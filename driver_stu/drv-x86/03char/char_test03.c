/**********************
 * 支持多个缓冲区的char驱动
 * 建议采用新的proc接口(seq_file接口)
 * author: zhang
 * date: 2014-08-12
 **********************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>

#define DEF_LEN 	100 /* 缓冲区的默认大小 */
#define DEF_MAJOR 	55  /* 默认主设备号 */
#define MEM_NUM		3

/* 定义驱动支持的ioctl号 */
#define MEM_TYPE	'B'
#define MEM_RESET 	_IO(MEM_TYPE, 1)
#define MEM_RESIZE 	_IOW(MEM_TYPE, 2, int)

static int sizes[] = {DEF_LEN, DEF_LEN*2, DEF_LEN*3};
module_param_array(sizes,int,NULL,0444);

struct mem_priv {
	char *start;
	int buf_len;
	int wp;
	dev_t dev_id;
	struct cdev mem_cdev;
};

static struct mem_priv *devs[MEM_NUM];

/* /proc文件的读函数 */
static int 
mem_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	int i;
	
	for (i=0; i<MEM_NUM; i++) {
		ret += sprintf(page+ret, "-----DEV %d:%d-----\n", MAJOR(devs[i]->dev_id), MINOR(devs[i]->dev_id));
		ret += sprintf(page+ret, "buf_len = %d bytes; from 0x%p\n", devs[i]->buf_len, devs[i]->start);
		ret += sprintf(page+ret, "wp = %d\n\n", devs[i]->wp);
	}

	return ret;
}

//open中的最主要工作就是找到和用户态打开文件对应的设备私有结构体
static int 
mem_open(struct inode *inode, struct file *filp)
{
	struct mem_priv *tmp = container_of(inode->i_cdev, struct mem_priv, mem_cdev);

	filp->private_data = tmp;

	return 0;
}


static int 
mem_release(struct inode *inode, struct file *filp)
{
	return 0;
}


static ssize_t 
mem_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	struct mem_priv *dev = filp->private_data;

	/* 当缓冲区被reset后，可能出现读指针在写指针之上的情况
	   将读指针恢复到0即可 */
	if (*f_pos > dev->wp)
		*f_pos = 0;

	if (count == 0 || filp->f_pos == dev->wp)
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
	struct mem_priv *dev = filp->private_data;

	if (count == 0 || dev->wp == dev->buf_len)
		return 0;

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
	struct mem_priv *dev = filp->private_data;
	char *tmp;

	switch (req) {
	case MEM_RESET:	/* reset buffer */
		dev->wp = 0;
		memset(dev->start, 0, dev->buf_len);
		break;
	case MEM_RESIZE: /* resize buffer */
		if (arg > 0x400000) {
			printk("Buffer too long\n");
			return -ENOMEM;
		}
		tmp = (char *)kzalloc(arg, GFP_KERNEL);
		if (tmp == NULL)
			return -ENOMEM;
		kfree(dev->start);
		dev->start = tmp;
		dev->buf_len = arg;
		dev->wp = 0;
		break;
	default: 	/* unrecognize number */
		printk("request number error 0x%x\n", req);
		return -EFAULT;
	}

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


/* 初始化多个缓冲区，并注册到VFS */
static int devs_init(void)
{
	int i, ret;
	struct mem_priv *dev;

	for (i=0; i<MEM_NUM; i++) {
		dev = (struct mem_priv *)kzalloc(sizeof(*dev), GFP_KERNEL);
		if (!dev) {
			ret = -ENOMEM;
			goto err_alloc;
		}

		dev->start = (char *)kzalloc(sizes[i], GFP_KERNEL);
		if (!dev->start) {
			ret = -ENOMEM;
			goto err_buf;
		}
		dev->buf_len = sizes[i];
		dev->wp = 0;

		/* init & add cdev */
		dev->dev_id = MKDEV(DEF_MAJOR, i);
		cdev_init(&dev->mem_cdev, &mem_fops);
		dev->mem_cdev.owner = THIS_MODULE;
		cdev_add(&dev->mem_cdev, dev->dev_id, 1);
		devs[i] = dev;
	}

	return 0;
err_buf:
	kfree(dev);
err_alloc:
	return ret;
}


/* 释放缓冲区，并从VFS中注销 */
static void devs_release(void)
{
	int i;
	for (i=0; i<MEM_NUM; i++) {
		if (devs[i]) {
			cdev_del(&devs[i]->mem_cdev);
			kfree(devs[i]->start);
			kfree(devs[i]);
		}
	}
}


static int __init my_init(void)
{
	int ret;

	/* init all devices */
	ret = devs_init();
	if (ret)
		goto err_alloc;

	/* create /proc/mem_test */
	create_proc_read_entry("mem_test", 0,
		NULL, mem_proc_read, NULL);

	return 0;
err_alloc:
	devs_release();
	return ret;
}

static void __exit my_exit(void)
{
	remove_proc_entry("mem_test", NULL);
	devs_release();
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

