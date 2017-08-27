/**************************
 * 获取或设置dm96x1网卡寄存器的值
 * 实现一个char驱动
 * 通过ioctl命令来设置或读取寄存器的值
 * 驱动用usb_driver封装，采用同步方式访问9621中的寄存器
 * Author: zht
 * Date: 2014-08-27
 **************************/
#include <linux/module.h>
#include <linux/slab.h> //kzalloc
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/usb.h>

/* dm9621定义的访问寄存器的usb请求号 */
#define DM_READ_REGS	0x00 //读一组寄存器
#define DM_WRITE_REG	0x03 //写一个寄存器

struct usb_one_reg {
	char offset;
	char value;
};

struct usb_all_regs {
	char offset;
	char size;
	char values[256];
};

//ioctl号
#define USB_TYPE	'U'
#define USB_R_REG	_IOW(USB_TYPE, 1, struct usb_one_reg)
#define USB_W_REG	_IOW(USB_TYPE, 2, struct usb_one_reg)
#define USB_R_REGS	_IOW(USB_TYPE, 3, struct usb_all_regs)

//usb设备结构体指针
struct usb_device *udev;


/*********************
 * 同步读取一组连续寄存器
 * 结果存入data中
 *********************/
static int 
read_regs(char off, char length, void *data)
{
	void *buf;
	int ret = -ENOMEM;

	buf = kzalloc(length, GFP_KERNEL);
	if (!buf)
		goto out;

	/* 向control类型的端点发送数据并等待发送完成
	 * pipe的含义：
 	 * bit[7]=0(Out); =1(In)
 	 * bit[14:8]=7位的设备地址(0~127)
 	 * bit[18:15]=4位的endpoint号(0~15)
 	 * bit[31:30]=2位的端点传输类型
 	 * 	00(ISO); 01(Int); 10(Ctrl); 11(Bulk)
 	 */
	ret = usb_control_msg(udev,
		usb_rcvctrlpipe(udev, 0),
		DM_READ_REGS,
		USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
		0, off, buf, length, 5000);

	if (ret == length) {
		memcpy(data, buf, length);
		ret = 0;
	} else if (ret >= 0) {
		ret = -EINVAL;
	}
	kfree(buf);
out:
	return ret;
}


/************************
 * 同步读取一个寄存器
 ************************/
static int 
read_one_reg(char reg, char *value)
{
	return read_regs(reg, 1, value);
}


/************************
 * 同步写一个寄存器
 * usb为control/interrupt/bulk类型的通讯都设计了同步传输函数
 * 一旦函数返回，数据已经写入DM9621的寄存器
 ************************/
static int 
write_one_reg(char reg, char value)
{
	return usb_control_msg(udev,
		usb_sndctrlpipe(udev, 0),
		DM_WRITE_REG,
		USB_DIR_OUT | USB_TYPE_VENDOR |USB_RECIP_DEVICE,
		value, reg, NULL, 0, 
		5000);
}


/**********************
 * file_operations
 **********************/
static long
usbreg_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	int ret = -EFAULT;
	void *tmp = (void *)arg;
	struct usb_one_reg buf1;
	struct usb_all_regs buf2;

	memset(&buf1, 0, sizeof(buf1));
	memset(&buf2, 0, sizeof(buf2));

	switch (req) {
	case USB_R_REG:
		if (copy_from_user(&buf1, tmp, sizeof(buf1)))
			goto err;
		if (read_one_reg(buf1.offset, &buf1.value))
			goto err;
		if (copy_to_user(tmp, &buf1, sizeof(buf1)))
			goto err;
		break;
	case USB_R_REGS:
		if (copy_from_user(&buf2, tmp, sizeof(buf2)))
			goto err;
		if (read_regs(buf2.offset, buf2.size, buf2.values))
			goto err;
		if (copy_to_user(tmp, &buf2, sizeof(buf2)))
			goto err;
		break; 
	case USB_W_REG:
		if (copy_from_user(&buf1, tmp, sizeof(buf1)))
			goto err;
		if (write_one_reg(buf1.offset, buf1.value))
			goto err;
		break;
	default:
		printk("Cannot support ioctl 0x%x\n", req);
	}

	return 0;
err:
	return ret;
}


static struct file_operations usb_fops = {
	.owner 		= THIS_MODULE,
	.unlocked_ioctl = usbreg_ioctl,
};

static struct miscdevice usb_miscdev = {
	.minor		= MISC_DYNAMIC_MINOR,
	.name		= "dm96", //dev下设备文件的名字
	.fops		= &usb_fops,
};


/*********************
 * usb_driver->probe
 *********************/
static int 
usb_reg_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	int ret;

	printk("=====Enter usb_reg_probe=====\n");

	//找到usb_device的指针
	udev = interface_to_usbdev(intf);

	//注册miscdevice
	ret = misc_register(&usb_miscdev);
	if (ret) {
		printk("Cannot register usbreg misc\n");
		return ret;
	}

	return 0;
}


/**************************
 * usb_driver->disconnect
 **************************/
static void usb_reg_disconnect(struct usb_interface *intf)
{
	printk("Enter usb_reg_disconnect\n");
	misc_deregister(&usb_miscdev);
}

static struct usb_device_id my_ids[] = {
	{
	 USB_DEVICE(0x0A46, 0x9601), //Davicom 9601
	},
	{
	 USB_DEVICE(0x0A46, 0x9621), //Davicom 9621
	},
	{ }
};

MODULE_DEVICE_TABLE(usb, my_ids);

static struct usb_driver usb_reg_drv = {
	.name		= "dm96x1-regs",
	.probe		= usb_reg_probe,
	.disconnect	= usb_reg_disconnect,
	.id_table	= my_ids,
};

static int __init my_init(void)
{
	return usb_register(&usb_reg_drv);
}

static void __exit my_exit(void)
{
	usb_deregister(&usb_reg_drv);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

