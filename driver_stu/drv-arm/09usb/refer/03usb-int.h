
/*************************
 * DM9621驱动对中断端点的处理
 *************************/
//usb驱动要保证中断端点的urb队列中一直有urb的存在。如果没有则不会保证该urb的带宽。所以，需要在urb的callback函数中重新submit刚刚完成的urb.


1.分配中断端点使用的urb
------------------------
struct urb *inturb;
inturb = usb_alloc_urb(0, GFP_KERNEL);


2.初始化urb
------------------------
(1)获取中断端点的pipe号以及最大包长度
struct usb_host_endpoint *int_in = xxx;
	epaddr = int_in->desc.bEndpointAddress & 0xF;
	pipe = usb_rcvintpipe(udev, epaddr);
	maxp = usb_maxpacket(udev, pipe, 0);

(2)设置轮循周期为5ms
int period = 5;

(3)分配中断端点的缓冲区
char *buf = kmalloc(maxp, GFP_KERNEL);

(4)初始化urb
usb_fill_int_urb(inturb, udev, pipe, buf, maxp, intr_complete, priv, period);


3.提交urb
-----------------------
可用的标志有GFP_KERNEL,GFP_NOIO,GFP_ATOMIC
GFP_ATOMIC: callback函数，中断上下文，持有锁等情况下使用
GFP_NOIO: IO可能阻塞时使用(比如在resume函数中)
GFP_KERNEL: 其他情况下使用

ret = usb_submit_urb(inturb, GFP_KERNEL);
usb_submit_urb(inturb, GFP_NOIO);


4.中断端点的回调函数
------------------------------
当回调函数调用时，要重新submit。如下：
static void 
intr_complete(struct urb *urb)
{
	struct dm9621_priv *dev = urb->context;
	...
	/* 重新提交INT端点的urb */
	memset(urb->transfer_buffer, 0, urb->transfer_buffer_length);
	status = usb_submit_urb(urb, GFP_ATOMIC);
}


5.停止urb(对应usb_submit_urb)
-------------------------
usb_kill_urb(inturb);


6.释放urb(对应usb_alloc_urb)
--------------------------
usb_free_urb(inturb);


