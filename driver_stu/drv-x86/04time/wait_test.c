/****************************
 * 等待队列的例子
 * 基于03char目录下的单缓冲区例子，应该考虑加锁保护
 * Author: zht
 * Date: 2014-08-15
 ****************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/wait.h> /* wait_queue_head_t */

#define DEF_LEN 	100
#define DEF_MAJOR 	70

#define MEM_TYPE 	'Z' 
#define MEM_RESET 	_IO(MEM_TYPE, 1)
#define MEM_RESIZE 	_IOW(MEM_TYPE, 2, int)

//描述缓冲区的私有结构体
struct mem_priv {
	char *start;
	int buf_len;
	int wp; //写偏移
	int open_cnt;
	dev_t dev_id;
	struct cdev mem_cdev;
	wait_queue_head_t writeq;
};

static struct mem_priv *dev;


static int 
mem_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;

	ret += sprintf(page+ret, "-----DEV %d:%d-----\n", MAJOR(dev->dev_id), MINOR(dev->dev_id));
	ret += sprintf(page+ret, "buf_len %dbytes; from 0x%p\n", dev->buf_len, dev->start);
	ret += sprintf(page+ret, "wp = %d; open_cnt = %d\n", dev->wp, dev->open_cnt);

	return ret;
}


static int 
mem_open(struct inode *inode, struct file *filp)
{
	dev->open_cnt++;
	return 0;
}


static int 
mem_release(struct inode *inode, struct file *filp)
{
	dev->open_cnt--;
	return 0;
}


static ssize_t 
mem_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	if (*f_pos > dev->wp)
		*f_pos = 0;

	if (count == 0 || *f_pos == dev->wp)
		return 0;

	count = min(count, (size_t)(dev->wp - *f_pos));

	/* copy to user(to, from, count) */
	if (copy_to_user(buf, (dev->start + *f_pos), count))
		return -EFAULT;

	*f_pos += count;
	return count;
}


static ssize_t 
mem_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	if (count == 0)
		return 0;

	//只有在缓冲区满时，才需要睡眠
	if (dev->wp == dev->buf_len) {
		wait_event(dev->writeq, (dev->wp < dev->buf_len));
		//if (wait_event_interruptible(dev->writeq, (dev->wp < dev->buf_len)))
		//	return -ERESTARTSYS;
	}

	count = min(count, (size_t)(dev->buf_len - dev->wp));

	/* copy from user (to, from, count) */
	if (copy_from_user((dev->start + dev->wp), buf, count))
		return -EFAULT;

	dev->wp += count;

	return count;
}


static long 
mem_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	char *tmp;

	if (_IOC_TYPE(req) != MEM_TYPE) {
		printk("Cannot recognize ioctl number 0x%x\n", req);
		return -EFAULT;
	}

	switch (_IOC_NR(req)) {
	case 1:	/* reset buffer */
		dev->wp = 0;
		memset(dev->start, 0, dev->buf_len);
		break;
	case 2:	/* resize buffer */
		if (arg > 0x400000) {
			printk("Buffer too long\n");
			return -ENOMEM;
		}
		tmp = (char *)kzalloc(arg, GFP_KERNEL);
		if (tmp == NULL)
			return -ENOMEM;
		dev->start = tmp;
		dev->buf_len = arg;
		dev->wp = 0;
		break;
	default: 	/* unrecognize number */
		printk("request number error\n");
		return -EFAULT;
	}

	/* wake up writeq */
	wake_up(&dev->writeq);
	//wake_up_interruptible(&dev->writeq);

	return 0;
}


static struct file_operations mem_fops = {
	.owner = THIS_MODULE, 
	.open = mem_open,
	.release = mem_release,
	.read = mem_read,
	.write = mem_write,
	.unlocked_ioctl = mem_ioctl,
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
	dev->wp = 0;
	dev->open_cnt = 0;

	/* init wait_queue_head */
	init_waitqueue_head(&dev->writeq);

	/* init & add cdev */
	dev->dev_id = MKDEV(DEF_MAJOR, 0);
	cdev_init(&dev->mem_cdev, &mem_fops);
	dev->mem_cdev.owner = THIS_MODULE;
	cdev_add(&dev->mem_cdev, dev->dev_id, 1);

	/* create /proc/wait_test */
	create_proc_read_entry("wait_test", 0, \
		NULL, mem_proc_read, NULL);

	return 0;
err_buf:
	kfree(dev);
err_alloc:
	remove_proc_entry("wait_test", NULL);
	return ret;
}

static void __exit my_exit(void)
{
	remove_proc_entry("wait_test", NULL);
	cdev_del(&dev->mem_cdev);
	kfree(dev->start);
	kfree(dev);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

