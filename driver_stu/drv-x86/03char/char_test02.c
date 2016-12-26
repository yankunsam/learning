/**********************
 * 基本的char驱动例子2
 * 本例内存缓冲区模拟为设备进行控制
 * 实现char驱动核心的file_operations
 * 支持多个缓冲区，在open函数中区分要操作的缓冲区
 * Author: zht
 * Date: 2015-04-17
 **********************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>

//define硬件信息，设备号等
//要找到别人没有用过的主设备号，可以参考/proc/devices，也可以让内核动态分配
#define DEF_SIZE	100
#define DEF_MAJOR	70
#define DEV_NUM		3

//定义ioctl号
#define BUF_TYPE	'B'
#define BUF_RESET	_IO(BUF_TYPE, 1)
#define BUF_RESIZE	_IOW(BUF_TYPE, 2, int)

struct mem_priv {
	char *start;
	int buf_size;
	int wp;
	dev_t dev_id; //设备号
	struct cdev mem_cdev; //用于注册
};

//全局的设备数组指针
static struct mem_priv *devs[DEV_NUM];

//可以通过模块的参数来指定缓冲区的大小
static int sizes[] = {DEF_BUF, DEF_ BUF, DEF_BUF};
module_param_array(sizes,int,NULL,0644);

//proc文件的读函数
static int
my_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	//显示3个缓冲区的当前使用状态
}


//准备char驱动的函数
static int 
mem_open(struct inode *inode, struct file *filp)
{
	//要根据用户态打开的设备文件，找到对应的私有结构体
	//可以利用inode->i_rdev或i_cdev找到私有结构体，推荐用i_cdev
	//一旦找到对应的私有结构体，则存入file
	struct mem_priv *tmp = ...;
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
	//从filp->private_data中找到私有结构体
	struct mem_priv *dev = filp->private_data;

	//判断缓冲区有多少数据可读
	size_t cnt = min(count, (size_t)(dev->wp - *f_pos));
	if (0 == cnt)
		return 0;
	//copy_to_user(to,from,cnt)
	if (copy_to_user(buf, (dev->start+*f_pos), cnt))
		return -EFAULT;
	//更新f_pos
	*f_pos += cnt;
	return cnt;
}

static ssize_t
mem_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct mem_priv *dev = filp->private_data;
	//判断缓冲区还有多少空间
	size_t cnt = min(count, (size_t)(dev->buf_size - dev->wp));
	if (0 == cnt)
		return 0;
	//copy_from_user(to,from,cnt)
	if (copy_from_user(dev->start+dev->wp, buf, cnt))
		return -EFAULT;
	//更新wp
	dev->wp += cnt;
	return cnt;
}

static long
mem_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	struct mem_priv *dev = filp->private_data;
	char *tmp;

	if (req == BUF_RESET) {
		memset(dev->start, 0, dev->buf_size);
		dev->wp = 0;
	}
	else if (req == BUF_RESIZE) {
		tmp = (char *)kzalloc(arg, GFP_KERNEL);
		if (!tmp)
			return -ENOMEM;
		dev->wp = 0;
		dev->buf_size = arg;
		kfree(dev->start);
		dev->start = tmp;
	}
	else {
		printk("Cannot support ioctl 0x%x\n", req);
		return -1;
	}

	return 0;
}

//准备file_operations
static struct file_operations mem_fops = {
	.owner = THIS_MODULE,
	.open = mem_open,
	.release = mem_release,
	.read = mem_read,
	.write = mem_write,
	.unlocked_ioctl = mem_ioctl
};

static int __init my_init(void)
{
	//以下步骤1，2，3，4是针对一个设备的，需要执行3次
	//3个设备可以用一个proc文件显示信息，因此步骤5需要执行1次

	//1.分配私有结构体
	dev = (struct mem_priv *)kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	//2.分配并初始化缓冲区
	dev->buf_size = sizes[i];
	dev->wp = 0;
	dev->start = (char *)kzalloc(dev->buf_size, GFP_KERNEL);
	if (!dev->start) {
		kfree(dev);
		return -ENOMEM;
	}

	//3.为设备分配设备号(66, 10)
	dev->dev_id = MKDEV(DEF_MAJOR, i);

	//4.将设备号和file_operations集成在cdev结构体中，注册到VFS
	cdev_init(&dev->mem_cdev, &mem_fops);
	dev->mem_cdev.owner = THIS_MODULE;
	cdev_add(&dev->mem_cdev, dev->dev_id, 1);

	//5.创建proc文件，显示设备的使用情况
	return 0;
}

static void __exit my_exit(void)
{
	//exit的内容一般和init正相反
	//如果有proc文件，则remove，一次即可
	//以下步骤支持3次
	cdev_del(&dev->mem_cdev);
	kfree(dev->start);
	kfree(dev);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

