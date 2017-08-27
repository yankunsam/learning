/****************************
 * PIPE或FIFO的例子
 * 用缓冲区来模拟PIPE，增加读写指针
 * Author: zht
 * Date: 2014-08-15
 ****************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/wait.h> //wait_queue_head_t
#include <linux/mutex.h> //mutex
#include <asm/atomic.h> //atomic_t

#define DEF_LEN 	100
#define DEF_MAJOR 	75

//描述缓冲区的私有结构体
struct mem_priv {
	char *start, *end;
	char *wp, *rp;
	int buf_len;
	atomic_t open_cnt;
	dev_t dev_id;
	struct cdev mem_cdev;
	wait_queue_head_t writeq, readq;
	struct mutex mem_lock;
};

static struct mem_priv *dev;


static int 
mem_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;

	ret += sprintf(page+ret, "-----DEV %d:%d-----\n", MAJOR(dev->dev_id), MINOR(dev->dev_id));
	ret += sprintf(page+ret, "buf_len %dbytes; from 0x%p to 0x%p\n", dev->buf_len, dev->start, dev->end);
	ret += sprintf(page+ret, "wp in 0x%p; rp in 0x %p; open_cnt = %d\n", dev->wp, dev->rp, atomic_read(&dev->open_cnt));

	return ret;
}


static int 
mem_open(struct inode *inode, struct file *filp)
{
	atomic_inc(&dev->open_cnt);
	return 0;
}


static int 
mem_release(struct inode *inode, struct file *filp)
{
	atomic_dec(&dev->open_cnt);
	return 0;
}


static ssize_t 
mem_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	//1.获得锁 mutex_lock & mutex_lock_inter..;	
	//2.判断缓冲区是否为空(while)
	//3.如果为空，则首先释放锁
	//4.wait_event & wait_event_interruptible
	//5.如果等待到缓冲区有数据，则首先重新获得锁
	//6.获得锁后，再次检测缓冲区是否有数据
	//如果确保缓冲区非空且持有锁：
	//7.计算可以向用户态拷贝多少数据
	//	size_t cnt = min(...);
	//8.copy_to_user();
	//9.更新rp指针，如果rp==end，则rp=start;
	//10.如果不再访问缓冲区，则解锁mutex_unlock
	//11.唤醒因为缓冲区满而睡眠的进程
	//	wake_up(&dev->writeq);
	//return cnt;
}


static ssize_t 
mem_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{	
	//1.获得锁 mutex_lock & mutex_lock_inter..;	
	//2.判断缓冲区是否为满(while)
	//3.如果为满，则首先释放锁
	//4.wait_event & wait_event_interruptible
	//5.如果等待到缓冲区非满，则首先重新获得锁
	//6.获得锁后，再次检测缓冲区是否非满
	//如果确保缓冲区非满且持有锁：
	//7.计算可以从用户态拷贝的数据
	//	size_t cnt = min(...);
	//8.copy_from_user();
	//9.更新wp指针，如果wp==end，则wp=start;
	//10.如果不再访问缓冲区，则解锁mutex_unlock
	//11.唤醒因为缓冲区空而睡眠的进程
	//	wake_up(&dev->readq);
	//return cnt;
}


static struct file_operations mem_fops = {
	.owner = THIS_MODULE, 
	.open = mem_open,
	.release = mem_release,
	.read = mem_read,
	.write = mem_write,
};


static int __init my_init(void)
{
	int ret;

		//分配并初始化私有结构体
	dev = (struct mem_priv *)kzalloc(sizeof(*dev), GFP_KERNEL);
	if (NULL == dev) {
		ret = -ENOMEM;
		goto err_alloc;
	}

	dev->start = (char *)kzalloc(DEF_LEN, GFP_KERNEL);
	if (NULL == dev->start) {
		ret = -ENOMEM;
		goto err_buf;
	}
	dev->buf_len = DEF_LEN;
	dev->end = dev->start + dev->buf_len;
	dev->wp = dev->start;
	dev->rp = dev->start;
	atomic_set(&dev->open_cnt, 0);

	/* init wait_queue_head */
	init_waitqueue_head(&dev->writeq);
	init_waitqueue_head(&dev->readq);

	//init mutex
	mutex_init(&dev->mem_lock);

	/* init & add cdev */
	dev->dev_id = MKDEV(DEF_MAJOR, 0);
	cdev_init(&dev->mem_cdev, &mem_fops);
	dev->mem_cdev.owner = THIS_MODULE;
	cdev_add(&dev->mem_cdev, dev->dev_id, 1);

	/* create /proc/mutex_test */
	create_proc_read_entry("mutex_test", 0, \
		NULL, mem_proc_read, NULL);

	return 0;
err_buf:
	kfree(dev);
err_alloc:
	remove_proc_entry("mutex_test", NULL);
	return ret;
}

static void __exit my_exit(void)
{
	remove_proc_entry("mutex_test", NULL);
	cdev_del(&dev->mem_cdev);
	kfree(dev->start);
	kfree(dev);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

