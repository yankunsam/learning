/***************************
 * 完整的块设备驱动，基于内存缓冲区
 * 用缓冲区来模拟磁盘，需要较大的空间，默认64MB
 * 支持linux 2.6.32(Redhat 6)
 * 支持linux 3.5(Android)
 * Author: zht
 * Date: 2014-08-28
 ***************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/vmalloc.h>  /* vmalloc/vfree */
#include <linux/genhd.h>    /* gendisk */
#include <linux/blkdev.h>   /* request */
#include <linux/hdreg.h>

/* 支持的分区数量以及扇区大小 */
#define DEV_MINORS	16
#define SECTOR_SIZE	512

/* 块设备的主设备号
 * 可以自己指定，也可以由内核分配 */
static int ram_major = 0;
module_param(ram_major, int, 0444);

/* 硬件扇区大小 */
static int hardsect_shift = 9;
module_param(hardsect_shift, int, 0);

/* 磁盘大小(默认64MB) */
static int nsectors = 131072; //1<<17
module_param(nsectors, int, 0);


/* 私有结构体，和每个磁盘对应 */
struct ramdisk_priv {
	int size;  /* 磁盘大小(字节数) */
	char *data; /* 磁盘对应的缓冲区 */
	short users;
	spinlock_t lock; /* 在访问request_queue之前获得 */
	struct request_queue *queue;    /* 请求队列 */
	struct gendisk *gd;  /* 对应一个磁盘 */
};

static struct ramdisk_priv *dev;


/************************
 * 处理request中的一个bio_vec
 ************************/
static int 
do_one_biovec(struct ramdisk_priv *priv, struct request *req)
{
	unsigned long offset, nbytes;
	char *buf;

	//offset为访问位置(字节)
	//nbytes为bio当前bio_vec的长度
	offset = blk_rq_pos(req) << 9;
	nbytes = blk_rq_cur_bytes(req);
	buf = req->buffer;

	if (req->cmd_type != REQ_TYPE_FS)
		return -EIO;

	if (blk_rq_pos(req) + blk_rq_cur_sectors(req) >
	    get_capacity(req->rq_disk)) {
		printk("Beyond device end (%ld+%ld)\n", offset, nbytes);
		return -EIO;
	}

	switch(rq_data_dir(req)) {
	case READ:
		printk("R %ldB\n", nbytes);
		memcpy(buf, priv->data + offset, nbytes);
		return 0;
	case WRITE:
		printk("W %ldB\n", nbytes);
		memcpy(priv->data + offset, buf, nbytes);
		return 0;
	default:
		printk(KERN_NOTICE "Unknown request %u\n", rq_data_dir(req));
		return -EIO;
	}
}


/***********************
 * 用于处理请求的函数
 * 在blk_init_queue初始化请求队列时传入
 * 作为整个队列中所有请求的处理函数
 ***********************/
static void 
ram_request(struct request_queue *rq)
{
	struct ramdisk_priv *priv = rq->queuedata;
	struct request *req = NULL;
	int res;

	/* 如果找不到设备私有结构体且rq队列不为空，则结束队列中所有的请求 */
	if (!priv) {
		while ((req = blk_fetch_request(rq)) != NULL)
			__blk_end_request_all(req, -ENODEV);
		return;
	} 

	//遍历处理请求队列中的请求
	req = blk_fetch_request(rq);
	while (req != NULL) {
		//处理request中bio的一个iovec
		//返回0说明request中的所有buffer处理完毕，从队列中取下一个request
		res = do_one_biovec(priv, req);

		if (!__blk_end_request_cur(req, res))
			req = blk_fetch_request(rq);
	}
}


/***********************
 * block_device_operations->open
 ***********************/
static int 
ram_open(struct block_device *bdev, fmode_t mode)
{
	struct ramdisk_priv *priv = bdev->bd_disk->private_data;

	spin_lock(&priv->lock);
	priv->users++;
	printk("RAMDISK: open %d times, in %ld\n", priv->users, jiffies);
	spin_unlock(&priv->lock);

	return 0;
}


/***********************
 * block_device_operations->release
 ***********************/
static int 
ram_release(struct gendisk *gd, fmode_t mode)
{
	struct ramdisk_priv *priv = gd->private_data;

	printk("RAMDISK: release in %ld\n", jiffies);
	spin_lock(&priv->lock);
	priv->users--;
	spin_unlock(&priv->lock);

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
	geo->sectors = 16; //16sectors/track
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


static int __init my_init(void)
{
	int ret;
	
	//1.自己选或要求内核来分配主设备号
	ret = register_blkdev(ram_major, "ram_test");
	if (ret < 0) {
		printk("Request major %d error\n", ram_major);
		return -EBUSY;
	}
	if (ram_major == 0)
		ram_major = ret;

	//2.分配私有结构体
	dev = kzalloc(sizeof(struct ramdisk_priv), GFP_KERNEL);
	if (!dev) {
		ret = -ENOMEM;
		goto err1;
	}


	//3.分配缓冲区，由于超过4MB，要使用vmalloc
	dev->size = nsectors << hardsect_shift;
	dev->data = vmalloc(dev->size);
	if (!dev->data) {
		printk ("vmalloc failure.\n");
		ret = -ENOMEM;
		goto err2;
	}

	//4.初始化锁，用于保护对请求队列的访问
	spin_lock_init(&dev->lock);
	
	//5.分配并初始化请求队列
	//将私有结构体放入request_queue->queuedata中
	dev->queue = blk_init_queue(ram_request, &dev->lock);
	if (dev->queue == NULL) {
		ret = -ENOMEM;
		goto err3;
	}
	dev->queue->queuedata = dev;

	//6.分配gendisk(每个gendisk对应一个磁盘)
	dev->gd = alloc_disk(DEV_MINORS);
	if (!dev->gd) {
		ret = -ENOMEM;
		goto err3;
	}

	//7.初始化gendisk
	dev->gd->major = ram_major;
	dev->gd->first_minor = 30;
	dev->gd->fops = &ram_ops;
	dev->gd->queue = dev->queue;
	dev->gd->private_data = dev;
	snprintf(dev->gd->disk_name, 32, "abc");
	set_capacity(dev->gd, (dev->size/SECTOR_SIZE));

	//8.将gendisk注册到块子系统
	add_disk(dev->gd);

	return 0;
err3:
	vfree(dev->data);
err2:
	kfree(dev);
err1:
	unregister_blkdev(ram_major, "ram_test");
	return ret;
}


static void __exit my_exit(void)
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
	
module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

