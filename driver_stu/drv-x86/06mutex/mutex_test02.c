/***********************
 * 实现一个PIPE的例子
 * 在内核创建一个缓冲区，模拟PIPE的行为
 * 用户态echo>设备文件可以向缓冲区写入数据
 * 如果cat设备文件，则将数据读出(只能读出一次)
 * Author: zht
 * Date: 2014-11-20
 ************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <asm/atomic.h>

#define PIPE_MAJOR	75
#define BUF_SIZE	100

struct pipe_priv {
	char *start, *end;
	char *wp, *rp;
	int buf_size;
	atomic_t open_cnt;
	wait_queue_head_t readq, writeq;
	struct mutex pipe_lock;
	dev_t dev_id;
	struct cdev pipe_cdev;
};

static struct pipe_priv *dev;


/* proc文件的读函数 */
static int 
my_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{	
	int ret = 0;

	ret += sprintf(page+ret, "---PIPE %d:%d---\n", MAJOR(dev->dev_id), MINOR(dev->dev_id));
	ret += sprintf(page+ret, "Size %d bytes: from 0x%p to 0x%p\n", dev->buf_size, dev->start, dev->end);
	ret += sprintf(page+ret, "Open %d times: rp = 0x%p; wp = 0x%p\n", atomic_read(&dev->open_cnt), dev->rp, dev->wp);

	return ret;
}

static int 
pipe_open(struct inode *inode, struct file *filp)
{
	atomic_inc(&dev->open_cnt);
	return 0;
}

static int 
pipe_release(struct inode *inode, struct file *filp)
{
	atomic_dec(&dev->open_cnt);
	return 0;
}

static ssize_t 
pipe_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	int ret;
	size_t cnt;

	//获得锁
	ret = mutex_lock_interruptible(&dev->pipe_lock);
	if (ret)
		return -ERESTARTSYS;

	//判断缓冲区是否为空
	while (dev->rp == dev->wp) {
		mutex_unlock(&dev->pipe_lock);
		ret = wait_event_interruptible(dev->readq, dev->rp != dev->wp);
		if (ret)
			return -ERESTARTSYS;
		if (mutex_lock_interruptible(&dev->pipe_lock))
			return -ERESTARTSYS;
	}

	//此时持有锁且缓冲区非空
	if (dev->wp > dev->rp) 
		cnt = min(count, (size_t)(dev->wp - dev->rp));
	else 
		cnt = min(count, (size_t)(dev->end - dev->rp));	

	if (copy_to_user(buf, dev->rp, cnt)) {
		mutex_unlock(&dev->pipe_lock);
		return -EFAULT;
	}

	//更新rp
	dev->rp += cnt;
	if (dev->rp == dev->end)
		dev->rp = dev->start;

	mutex_unlock(&dev->pipe_lock);
	wake_up(&dev->writeq);

	return cnt;
}

/* 返回缓冲区可写的字节数
 * 如缓冲区满则返回0，缓冲区空返回99 */
int space_free(struct pipe_priv *tmp)
{
	if (tmp->rp > tmp->wp)
		return (tmp->rp - tmp->wp - 1);
	else 
		return (tmp->buf_size+tmp->rp-tmp->wp-1);
}


static ssize_t 
pipe_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	size_t cnt;
	if (0 == count)
		return 0;

	//加锁
	if (mutex_lock_interruptible(&dev->pipe_lock))
		return -ERESTARTSYS;

	//判断缓冲区是否为满
	while(!space_free(dev)) {
		mutex_unlock(&dev->pipe_lock);
		if (wait_event_interruptible(dev->writeq, space_free(dev)))
			return -ERESTARTSYS;
		if (mutex_lock_interruptible(&dev->pipe_lock))
			return -ERESTARTSYS;
	}

	//此时，持有锁且缓冲区非满
	cnt = min(count, (size_t)space_free(dev));
	if (dev->wp >= dev->rp)
		cnt = min(cnt, (size_t)(dev->end - dev->wp));

	if (copy_from_user(dev->wp, buf, cnt)) {
		mutex_unlock(&dev->pipe_lock);
		return -EFAULT;
	}

	//更新wp指针
	dev->wp += cnt;
	if (dev->wp == dev->end)
		dev->wp = dev->start;

	mutex_unlock(&dev->pipe_lock);
	wake_up_interruptible(&dev->readq);
	//wake_up(&dev->readq);

	return cnt;
}

static struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.open = pipe_open,
	.release = pipe_release,
	.read = pipe_read,
	.write = pipe_write,
};


static int __init my_init(void)
{
	dev = (struct pipe_priv *)kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	dev->buf_size = BUF_SIZE;
	dev->start = (char *)kzalloc(dev->buf_size, GFP_KERNEL);
	if (!dev->start) {
		kfree(dev);
		return -ENOMEM;
	}
	dev->end = dev->start + dev->buf_size;
	dev->wp = dev->start;
	dev->rp = dev->start;

	init_waitqueue_head(&dev->readq);
	init_waitqueue_head(&dev->writeq);
	mutex_init(&dev->pipe_lock);
	atomic_set(&dev->open_cnt, 0);

	create_proc_read_entry("proc_pipe", 0444, \
		NULL, my_proc_read, NULL);

	dev->dev_id = MKDEV(PIPE_MAJOR, 0);
	cdev_init(&dev->pipe_cdev, &my_fops);
	dev->pipe_cdev.owner = THIS_MODULE;
	cdev_add(&dev->pipe_cdev, dev->dev_id, 1);

	return 0;
}

static void __exit my_exit(void)
{
	cdev_del(&dev->pipe_cdev);
	remove_proc_entry("proc_pipe", NULL);
	kfree(dev->start);
	kfree(dev);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

