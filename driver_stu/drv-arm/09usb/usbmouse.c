/***********************
 * usb鼠标驱动
 * 将鼠标识别为input设备并注册
 * Author: zht
 * Date: 2014-01-13
 ***********************/
#include <linux/module.h>
#include <linux/input.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

//鼠标返回的信息应该占4字节，最大8字节
#define MOUSE_DATA	8 


//私有结构体
struct usb_mouse {
	char name[128];
	char phys[64];
	struct usb_device *usbdev;
	struct input_dev *dev;
	struct urb *irq;
	char *data;
};


/**********************
 * 中断urb的回调函数
 **********************/
static void usb_mouse_irq(struct urb *urb)
{
	struct usb_mouse *mouse = urb->context;
	char *data = mouse->data;
	struct input_dev *dev = mouse->dev;
	int status;

	printk("mouse click\n");

	switch (urb->status) {
	case 0:			/* success */
		break;
	case -ECONNRESET:	/* unlink */
	case -ENOENT:
	case -ESHUTDOWN:
		return;
	/* -EPIPE: 重新提交 */
	default:
		goto resubmit;
	}

	input_report_key(dev, BTN_LEFT,   data[0] & 0x01);
	input_report_key(dev, BTN_RIGHT,  data[0] & 0x02);
	input_report_key(dev, BTN_MIDDLE, data[0] & 0x04);
	input_report_key(dev, BTN_SIDE,   data[0] & 0x08);
	input_report_key(dev, BTN_EXTRA,  data[0] & 0x10);

	input_report_rel(dev, REL_X,     data[1]);
	input_report_rel(dev, REL_Y,     data[2]);
	input_report_rel(dev, REL_WHEEL, data[3]);

	input_sync(dev);
resubmit:
	status = usb_submit_urb(urb, GFP_ATOMIC);
	if (status)
		printk("can't resubmit intr, status %d\n", status);
}


/**********************
 * input_dev->open
 * 当打开/dev/input/eventx设备时，才开始轮循usb鼠标
 **********************/
static int usb_mouse_open(struct input_dev *dev)
{
	struct usb_mouse *mouse = input_get_drvdata(dev);

	//向usb子系统提交urb
	if (usb_submit_urb(mouse->irq, GFP_KERNEL))
		return -EIO;

	return 0;
}


/********************
 * input_dev->close
 ********************/
static void usb_mouse_close(struct input_dev *dev)
{
	struct usb_mouse *mouse = input_get_drvdata(dev);

	//取消已经提交的urb
	usb_kill_urb(mouse->irq);
}


/*********************
 * usb_driver->probe
 *********************/
static int 
usb_mouse_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	struct usb_device *dev = interface_to_usbdev(intf);
	struct usb_host_interface *interface;
	struct usb_endpoint_descriptor *endpoint;
	struct usb_mouse *mouse;
	struct input_dev *input_dev;
	int pipe, maxp;
	int error = -ENOMEM;

	printk("=====Enter usbmouse probe====\n");
	interface = intf->cur_altsetting;

	if (interface->desc.bNumEndpoints != 1)
		return -ENODEV;

	endpoint = &interface->endpoint[0].desc;
	if (!usb_endpoint_is_int_in(endpoint))
		return -ENODEV;

	pipe = usb_rcvintpipe(dev, endpoint->bEndpointAddress);
	maxp = usb_maxpacket(dev, pipe, usb_pipeout(pipe));

	//分配私有结构体和input_dev
	mouse = kzalloc(sizeof(struct usb_mouse), GFP_KERNEL);
	input_dev = input_allocate_device();
	if (!mouse || !input_dev)
		goto fail1;

	//分配中断urb及其缓冲区
	mouse->data = kmalloc(8, GFP_ATOMIC);
	if (!mouse->data)
		goto fail1;

	mouse->irq = usb_alloc_urb(0, GFP_KERNEL);
	if (!mouse->irq)
		goto fail2;

	mouse->usbdev = dev;
	mouse->dev = input_dev;

	//生成鼠标设备的名字
	strcpy(mouse->name, "zht mouse name");
	strcpy(mouse->phys, "zht mouse path");
	input_dev->name = mouse->name;
	input_dev->phys = mouse->phys;

	input_dev->id.bustype = BUS_USB;
	input_dev->id.vendor  = 0xdead;
	input_dev->id.product = 0xbeef;
	input_dev->id.version = 0x1;

	input_dev->dev.parent = &intf->dev;

	set_bit(EV_KEY, input_dev->evbit);
	set_bit(EV_REL, input_dev->evbit);
	set_bit(EV_SYN, input_dev->evbit);

	set_bit(BTN_LEFT, input_dev->keybit);
	set_bit(BTN_RIGHT, input_dev->keybit);
	set_bit(BTN_MIDDLE, input_dev->keybit);
	set_bit(BTN_SIDE, input_dev->keybit);
	set_bit(BTN_EXTRA, input_dev->keybit);

	set_bit(REL_X, input_dev->relbit);
	set_bit(REL_Y, input_dev->relbit);
	set_bit(REL_WHEEL, input_dev->relbit);

	//将私有结构体存入input_dev中
	input_set_drvdata(input_dev, mouse);

	input_dev->open = usb_mouse_open;
	input_dev->close = usb_mouse_close;

	//初始化中断断点
	usb_fill_int_urb(mouse->irq, dev, pipe, mouse->data,
			 (maxp > 8 ? 8 : maxp),
			 usb_mouse_irq, mouse, endpoint->bInterval);

	//注册input_dev
	error = input_register_device(mouse->dev);
	if (error)
		goto fail3;

	//将私有结构体存入usb_interface
	usb_set_intfdata(intf, mouse);
	return 0;
fail3:	
	usb_free_urb(mouse->irq);
fail2:	
	kfree(mouse->data);
fail1:	
	input_free_device(input_dev);
	kfree(mouse);
	return error;
}


/**************************
 * usb_driver->disconnect
 **************************/
static void usb_mouse_disconnect(struct usb_interface *intf)
{
	struct usb_mouse *mouse = usb_get_intfdata(intf);

	printk("=====Enter usbmouse disconnect=====\n");
	usb_set_intfdata(intf, NULL);

	if (mouse) {
		usb_kill_urb(mouse->irq);
		input_unregister_device(mouse->dev);
		usb_free_urb(mouse->irq);
		kfree(mouse->data);
		kfree(mouse);
	}
}

static struct usb_device_id usb_mouse_id_table[] = {
	{
	 USB_DEVICE(0x0461, 0x4d81), //my mouse
	},
	{ }
};

MODULE_DEVICE_TABLE(usb, usb_mouse_id_table);

static struct usb_driver usb_mouse_drv = {
	.name		= "my-usbmouse",
	.probe		= usb_mouse_probe,
	.disconnect	= usb_mouse_disconnect,
	.id_table	= usb_mouse_id_table,
};

static int __init my_init(void)
{
	return usb_register(&usb_mouse_drv);
}

static void __exit my_exit(void)
{
	usb_deregister(&usb_mouse_drv);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

