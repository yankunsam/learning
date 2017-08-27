/***************************
 * 完整的块设备驱动，基于内存缓冲区
 * 支持linux 2.6.28内核
 * Author: zhanght
 * Date: 2012-09-05
 ***************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/vmalloc.h> /* vmalloc/vfree */
#include <linux/genhd.h>	/* gendisk */
#include <linux/blkdev.h>
#include <linux/hdreg.h>

/* 支持的分区数量以及扇区大小 */
#define DEV_MINORS	16
#define SECTOR_SIZE	512

/* 块设备的主设备号，可以自己指定，也可以由内核分配 */
static int ram_major = 0;
module_param(ram_major, int, 0);

/* 扇区大小对应的移位值(默认512字节) */
static int hardsect_shift = 9;
module_param(hardsect_shift, int, 0);

/* 磁盘包含的扇区数量(默认大小16MB) */
static int nsectors = 32768;
module_param(nsectors, int, 0);


/* 私有结构体，和每个磁盘对应 */
struct ram_dev {
	int size; /* 磁盘大小(字节数) */
	char *data; /* 磁盘对应的缓冲区起始地址 */
	short users;
	spinlock_t lock; /* 在访问request_queue之前获得 */
	struct request_queue *queue;    /* 请求队列 */
	struct gendisk *gd;  /* 对应一个磁盘 */
};

static struct ram_dev *dev;


/*************************
 * Handle one I/O request
 *************************/
static int 
ram_transfer(struct ram_dev *dev, unsigned long sector,	
	     unsigned long nsect, char *buffer, int write)
{
	unsigned long offset = sector * SECTOR_SIZE;
	unsigned long nbytes = nsect * SECTOR_SIZE;

	if ((offset + nbytes) > dev->size) {
		printk("Beyond-device end (%ld %ld)\n", offset, nbytes);
		return -EIO;
	}

	if (write)
		memcpy(dev->data + offset, buffer, nbytes);
	else
		memcpy(buffer, dev->data + offset, nbytes);

	return 0;
}


/***********************
 * 用于处理请求的函数
 * 在blk_init_queue初始化请求队列时传入
 * 作为整个队列中所有请求的处理函数
 ***********************/
static void 
ram_request(struct request_queue *q)
{
	struct request *req;
	struct ram_dev *dev;

	/* 从队列中依次取出要处理的request */
	while ((req = elv_next_request(q))!= NULL) {
		dev = (struct ram_dev *)req->rq_disk->private_data;
		if (!blk_fs_request(req)) {
			printk("Skip non-fs request\n");
			end_request(req, 0);
			continue;
		}
       		printk("Req: %s sector %ld, nr %d\n", 
			((long)rq_data_dir(req) ? "w":"r"), 
			(long)req->sector, 
			(int)req->current_nr_sectors);
	
		ram_transfer(dev, req->sector, req->current_nr_sectors, req->buffer, rq_data_dir(req));
		end_request(req, 1);
	}
}


/***********************
 * block_device_operations->open
 ***********************/
static int 
ram_open(struct block_device *bdev, fmode_t mode)
{
	struct ram_dev *dev = bdev->bd_disk->private_data;

	printk("RAMDISK: open in %ld\n", jiffies);
	spin_lock(&dev->lock);
	dev->users++;
	spin_unlock(&dev->lock);

	return 0;
}


/***********************
 * block_device_operations->release
 ***********************/
static int 
ram_release(struct gendisk *gd, fmode_t mode)
{
	struct ram_dev *dev = gd->private_data;

	printk("RAMDISK: release in %ld\n", jiffies);
	spin_lock(&dev->lock);
	dev->users--;
	spin_unlock(&dev->lock);

	return 0;
}


/*********************
 * block_device_operations->getgeo
 * 获取磁盘的结构信息
 *********************/
static int 
ram_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
	struct ramdisk_priv *priv = bdev->bd_disk->private_data;

	printk("Ramdisk: getgeo\n");
	geo->heads = 4;
	geo->sectors = 16;
	geo->cylinders = (priv->size/SECTOR_SIZE) >> 6;

	return 0;
}

/*************************
 * 块设备的操作函数集
 * 用户态访问/dev下块设备文件时调用
 *************************/
static struct block_device_operations ram_ops = {
	.owner	 = THIS_MODULE,
	.open	 = ram_open,
	.release = ram_release,
	.getgeo  = ram_getgeo,
};


/*************************
 * 初始化私有结构体，并分配对应的缓冲区
 * 分配并初始化gendisk和对应的request_queue
 * 注册gendisk
 *************************/
static int 
setup_device(void)
{
	/* 1.分配16MB缓冲区，由于超过4MB，所以不能再使用kmalloc，只能用vmalloc。但vmalloc只能保证虚拟连续，物理一般是不连续的 */
	dev->size = nsectors << hardsect_shift;
	dev->data = vmalloc(dev->size);
	if (dev->data == NULL) {
		printk ("vmalloc failure.\n");
		return -ENOMEM;
	}

	/* 初始化锁，用于保护对请求队列的访问 */
	spin_lock_init(&dev->lock);
	
	/* 分配并初始化请求队列
	 * 将私有结构体放入block_queue->queuedata中 */
	dev->queue = blk_init_queue(ram_request, &dev->lock);
	if (dev->queue == NULL)
		goto out_vfree;
	dev->queue->queuedata = dev;

	/* 分配并初始化gendisk
	 * 每个gendisk对应一个磁盘 */
	dev->gd = alloc_disk(DEV_MINORS);
	if (!dev->gd) {
		printk("alloc_disk failure\n");
		goto out_vfree;
	}

	/* 初始化gendisk */
	dev->gd->major = ram_major;
	dev->gd->first_minor = 0;
	dev->gd->fops = &ram_ops;
	dev->gd->queue = dev->queue;
	dev->gd->private_data = dev;
	snprintf(dev->gd->disk_name, 32, "shrek");
	set_capacity(dev->gd, (dev->size / SECTOR_SIZE));

	/* 将gendisk注册到块子系统 */
	add_disk(dev->gd);

	return 0;
out_vfree:
	if (dev->data)
		vfree(dev->data);
	return -1;
}


static int __init ram_init(void)
{
	int ret;
	
	/* 自己选或要求内核来分配主设备号 */
	ret = register_blkdev(ram_major, "ram_test");
	if (ret < 0) {
		printk("Request major %d error\n", ram_major);
		return -EBUSY;
	}
	if (ram_major == 0)
		ram_major = ret;




	/* 分配私有结构体 */
	dev = kzalloc(sizeof(struct ram_dev), GFP_KERNEL);
	if (dev == NULL) {
		ret = -ENOMEM;
		goto err1;
	}

	//初始化私有结构体，分配并注册gendisk
	ret = setup_device();
	if (ret) 
		goto err2;

    return 0;
err2:
	kfree(dev);
err1:
	unregister_blkdev(ram_major, "ram_test");
	return ret;
}


static void __exit ram_exit(void)
{
	blk_cleanup_queue(dev->queue);

	/* del_gendisk对应add_disk
	 * put_disk对应alloc_disk */
	if (dev->gd) {
		del_gendisk(dev->gd);
		put_disk(dev->gd);
	}

	if (dev->data)
		vfree(dev->data);

	unregister_blkdev(ram_major, "ram_test");
	kfree(dev);
}
	
module_init(ram_init);
module_exit(ram_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

