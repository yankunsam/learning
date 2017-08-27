/*****************************
 * DM9621网卡的驱动
 * 用于android 4.2对应的linux-3.5内核
 * author: zht
 * date: 2013-12-19
 *****************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/ethtool.h>
#include <linux/mii.h>
#include <linux/crc32.h>
#include <linux/usb.h>
#include "dm9621.h"

#define DRIVER_NAME	"DM9621"
#define DRIVER_VERSION "2013-12-19"

static const char *kevent_msg[] = {
	"TX halt",
	"RX halt",
	"RX nomem",
	"LINK reset",
	"DEV asleep",
	"DEV open",
};

static u8 mac_addr[ETH_ALEN] = {0x00, 0x23, 0x56, 0x44, 0x78, 0xaa};


/*********************
 * 同步读取DM9621中的一组连续的寄存器
 * 结果存入data中
 *********************/
static int 
dm_read(struct dm9621_priv *dev, u8 reg, u16 length, void *data)
{
	void *buf;
	int err = -ENOMEM;

	printk("dm_read() reg=0x%02x length=%d\n", reg, length);

	buf = kmalloc(length, GFP_KERNEL);
	if (!buf)
		goto out;

	err = usb_control_msg(dev->udev,
		usb_rcvctrlpipe(dev->udev, 0),
		DM_READ_REGS,
		USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
		0, reg, buf, length, 
		USB_CTRL_SET_TIMEOUT);

	if (err == length)
		memcpy(data, buf, length);
	else if (err >= 0)
		err = -EINVAL;
	kfree(buf);
out:
	return err;
}


/************************
 * 同步读取DM9621中的一个寄存器
 ************************/
static int 
dm_read_reg(struct dm9621_priv *dev, u8 reg, u8 *value)
{
	return dm_read(dev, reg, 1, value);
}


/************************
 * 同步写DM9621中的一组连续的寄存器
 * 返回值为写入的字节数或错误值
 ************************/
static int dm_write(struct dm9621_priv *dev, u8 reg, u16 length, void *data)
{
	void *buf = NULL;
	int err = -ENOMEM;

	printk("dm_write() reg=0x%02x, length=%d\n", reg, length);

	/* 将data中的内容复制到buf中 */
	if (data) {
		buf = kmemdup(data, length, GFP_KERNEL);
		if (!buf)
			goto out;
	}

	err = usb_control_msg(dev->udev,
		usb_sndctrlpipe(dev->udev, 0),
		DM_WRITE_REGS,
		USB_DIR_OUT | USB_TYPE_VENDOR |USB_RECIP_DEVICE,
		0, reg, buf, length, 
		USB_CTRL_SET_TIMEOUT);
	kfree(buf);
	if (err >= 0 && err < length)
		err = -EINVAL;
 out:
	return err;
}


/************************
 * 同步写DM9621中的一个寄存器
 ************************/
static int 
dm_write_reg(struct dm9621_priv *dev, u8 reg, u8 value)
{
	printk("dm_write_reg() reg=0x%02x, value=0x%02x\n", reg, value);

	return usb_control_msg(dev->udev,
		usb_sndctrlpipe(dev->udev, 0),
		DM_WRITE_REG,
		USB_DIR_OUT | USB_TYPE_VENDOR |USB_RECIP_DEVICE,
		value, reg, NULL, 0, 
		USB_CTRL_SET_TIMEOUT);
}


/**********************
 * 异步写DM9621寄存器的回调函数
 * 释放usb_ctrlrequest
 **********************/
static void 
dm_write_async_callback(struct urb *urb)
{
	struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
	int status = urb->status;

	if (status < 0)
		printk("dm_write_callback() failed %d\n", status);

	kfree(req);
	usb_free_urb(urb);
}


/**************************
 * 异步写DM9621中的一组连续寄存器
 **************************/
static void 
dm_write_async_helper(struct dm9621_priv *dev, u8 reg, u8 value, u16 length, void *data)
{
	struct usb_ctrlrequest *req;
	struct urb *urb;
	int status;

	urb = usb_alloc_urb(0, GFP_ATOMIC);
	if (!urb) {
		printk("Alloc URB err in dm_write\n");
		return;
	}

	req = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
	if (!req) {
		printk("Control req alloc failed\n");
		usb_free_urb(urb);
		return;
	}

	req->bRequestType = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
	req->bRequest = length ? DM_WRITE_REGS : DM_WRITE_REG;
	req->wValue = cpu_to_le16(value);
	req->wIndex = cpu_to_le16(reg);
	req->wLength = cpu_to_le16(length);

	usb_fill_control_urb(urb, dev->udev,
		     usb_sndctrlpipe(dev->udev, 0),
		     (void *)req, data, length,
		     dm_write_async_callback, req);

	status = usb_submit_urb(urb, GFP_ATOMIC);
	if (status < 0) {
		printk("Submit con msg err: %d\n", status);
		kfree(req);
		usb_free_urb(urb);
	}
}


/**********************
 * 异步写DM9621寄存器的封装函数
 * 写一组寄存器
 **********************/
static void 
dm_write_async(struct dm9621_priv *dev, u8 reg, u16 length, void *data)
{
	printk("dm_write_async() reg=0x%02x length=%d\n", reg, length);
	dm_write_async_helper(dev, reg, 0, length, data);
}


/**********************
 * 异步写DM9621寄存器的封装函数
 * 写一个寄存器
 **********************/
static void 
dm_write_reg_async(struct dm9621_priv *dev, u8 reg, u8 value)
{
	printk("dm_write_reg_async() reg=0x%02x value=0x%02x\n", reg, value);
	dm_write_async_helper(dev, reg, value, 0, NULL);
}


/*********************
 * 从PHY中读一个字(2字节)
 *********************/
static int 
dm_read_shared_word(struct dm9621_priv *dev, u8 reg, __le16 *value)
{
	int ret, i;

	dm_write_reg(dev, DM_SHARED_ADDR, (reg|0x40));
	dm_write_reg(dev, DM_SHARED_CTRL, 0xC);

	for (i = 0; i < DM_TIMEOUT; i++) {
		u8 tmp;

		udelay(1);
		ret = dm_read_reg(dev, DM_SHARED_CTRL, &tmp);
		if (ret < 0)
			goto out;

		/* ready */
		if ((tmp & 1) == 0)
			break;
	}

	if (i == DM_TIMEOUT) {
		printk("PHY read timed out!\n");
		ret = -EIO;
		goto out;
	}

	dm_write_reg(dev, DM_SHARED_CTRL, 0x0);
	ret = dm_read(dev, DM_SHARED_DATA, 2, value);
out:
	return ret;
}


/*********************
 * 向PHY中写一个字(2字节)
 *********************/
static int 
dm_write_shared_word(struct dm9621_priv *dev, u8 reg, __le16 value)
{
	int ret, i;

	ret = dm_write(dev, DM_SHARED_DATA, 2, &value);
	if (ret < 0)
		goto out;

	dm_write_reg(dev, DM_SHARED_ADDR, (reg | 0x40));
	dm_write_reg(dev, DM_SHARED_CTRL, 0x1A);

	for (i = 0; i < DM_TIMEOUT; i++) {
		u8 tmp;

		udelay(1);
		ret = dm_read_reg(dev, DM_SHARED_CTRL, &tmp);
		if (ret < 0)
			goto out;

		/* ready */
		if ((tmp & 1) == 0)
			break;
	}

	if (i == DM_TIMEOUT) {
		printk("PHY write timed out!\n");
		ret = -EIO;
		goto out;
	}

	dm_write_reg(dev, DM_SHARED_CTRL, 0x0);
out:
	return ret;
}


/**********************
 * mii_if_info->mdio_read
 * 从DM9621的内部PHY中读一个字
 **********************/
static int 
dm9621_mdio_read(struct net_device *ndev, int phy_id, int loc)
{
	struct dm9621_priv *dev = netdev_priv(ndev);
	__le16 res;

	/* 从PHY中读一个字 */
	dm_read_shared_word(dev, loc, &res);
	printk("mdio_read(): loc=0x%02x, val=0x%04x\n", loc, le16_to_cpu(res));

	return le16_to_cpu(res);
}


/***********************
 * mii_if_info->mdio_write
 * 向DM9621内部的PHY写一个word(PHY寄存器都是2字节的)
 ***********************/
static void 
dm9621_mdio_write(struct net_device *ndev, int phy_id, int loc, int val)
{
	struct dm9621_priv *dev = netdev_priv(ndev);
	__le16 res = cpu_to_le16(val);

	dm_write_shared_word(dev, loc, res);
	mdelay(1);
	printk("mdio_write(): loc=0x%02x, val=0x%04x\n", loc, val);
}


/***********************
 * dm9621_kevent()
 * 工作队列的执行函数，需要在进程上下文中调用
 * 处理dm9621_priv->flags中标记的各种事件
 * 对于TX/RX halt核心工作是通知dm9621清除端点的halt状态
 * 事件处理完毕后，要清除flags的对应位
 ***********************/
static void
dm9621_kevent(struct work_struct *work)
{
	struct dm9621_priv *dev = container_of(work, struct dm9621_priv, kevent);
	int status = 0, retval = 0;

	//处理tx halt事件
	//通知dm9621清除out端点的halt状态
	//注意，usb_clear_halt()需要在进程上下文调用
	if (test_bit(EVENT_TX_HALT, &dev->flags)) {
		dm9621_unlink_urbs(dev, &dev->txq);
		status = usb_autopm_get_interface(dev->intf);
		if (status < 0)
			goto fail_pipe;
		status = usb_clear_halt(dev->udev, dev->out);
		usb_autopm_put_interface(dev->intf);
		if (status < 0 &&
		    status != -EPIPE &&
		    status != -ESHUTDOWN) {
			if (netif_msg_tx_err(dev))
fail_pipe:
				printk("Kevent: clear tx halt err\n");
		} else {
			clear_bit(EVENT_TX_HALT, &dev->flags);
			if (status != -ESHUTDOWN)
				netif_wake_queue(dev->net);
		}
	}

	/* 处理RX halt事件 */
	if (test_bit(EVENT_RX_HALT, &dev->flags)) {
		dm9621_unlink_urbs(dev, &dev->rxq);
		status = usb_autopm_get_interface(dev->intf);
		if (status < 0)
			goto fail_halt;
		status = usb_clear_halt(dev->udev, dev->in);
		usb_autopm_put_interface(dev->intf);
		if (status < 0 &&
		    status != -EPIPE &&
		    status != -ESHUTDOWN) {
			if (netif_msg_rx_err(dev))
fail_halt:
				printk("Kevent: clear rx halt err\n");
		} else {
			clear_bit(EVENT_RX_HALT, &dev->flags);
			tasklet_schedule(&dev->bh);
		}
	}

	/* 如果内存紧张，则tasklet可以一直resubmit自己 */
	if (test_bit(EVENT_RX_MEMORY, &dev->flags)) {
		struct urb *urb = NULL;
		int resched = 1;

		if (netif_running(dev->net))
			urb = usb_alloc_urb(0, GFP_KERNEL);
		else
			clear_bit(EVENT_RX_MEMORY, &dev->flags);
		if (urb != NULL) {
			clear_bit(EVENT_RX_MEMORY, &dev->flags);
			status = usb_autopm_get_interface(dev->intf);
			if (status < 0) {
				usb_free_urb(urb);
				goto fail_lowmem;
			}
			if (rx_submit(dev, urb, GFP_KERNEL) == -ENOLINK)
				resched = 0;
			usb_autopm_put_interface(dev->intf);
fail_lowmem:
			if (resched)
				tasklet_schedule(&dev->bh);
		}
	}

	/* 复位连接 */
	if (test_bit(EVENT_LINK_RESET, &dev->flags)) {
		clear_bit(EVENT_LINK_RESET, &dev->flags);
		status = usb_autopm_get_interface(dev->intf);
		if (status < 0)
			goto skip_reset;
		if((retval = dm9621_link_reset(dev)) < 0) {
			usb_autopm_put_interface(dev->intf);
skip_reset:
			printk("Kevent: link reset failed\n");
		} else {
			usb_autopm_put_interface(dev->intf);
		}
	}

	if (dev->flags)
		printk("kevent done\n");
}


/*****************************
 * dm9621_defer_bh()
 * 函数只在tx_complete以及rx_complete中调用
 * 将skb从tx或rx队列中摘除，然后放入done队列
 * 如果done队列中的skb为1，则启动tasklet下半部
 *****************************/
static void 
dm9621_defer_bh(struct dm9621_priv *dev, struct sk_buff *skb, struct sk_buff_head *list)
{
	unsigned long flags;

	/* 注意锁的使用 */
	spin_lock_irqsave(&list->lock, flags);
	__skb_unlink(skb, list);
	spin_unlock(&list->lock);

	spin_lock(&dev->done.lock);
	__skb_queue_tail(&dev->done, skb);
	if (dev->done.qlen == 1)
		tasklet_schedule(&dev->bh);

	spin_unlock_irqrestore(&dev->done.lock, flags);
}


/**********************
 * dm9621_defer_kevent()
 * 标记事件后，启动DM9621的工作队列
 * 在工作队列中处理的通常是一些故障情况，如收发暂停等，连接复位以及网卡open时也会调用
 **********************/
static void 
dm9621_defer_kevent(struct dm9621_priv *dev, int work)
{
	set_bit(work, &dev->flags);
	if (!schedule_work(&dev->kevent))
		printk("kevent %s dropped\n", kevent_msg[work]);
	else
		printk("kevent %s scheduled\n", kevent_msg[work]);
}


/************************
 * dm9621_tx_fixup()
 * 在ndo_start_xmit中调用
 * 对要发送到OUT端点的数据包进行预处理
 ************************/
static struct sk_buff *
dm9621_tx_fixup(struct dm9621_priv *dev, 
		struct sk_buff *skb, gfp_t flags)
{
	int len = skb->len;

	/* format:
	   b1: packet length low
	   b2: packet length high
	   b3..n: packet data
	*/
	//确保skb的data和head之间至少有2字节存储TX附加头
	if (skb_headroom(skb) < DM_TX_OVERHEAD) {
		struct sk_buff *skb2;
		skb2 = skb_copy_expand(skb, DM_TX_OVERHEAD, 0, flags);
		dev_kfree_skb_any(skb);
		skb = skb2;
		if (!skb)
			return NULL;
	}

	//将skb->data减少2字节以存储发送头
	__skb_push(skb, DM_TX_OVERHEAD);

	/* 如果数据包的长度正好是USB端点最大包长度的整数倍，
	 * 则在包的末尾补0，并增加包长度 */
	if ((skb->len % dev->maxpacket) == 0)
		len++;

	skb->data[0] = len;
	skb->data[1] = len >> 8;

	return skb;
}


/*************************
 * tx_complete()
 * 发送urb的回调函数
 *************************/
static void 
tx_complete(struct urb *urb)
{
	struct sk_buff *skb = (struct sk_buff *)urb->context;
	struct skb_data	*entry = (struct skb_data *)skb->cb;
	struct dm9621_priv *dev = entry->dev;

	if (urb->status == 0) {
		dev->net->stats.tx_packets++;
		dev->net->stats.tx_bytes += entry->length;
	} else {
		dev->net->stats.tx_errors++;

		switch (urb->status) {
		case -EPIPE: /* 启动工作队列处理发送挂起 */
			dm9621_defer_kevent(dev, EVENT_TX_HALT);
			break;

		case -ECONNRESET: /* 连接复位 */
		case -ESHUTDOWN:  /* 硬件已经移除 */
			break;

		/* 收发io错误，过一会儿再启动bh继续收发 */
		case -EPROTO:
		case -ETIME:
		case -EILSEQ:
			usb_mark_last_busy(dev->udev);
			if (!timer_pending(&dev->delay)) {
				mod_timer(&dev->delay,
					jiffies + THROTTLE_JIFFIES);
				printk("tx throttle %d\n", urb->status);
			}
			netif_stop_queue(dev->net);
			break;
		default:
			printk("tx err %d\n", entry->urb->status);
			break;
		}
	}

	//无论skb是否发送正确，都将其标记为tx_done，然后从txq移动到done队列
	usb_autopm_put_interface(dev->intf);
	urb->dev = NULL;
	entry->state = tx_done;
	dm9621_defer_bh(dev, skb, &dev->txq);
}


/*************************
 * dm9621_skb_return()
 * 由rx_process()调用
 * 完成一个数据包的接收，将skb处理完后提交给网络子系统
 *************************/
static void 
dm9621_skb_return(struct dm9621_priv *dev, struct sk_buff *skb)
{
	int status;
	
	//printk("In skb_return()\n");
	skb->protocol = eth_type_trans(skb, dev->net);
	dev->net->stats.rx_packets++;
	dev->net->stats.rx_bytes += skb->len;

	printk("< rx, len %zu, type 0x%x\n",
		  skb->len + sizeof(struct ethhdr), skb->protocol);
	memset(skb->cb, 0, sizeof(struct skb_data));

	status = netif_rx(skb);
	if (status != NET_RX_SUCCESS)
		printk("netif_rx status %d\n", status);
}


/***********************
 * dm9621_rx_fixup()
 * !!!9621的返回值和本函数相反
 * 对从IN端点接收到的数据包进行预处理
 ***********************/
static int 
dm9621_rx_fixup(struct dm9621_priv *dev, struct sk_buff *skb)
{
	u8 status;
	int len;

	//参考手册P42, 如果电路图的GPIO2——2引脚拉高，则采用4字节的接收包头，否则为3字节的
	//根据头文件中的内容，9621应该用4字节包头
	/* format:
	   b0: rx checksum
	   b1: rx status
	   b2: packet length (incl crc) low
	   b3: packet length (incl crc) high
	   b4..n-4: packet data
	   bn-3..bn: ethernet crc
	 */
	if (unlikely(skb->len < DM_RX_OVERHEAD)) {
		printk("DM9621 RX: unexpected tiny rx frame\n");
		return -1;
	}

	//将接收长度减4是去掉头部的4字节还是尾部的4字节CRC?
	status = skb->data[1];
	len = (skb->data[2] | (skb->data[3] << 8)) - 4;
	printk(">rx len %d\n", len);

	//如果收到的包有错，则增加错误计数
	if (status & 0xbf) {
		if (status & 0x01) 
			dev->net->stats.rx_fifo_errors++;
		if (status & 0x02) 
			dev->net->stats.rx_crc_errors++;
		if (status & 0x04) 
			dev->net->stats.rx_frame_errors++;
		if (status & 0x20) 
			dev->net->stats.rx_missed_errors++;
		if (status & 0x90) 
			dev->net->stats.rx_length_errors++;
		return -1;
	}

	//将skb->data向上移动4个字节
	skb_pull(skb, 4);

	//将skb缓冲区的数据区截断到len
	skb_trim(skb, len);

	return 0;
}


/**************************
 * rx_process()
 * 由tasklet的下半部函数调用，初步接收一个包
 * 正确包用netif_rx()提交给网络子系统;
 * 错误包要更新ndev->stat中的统计信息;
 * 无论正确还是错误包，都要把skb重新挂回done队列
 **************************/
static void 
rx_process(struct dm9621_priv *dev, struct sk_buff *skb)
{
	int ret = 0;

	/* 首先对接收到的包进行预处理 */
	ret = dm9621_rx_fixup(dev, skb);
	if (ret) {
		dev->net->stats.rx_errors++;
		goto done;
	}

	/* 将处理好的sk_buff提交给网络子系统 */
	if (skb->len) {
		dm9621_skb_return(dev, skb);
		return;
	}

	printk("rx: drop\n");
	dev->net->stats.rx_errors++;
done:
	skb_queue_tail(&dev->done, skb);
}


/***************************
 * rx_submit()
 * 函数负责分配skb并提交给usb子系统
 * (1)urb在调用rx_submit之前分配
 * (2)在rx_submit中准备好接收包需要的skb及其缓冲区
 * (3)最后将urb提交给usb子系统
 * 如提交不成功，在工作队列中完成错误处理;
 * 如提交成功，将新分配的skb挂入rxq队列;
 * 当成功从dm9621接收到数据包后，会调用urb对应的回调函数rx_complete，在函数中将rxq队列中的skb挪动到done队列中，并重新调用rx_submit
 ****************************/
static int 
rx_submit(struct dm9621_priv *dev, struct urb *urb, gfp_t flags)
{
	struct sk_buff		*skb;
	struct skb_data		*entry;
	int			retval = 0;
	unsigned long		lockflags;
	size_t			size = dev->rx_urb_size;

	/* 按最大包长度分配并初始化一个sk_buff */
	if ((skb = alloc_skb(size + NET_IP_ALIGN, flags)) == NULL) {
		printk("no rx skb\n");
		dm9621_defer_kevent(dev, EVENT_RX_MEMORY);
		usb_free_urb(urb);
		return -ENOMEM;
	}
	skb_reserve(skb, NET_IP_ALIGN);

	//初始化skb->cb; 当前skb处于rx_start状态
	entry = (struct skb_data *)skb->cb;
	entry->urb = urb;
	entry->dev = dev;
	entry->state = rx_start;
	entry->length = 0;

	usb_fill_bulk_urb(urb, dev->udev, dev->in,
		skb->data, size, rx_complete, skb);

	spin_lock_irqsave(&dev->rxq.lock, lockflags);

	//向usb子系统提交urb
	//在延后的work队列中处理usb_submit_urb失败的情况
	if (netif_running(dev->net) &&
	    netif_device_present(dev->net) &&
	    !test_bit(EVENT_RX_HALT, &dev->flags) &&
	    !test_bit(EVENT_DEV_ASLEEP, &dev->flags)) {
		switch (retval = usb_submit_urb(urb, GFP_ATOMIC)) {
		case -EPIPE:
			dm9621_defer_kevent(dev, EVENT_RX_HALT);
			break;
		case -ENOMEM:
			dm9621_defer_kevent(dev, EVENT_RX_MEMORY);
			break;
		case -ENODEV:
			printk("DM9621 rx submit: device gone\n");
			netif_device_detach(dev->net);
			break;
		case -EHOSTUNREACH:
			retval = -ENOLINK;
			break;
		default:
			printk("rx submit, %d\n", retval);
			tasklet_schedule(&dev->bh);
			break;
		case 0:
			printk("Add skb to rxq\n");
			__skb_queue_tail(&dev->rxq, skb);
		}
	} else {
		printk("rx: stopped\n");
		retval = -ENOLINK;
	}
	spin_unlock_irqrestore(&dev->rxq.lock, lockflags);

	if (retval) {
		dev_kfree_skb_any(skb);
		usb_free_urb(urb);
	}

	return retval;
}


/************************
 * dm9621_bh()
 * 定时器和tasklet下半部的处理函数
 * 通过tasklet调用为正常情况，在open和tx|rx_complete中启动;
 * 通过定时器调用为非正常，在tx|rx throttle时启动
 * (1)循环对done队列中的skb进行处理
 * (2)当rxq不满时，分配几个新的urb，并调用rx_submit()
 * (3)当txq不满时，唤醒ndev的tx队列
 ************************/
static void 
dm9621_bh(unsigned long param)
{
	struct dm9621_priv *dev = (void *)param;
	struct sk_buff *skb;
	struct skb_data	*entry;

	//(1)首先对done队列中的skb进行处理
	//循环处理done队列中的所有skb
	while ((skb = skb_dequeue(&dev->done))) {
		entry = (struct skb_data *)skb->cb;
		switch (entry->state) {
		case rx_done: 
			//无论收到的包正确还是错误，都在rx_cleanup阶段统一释放
			entry->state = rx_cleanup;
			rx_process(dev, skb);
			continue;
		case tx_done:
		case rx_cleanup:
			usb_free_urb(entry->urb);
			dev_kfree_skb(skb);
			continue;
		default:
			printk("bogus skb state %d\n", entry->state);
		}
	}

	//唤醒因调用dm9621_terminate_urbs()等待txq/rxq/done这3个队列处理完而睡眠的进程
	if (dev->wait) {
		if ((dev->txq.qlen+dev->rxq.qlen+dev->done.qlen) == 0)
			wake_up(dev->wait);
	} else if (netif_running(dev->net) &&
		   netif_device_present(dev->net) &&
		   !timer_pending(&dev->delay) &&
		   !test_bit(EVENT_RX_HALT, &dev->flags)) {
		int temp = dev->rxq.qlen;
		int qlen = RX_QLEN;

		//当rxq队列不满时:
		//(1)首先分配几个新的urb(不超过10个)
		//(2)为每个urb分配对应的skb并提交给usb子系统
		//(3)提交成功的skb放到rxq队列中
		//(4)成功收到数据后，将skb从rxq挪入done队列
		if (temp < qlen) {
			struct urb *urb;
			int i;

			for (i = 0; i < 10 && dev->rxq.qlen < qlen; i++) {
				urb = usb_alloc_urb(0, GFP_ATOMIC);
				if (urb != NULL) {
					if (rx_submit(dev, urb, GFP_ATOMIC) == -ENOLINK)
						return;
				}
			}
			if (temp != dev->rxq.qlen)
				printk("rxqlen %d --> %d\n",
					  temp, dev->rxq.qlen);
			if (dev->rxq.qlen < qlen)
				tasklet_schedule(&dev->bh);
		}

		//当txq队列不满时，唤醒ndev的发送队列
		if (dev->txq.qlen < TX_QLEN)
			netif_wake_queue(dev->net);
	}
}


/**************************
 * rx_complete()
 * 数据包接收urb的回调函数
 * 首先处理接收错误: 将sk_buff置入rx_cleanup状态;
 * 正确接收的包则进入rx_done状态;
 * 不用分配新的urb，再次调用rx_submit()提交
 **************************/
static void 
rx_complete(struct urb *urb)
{
	struct sk_buff *skb = (struct sk_buff *)urb->context;
	struct skb_data	*entry = (struct skb_data *)skb->cb;
	struct dm9621_priv *dev = entry->dev;
	struct net_device *ndev = dev->net;
	int urb_status = urb->status;

	//增加缓冲区的tail和len; 令sk_buff进入rx_done状态
	skb_put(skb, urb->actual_length);
	entry->state = rx_done;
	entry->urb = NULL;

	switch (urb_status) {
	/* 接收成功，但数据内容过短 */
	case 0:
		if (skb->len < ndev->hard_header_len) {
			entry->state = rx_cleanup;
			ndev->stats.rx_errors++;
			ndev->stats.rx_length_errors++;
			printk("rx length %d\n", skb->len);
		}
		break;

	/* RX的stall需要手工复位，不常见 */
	case -EPIPE:
		ndev->stats.rx_errors++;
		dm9621_defer_kevent(dev, EVENT_RX_HALT);

	case -ECONNRESET: /* 连接断开 */
	case -ESHUTDOWN:  /* 设备已经不存在 */
		printk("rx shutdown, code %d\n", urb_status);
		goto block;

	/* 在khubd disconnect()延迟期间遇到控制器I/O错误
	 * 等1/8秒再进行收发(避免throttle) */
	case -EPROTO:
	case -ETIME:
	case -EILSEQ:
		ndev->stats.rx_errors++;
		if (!timer_pending(&dev->delay)) {
			mod_timer(&dev->delay, jiffies+THROTTLE_JIFFIES);
			printk("rx throttle %d\n", urb_status);
		}
block:
		entry->state = rx_cleanup;
		entry->urb = urb;
		urb = NULL;
		break;
	default:
		entry->state = rx_cleanup;
		ndev->stats.rx_errors++;
		printk("rx err %d\n", urb_status);
		break;
	}

	//将收到的sk_buff从rxq队列移动到done队列
	dm9621_defer_bh(dev, skb, &dev->rxq);

	//再次把本urb提交给usb子系统，准备接收下一个包
	//如果设备进入RX_HALT或设备非running，则释放本urb
	if (urb) {
		if (netif_running(dev->net) &&
		    !test_bit(EVENT_RX_HALT, &dev->flags)) {
			rx_submit(dev, urb, GFP_ATOMIC);
			return;
		}
		usb_free_urb(urb);
	}
	printk("no read resubmitted\n");
}


/***********************
 * dm9621_int_fixup()
 * 在intr_complete()中调用
 * 对从INT端点接收到的数据包进行预处理
 * 只对网线状态变化进行处理;
 * buf[0]的bit[0]=1说明9621收到数据包，但下面未进行判断;
 ***********************/
static void 
dm9621_int_fixup(struct dm9621_priv *dev, struct urb *urb)
{
	int link;
	u8 *buf;

	/* format:
	   b0: net status
	   b1: tx status 1
	   b2: tx status 2
	   b3: rx status
	   b4: rx overflow
	   b5: rx count
	   b6: tx count
	   b7: gpr
	*/
	if (urb->actual_length < 8)
		return;
	buf = urb->transfer_buffer;

	//对网线连接&断开进行处理(通过中断端点发送)
	link = !!(buf[0] & 0x40);
	if (netif_carrier_ok(dev->net) != link) {
		if (link) {
			netif_carrier_on(dev->net);
			dm9621_defer_kevent(dev, EVENT_LINK_RESET);
		} else {
			netif_carrier_off(dev->net);
		}
		printk("Link Status is: %d\n", link);
	}
}


/**********************
 * 中断urb的回调函数
 * 注意！9621驱动不是在收到中断包后才启动接收的
 **********************/
static void 
intr_complete(struct urb *urb)
{
	struct dm9621_priv *dev = urb->context;
	int status = urb->status;

	/* 0说明成功从INT端点收到包，首先进行预处理 */
	switch (status) {
	case 0:
		dm9621_int_fixup(dev, urb);
		break;
	case -ENOENT:	 /* urb killed */
	case -ESHUTDOWN: /* hardware gone */
		printk("intr shutdown, code %d\n", status);
		return;
	default:
		printk("intr status %d\n", status);
		break;
	}

	if (!netif_running(dev->net))
		return;

	/* 重新提交INT端点的urb */
	memset(urb->transfer_buffer, 0, urb->transfer_buffer_length);
	status = usb_submit_urb(urb, GFP_ATOMIC);
	if (status != 0)
		printk("intr resubmit --> %d\n", status);
}


/************************
 * dm9621_unlink_urbs()
 * 取消skb队列中所有skb对应的urb，后续的清理工作由完成函数进行
 ************************/
static int
dm9621_unlink_urbs(struct dm9621_priv *dev, struct sk_buff_head *q)
{
	unsigned long	flags;
	struct sk_buff	*skb;
	int		count = 0;

	spin_lock_irqsave(&q->lock, flags);
	while (!skb_queue_empty(q)) {
		struct skb_data	*entry;
		struct urb	*urb;
		int		retval;

		skb_queue_walk(q, skb) {
			entry = (struct skb_data *)skb->cb;
			if (entry->state != unlink_start)
				goto found;
		}
		break;
found:
		entry->state = unlink_start;
		urb = entry->urb;

		//在一些resume场景，(async)的unlink会被马上完成，用计数来确保urb不被释放
		usb_get_urb(urb);
		spin_unlock_irqrestore(&q->lock, flags);
		retval = usb_unlink_urb(urb);
		if (retval != -EINPROGRESS && retval != 0)
			printk("unlink urb err %d\n", retval);
		else
			count++;
		usb_put_urb(urb);
		spin_lock_irqsave(&q->lock, flags);
	}

	spin_unlock_irqrestore (&q->lock, flags);
	return count;
}


/************************
 * dm9621_terminate_urbs()
 * 由dm9621_stop()/dm9621_suspend()等调用
 * 睡眠等待直到txq/rxq/done等队列中的所有sk_buff完成
 * 不要在中断上下文调用
 ************************/
static void 
dm9621_terminate_urbs(struct dm9621_priv *dev)
{
	DECLARE_WAIT_QUEUE_HEAD_ONSTACK(unlink_wakeup);
	DECLARE_WAITQUEUE(wait, current);
	int temp;

	//确保已没有更多active的urbs
 	//睡眠的唤醒在bh函数中
	add_wait_queue(&unlink_wakeup, &wait);
	set_current_state(TASK_UNINTERRUPTIBLE);
	dev->wait = &unlink_wakeup;
	temp = dm9621_unlink_urbs(dev, &dev->txq) +
		dm9621_unlink_urbs(dev, &dev->rxq);

	//等待直到rxq/txq/done等skb的队列都为空
	//在9621_bh()中wake_up()
	//是不是应该先set_current_state?
	while (!skb_queue_empty(&dev->rxq)
		&& !skb_queue_empty(&dev->txq)
		&& !skb_queue_empty(&dev->done)) {
			set_current_state(TASK_UNINTERRUPTIBLE);
			schedule_timeout(msecs_to_jiffies(UNLINK_TIMEOUT_MS));
			printk("waited for %d urb completions\n", temp);
	}
	set_current_state(TASK_RUNNING);
	dev->wait = NULL;
	remove_wait_queue(&unlink_wakeup, &wait);
}


/*************************
 * dm9621_link_reset()
 * 当判断网卡有连接状态变化时调用本函数
 *************************/
static int 
dm9621_link_reset(struct dm9621_priv *dev)
{
	struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };

	/* 参数的(1,1)意思为可打印网络连接状态并修改mii结构体 */
	mii_check_media(&dev->mii, 1, 1);
	mii_ethtool_gset(&dev->mii, &ecmd);

	printk("link_reset() speed: %u duplex: %d\n",
		   ecmd.speed, ecmd.duplex);

	return 0;
}


/************************
 * net_device_ops->ndo_tx_timeout
 * 先取消所有提交的TX相关urb，然后调度下半部
 ************************/
static void 
dm9621_tx_timeout(struct net_device *ndev)
{
	struct dm9621_priv *dev = netdev_priv(ndev);

	dm9621_unlink_urbs(dev, &dev->txq);
	tasklet_schedule(&dev->bh);
}


/************************
 * net_device_ops->ndo_start_xmit
 ************************/
static netdev_tx_t
dm9621_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
	struct dm9621_priv *dev = netdev_priv(ndev);
	int		length;
	struct urb	*urb = NULL;
	struct skb_data	*entry;
	unsigned long	flags;
	int retval;

	//3.5驱动新增的
	skb_tx_timestamp(skb);

	/* 首先对要发送的包进行预处理 */
	skb = dm9621_tx_fixup(dev, skb, GFP_ATOMIC);
	if (!skb) {
		printk("tx: can't fixup skb\n");
		goto drop;
	}

	/* 分配并初始化发送用的urb */
	length = skb->len;
	if (!(urb = usb_alloc_urb(0, GFP_ATOMIC))) {
		printk("no urb\n");
		goto drop;
	}

	entry = (struct skb_data *)skb->cb;
	entry->urb = urb;
	entry->dev = dev;
	entry->length = length;

	usb_fill_bulk_urb(urb, dev->udev, dev->out,
			skb->data, skb->len, tx_complete, skb);

	/* 不要假定硬件可以自动处理0长度的usb包，在skb的数据中补尾0 */
	if (length % dev->maxpacket == 0) {
		urb->transfer_buffer_length++;
		if (skb_tailroom(skb)) {
			skb->data[skb->len] = 0;
			__skb_put(skb, 1);
		}
	}

	spin_lock_irqsave(&dev->txq.lock, flags);
	retval = usb_autopm_get_interface_async(dev->intf);
	if (retval < 0) {
		spin_unlock_irqrestore(&dev->txq.lock, flags);
		goto drop;
	}

#ifdef CONFIG_PM
	if (test_bit(EVENT_DEV_ASLEEP, &dev->flags)) {
		/* 在设备resume时完成传输 */
		usb_anchor_urb(urb, &dev->deferred);
		/* 设备睡眠时就没必要发更多包了 */
		netif_stop_queue(ndev);
		spin_unlock_irqrestore(&dev->txq.lock, flags);
		printk("Delaying transmission for resumption\n");
		goto tx_ok;
	}
#endif

	/* 将包含skb的urb提交给usb子系统 */
	switch ((retval = usb_submit_urb(urb, GFP_ATOMIC))) {
	case -EPIPE:
		netif_stop_queue(ndev);
		dm9621_defer_kevent(dev, EVENT_TX_HALT);
		usb_autopm_put_interface_async(dev->intf);
		retval = 0;
		break;
	default:
		usb_autopm_put_interface_async(dev->intf);
		printk("tx: submit urb err %d\n", retval);
		break;
	case 0: /* 向txq提交urb成功 */
		ndev->trans_start = jiffies;
		__skb_queue_tail(&dev->txq, skb);
		entry->state = tx_start;
		if (dev->txq.qlen >= TX_QLEN)
			netif_stop_queue(ndev);
	}
	spin_unlock_irqrestore(&dev->txq.lock, flags);

tx_ok:
	if (retval == 0)
		return NETDEV_TX_OK;
drop:
	dev->net->stats.tx_dropped++;
	if (skb)
		dev_kfree_skb_any(skb);
	if (urb)
		usb_free_urb(urb);

	return NETDEV_TX_BUSY;	
}


/******************************
 * net_device_ops->ndo_do_ioctl
 ******************************/
static int 
dm9621_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
	struct dm9621_priv *dev = netdev_priv(ndev);

	return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}


/******************************
 * net_device_ops->ndo_set_rx_mode
 ******************************/
static void 
dm9621_set_multicast(struct net_device *ndev)
{
	struct dm9621_priv *dev = netdev_priv(ndev);
	u8 hashes[DM_MCAST_SIZE];
	u8 rx_ctl = 0x31;

	//默认支持所有广播地址
	memset(hashes, 0xFF, DM_MCAST_SIZE);
	hashes[DM_MCAST_SIZE-1] |= 0x80;

	if (ndev->flags & IFF_PROMISC) {
		rx_ctl |= 0x02;
	} 
	else if (ndev->flags & IFF_ALLMULTI) {
		rx_ctl |= 0x08;
	} 

	dm_write_async(dev, DM_MCAST_ADDR, DM_MCAST_SIZE, hashes);
	dm_write_reg_async(dev, DM_RX_CTRL, rx_ctl);
}


static void 
__dm9621_set_mac_address(struct dm9621_priv *dev)
{
	dm_write_async(dev, DM_PHY_ADDR, ETH_ALEN, dev->net->dev_addr);
}


/*************************
 * net_device_ops->ndo_set_mac_address
 * 将新的MAC地址写入net_device以及DM9621的寄存器  
 *************************/
static int 
dm9621_set_mac_address(struct net_device *ndev, void *p)
{
	struct sockaddr *addr = p;
	struct dm9621_priv *dev = netdev_priv(ndev);

	if (!is_valid_ether_addr(addr->sa_data)) {
		dev_err(&ndev->dev, "invalid mac address %p\n", addr->sa_data);
		return -EINVAL;
	}

	memcpy(ndev->dev_addr, addr->sa_data, ndev->addr_len);
	__dm9621_set_mac_address(dev);

	return 0;
}


/***********************
 * net_device_ops->ndo_open
 ***********************/
static int 
dm9621_open(struct net_device *ndev)
{
	struct dm9621_priv *dev = netdev_priv(ndev);
	int retval;

	if ((retval = usb_autopm_get_interface(dev->intf)) < 0) {
		printk("DM9621 open: 9621 powerdown\n");
		goto done_nopm;
	}

	//检测网线是否连通
	dm9621_link_reset(dev);

	/* 启动中断传输 */
	if (dev->interrupt) {
		retval = usb_submit_urb(dev->interrupt, GFP_KERNEL);
		if (retval < 0) {
			printk("DM9621 open: int ep submit err\n");
			goto done;
		}
	}

	printk("DM9621 open: start queue\n");
	set_bit(EVENT_DEV_OPEN, &dev->flags);
	netif_start_queue(ndev);

	/* 设备完全open后，触发下半部 */
	tasklet_schedule(&dev->bh);

	return retval;
done:
	usb_autopm_put_interface(dev->intf);
done_nopm:
	return retval;
}


/***************************
 * net_device_ops->ndo_stop
 ***************************/
static int 
dm9621_stop(struct net_device *ndev)
{
	struct dm9621_priv *dev = netdev_priv(ndev);

	clear_bit(EVENT_DEV_OPEN, &dev->flags);
	netif_stop_queue(ndev);

	printk("stop stats: rx/tx %lu/%lu, errs %lu/%lu\n",
		   ndev->stats.rx_packets, ndev->stats.tx_packets,
		   ndev->stats.rx_errors, ndev->stats.tx_errors);

	/* 等待所有urb停止 */
	dm9621_terminate_urbs(dev);

	//停止提交中断urb
	usb_kill_urb(dev->interrupt);

	dev->flags = 0;
	del_timer_sync(&dev->delay);
	tasklet_kill(&dev->bh);

	usb_autopm_put_interface(dev->intf);

	return 0;
}


/*************************
 * dm9621_int_init()
 * 在usb_driver->probe中调用
 * 初始化DM9621的int端点(urb和buffer固定分配好)
 * 中断urb在dm9621_open时submit
 *************************/
static int 
dm9621_int_init(struct dm9621_priv *dev, struct usb_interface *intf)
{
	char *buf = NULL;
	unsigned int pipe = 0;
	unsigned int maxp;
	unsigned int period;

	/* 获取中断端点的pipe号以及最大包长度 */
	pipe = usb_rcvintpipe(dev->udev, dev->status->desc.bEndpointAddress & 0xF);
	maxp = usb_maxpacket(dev->udev, pipe, 0);

	/* 设定轮循周期为5ms */
	period = 5;

	/* 分配中断端点的固定urb以及缓冲区 */
	buf = kmalloc(maxp, GFP_KERNEL);
	if (buf) {
		dev->interrupt = usb_alloc_urb(0, GFP_KERNEL);
		if (!dev->interrupt) {
			kfree(buf);
			return -ENOMEM;
		} else {
			usb_fill_int_urb(dev->interrupt, dev->udev, pipe, buf, maxp, intr_complete, dev, period);
			dev->interrupt->transfer_flags |= URB_FREE_BUFFER;
			printk("Interrupt ep%d(in), %d bytes period %d\n", usb_pipeendpoint(pipe), maxp, period);
		}
	}

	return 0;
}


/**************************
 * dm9621_priv_init()
 * 在usb_driver->probe中调用
 * 初始化dm9621_priv，设置MAC地址，reset PHY
 **************************/
static int 
dm9621_priv_init(struct dm9621_priv *dev, struct usb_interface *intf)
{
	int ep, ret;
	u8 tmp;
	struct usb_host_interface *alt = NULL;
	struct usb_host_endpoint *in = NULL, *out = NULL;
	struct usb_host_endpoint *status = NULL;
	struct usb_host_endpoint *e = NULL;

	/* 通过解读interface，找到9621的3个端点 */
	alt = intf->altsetting;
	for (ep = 0; ep < alt->desc.bNumEndpoints; ep++) {
		e = alt->endpoint + ep;
		switch (e->desc.bmAttributes) {
		case USB_ENDPOINT_XFER_INT:
			if (usb_endpoint_dir_in(&e->desc))
				status = e;
			break;
		case USB_ENDPOINT_XFER_BULK:
			if (usb_endpoint_dir_in(&e->desc))
				in = e;
			else if (usb_endpoint_dir_out(&e->desc))
				out = e;
			break;
		}
	}
	
	if (!status || !in || !out)
		return -EINVAL;

	//in&out中保存批量输入/输出端点的pipe号
	//status保存中断端点的usb_host_endpoint指针
	dev->in = usb_rcvbulkpipe(dev->udev,
		    	in->desc.bEndpointAddress & 0xF);
	dev->out = usb_sndbulkpipe(dev->udev,
			out->desc.bEndpointAddress & 0xF);
	dev->status = status;

	/* 设置dm9621_priv的部分成员 */
	dev->rx_urb_size = dev->net->mtu + ETH_HLEN + DM_RX_OVERHEAD;
	dev->maxpacket = usb_maxpacket(dev->udev, dev->out, 1);

	//初始化mii_if_info结构体
	dev->mii.dev = dev->net;
	dev->mii.mdio_read = dm9621_mdio_read;
	dev->mii.mdio_write = dm9621_mdio_write;
	dev->mii.phy_id_mask = 0x1f;
	dev->mii.reg_num_mask = 0x1f;
	dev->mii.phy_id = DM9621_PHY_ID;

	//读取并打印部分DM9621寄存器
	ret = dm_read_reg(dev, 0x29, &tmp);
	if (ret >= 0)
		printk("dm9621--PID(0x29): 0x%02x\n", tmp);
	else
		printk("dm9621--PID(0x29): read error\n");

	ret = dm_read_reg(dev, 0x28, &tmp);
	if (ret >= 0)
		printk("dm9621--PID(0x28): 0x%02x\n", tmp);
	else
		printk("dm9621--PID(0x28): read error\n");

	ret = dm_read_reg(dev, DM_SMIREG, &tmp);
	if (ret >= 0)
		printk("dm9621--SMI(0x91): 0x%02x\n", tmp);
	else
		printk("dm9621--SMI(0x91): read error\n");

	ret = dm_read_reg(dev, 0xF2, &tmp);
	if (ret >= 0)
		printk("dm9621--status(0xF2): 0x%02x\n", tmp);
	else
		printk("dm9621--status(0xF2): read error\n");

	//software reset
	dm_write_reg(dev, DM_NET_CTRL, 1);
	udelay(20);

	//dm9620增加了流控的支持(我没加)

	//设置0xf4 usb控制寄存器
	//bit[5]=1(EP3在每个中断间隔返回8字节数据)
	//bit[4]=1(EP3总是返回NAK)
	dm_write_reg(dev, USB_CTRL, (0x1<<5));

	/* 将MAC地址写入dm9621的寄存器 */
	__dm9621_set_mac_address(dev);

	/* power up phy */
	dm_write_reg(dev, DM_GPR_CTRL, 1);
	dm_write_reg(dev, DM_GPR_DATA, 0);

#if DM_TX_CS_EN
	//发送checksum控制(0x31, P22)
	//bit[2:0]=0x7(硬件完成IP/UDP/TCP的checksum)
	dm_write_reg(dev, DM_TX_CRC_CTRL, 7);
#endif
	//接收checksum控制(0x32, P23)
	//bit[1]=1(使能硬件RXchecksum，结果存入收到数据包的第一个字节)
	dm_write_reg(dev, DM_RX_CRC_CTRL, 2);

	/* 使能接收 */
	dm9621_set_multicast(dev->net);

	/* 重新复位PHY */
	dm9621_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
	dm9621_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE, ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
	mii_nway_restart(&dev->mii);

	return 0;
}


//net_device->netdev_ops
//网络驱动的操作函数集
static struct net_device_ops dm9621_netdev_ops = {
	.ndo_open		= dm9621_open,
	.ndo_stop		= dm9621_stop,
	.ndo_start_xmit		= dm9621_start_xmit,
	.ndo_tx_timeout		= dm9621_tx_timeout,
	.ndo_do_ioctl		= dm9621_ioctl,
	.ndo_set_rx_mode 	= dm9621_set_multicast,
	.ndo_set_mac_address 	= dm9621_set_mac_address,
	.ndo_validate_addr	= eth_validate_addr,
};


/*************************
 * usb_driver->probe
 *************************/
static int
dm9621_probe(struct usb_interface *intf, const struct usb_device_id *prod)
{
	struct dm9621_priv *dev;
	struct net_device *ndev;
	struct usb_host_interface *interface;
	struct usb_device *udev;
	int ret;

	//设备要支持自动挂起(9601的驱动注释掉pm_runtime一句)
	//以前支持，暂时去掉
	//if (!driver->supports_autosuspend) {
	//	driver->supports_autosuspend = 1;
	//	pm_runtime_enable(&intf->dev);
	//}

	udev = interface_to_usbdev(intf);
	interface = intf->cur_altsetting;

	/* 增加usb_device的计数 */
	usb_get_dev(udev);

	/* 分配net_device以及dm9621_priv */
	ndev = alloc_etherdev(sizeof(*dev));
	if (!ndev) {
		printk("can't alloc dm9621_priv&net_device\n");
		ret = -ENOMEM;
		goto out;
	}
	SET_NETDEV_DEV(ndev, &intf->dev);

	/* 初始化dm9621_priv结构体 */
	dev = netdev_priv(ndev);
	dev->net = ndev;
	dev->udev = udev;
	dev->intf = intf;
	dev->msg_enable = NETIF_MSG_DRV | 
			  NETIF_MSG_PROBE | 
			  NETIF_MSG_LINK;

	/* 初始化sk_buff的队列 */
	skb_queue_head_init(&dev->rxq);
	skb_queue_head_init(&dev->txq);
	skb_queue_head_init(&dev->done);

	/* 初始化下半部；工作队列；usb_anchor */
	dev->bh.func = dm9621_bh;
	dev->bh.data = (unsigned long)dev;
	INIT_WORK(&dev->kevent, dm9621_kevent);
	init_usb_anchor(&dev->deferred);

	/* 初始化timer_list(执行函数和下半部的一样) */
	setup_timer(&dev->delay, dm9621_bh, (unsigned long)(dev));

	//设置net_device的name以及mac地址
	strcpy(ndev->name, "eth%d");
	memcpy(ndev->dev_addr, mac_addr, sizeof(mac_addr));

	//初始化net_device的部分成员
 	//！注意，9621发送时要增加2个字节包头 
	ndev->netdev_ops  = &dm9621_netdev_ops;
	ndev->watchdog_timeo = TX_TIMEOUT_JIFFIES;

	/* 初始化dm9621_priv，将MAC地址写入网卡，reset phy */
	ret = dm9621_priv_init(dev, intf);
	if (ret < 0)
		goto out1;

	/* 初始化中断端点 */
	ret = dm9621_int_init(dev, intf);
	if (ret < 0)
		goto out2;

	/* 注册net_device */
	ret = register_netdev(ndev);
	if (ret)
		goto out2;
	printk("Register dm9621 net_device\n");

	/* 利用usb_interface传递dm9621_priv结构体 */
	usb_set_intfdata(intf, dev);

	netif_device_attach(ndev);
	//9601原始驱动一开始网卡为off，是否应on?
	//netif_carrier_off(ndev);
	netif_carrier_on(ndev);

	return 0;
out2:
	usb_kill_urb(dev->interrupt);
	usb_free_urb(dev->interrupt);
out1:
	free_netdev(ndev);
out:
	usb_put_dev(udev);
	return ret;
}


/*************************
 * usb_driver->disconnect
 * 不要在中断上下文中调用
 *************************/
static void 
dm9621_disconnect(struct usb_interface *intf)
{
	struct dm9621_priv *dev;
	struct usb_device *udev;
	struct net_device *ndev;

	dev = usb_get_intfdata(intf);
	if (!dev)
		return;
	usb_set_intfdata(intf, NULL);

	udev = interface_to_usbdev(intf);
	ndev = dev->net;

	//注销net_device
	printk("Unregister dm9621 net_device\n");
	unregister_netdev(ndev);

	cancel_work_sync(&dev->kevent);

	usb_kill_urb(dev->interrupt);
	usb_free_urb(dev->interrupt);

	//释放net_device; 递减usb_device的计数
	free_netdev(ndev);
	usb_put_dev(udev);
}


/**************************
 * usb_driver->suspend
 * usb设备是有自动挂起能力的，但如果当前有数据包已经submit，则不要suspend
 **************************/
static int 
dm9621_suspend(struct usb_interface *intf, pm_message_t message)
{
	struct dm9621_priv *dev = usb_get_intfdata(intf);

	//suspend支持嵌套，第一次挂起时执行if中的内容
	//如果发送队列非空，则不允许挂起;
	//detach，完成所有缓冲的urb，再次attach设备
	if (!dev->suspend_count++) {
		spin_lock_irq(&dev->txq.lock);
		if (dev->txq.qlen) {
			dev->suspend_count--;
			spin_unlock_irq(&dev->txq.lock);
			return -EBUSY;
		} else {
			set_bit(EVENT_DEV_ASLEEP, &dev->flags);
			spin_unlock_irq(&dev->txq.lock);
		}

		//detach设备，完成当前缓冲的所有urb的收发
		//挂起后不要再执行中断urb
		netif_device_detach(dev->net);
		dm9621_terminate_urbs(dev);
		usb_kill_urb(dev->interrupt);

		/* 重新attach设备 */
		netif_device_attach(dev->net);
	}
	return 0;
}


/*********************
 * usb_driver->resume
 * 在resume之前，如果有要发送的urb会缓存在usb_anchor中
 * (在urb->context中记录该urb对应的sk_buff)
 *********************/
static int
dm9621_resume(struct usb_interface *intf)
{
	struct dm9621_priv *dev = usb_get_intfdata(intf);
	struct sk_buff *skb;
	struct urb *res;
	int retval;

	//递减计数，当计数为0时执行if中的内容
	if (!--dev->suspend_count) {
		/* 重新提交中断端点的URBs */
		if (dev->interrupt && test_bit(EVENT_DEV_OPEN, &dev->flags))
			usb_submit_urb(dev->interrupt, GFP_NOIO);

		//如果有推迟而未提交的urb，则提交
		spin_lock_irq(&dev->txq.lock);
		while ((res = usb_get_from_anchor(&dev->deferred))) {
			skb = (struct sk_buff *)res->context;
			retval = usb_submit_urb(res, GFP_ATOMIC);
			if (retval < 0) {
				dev_kfree_skb_any(skb);
				usb_free_urb(res);
				usb_autopm_put_interface_async(dev->intf);
			} else {
				//提交urb成功后，将sk_buff加入txq队列
				dev->net->trans_start = jiffies;
				__skb_queue_tail(&dev->txq, skb);
			}
		}

		smp_mb();
		clear_bit(EVENT_DEV_ASLEEP, &dev->flags);
		spin_unlock_irq(&dev->txq.lock);

		//如果等待发完的包不足60个，则唤醒tx队列
		if (test_bit(EVENT_DEV_OPEN, &dev->flags)) {
			if (!(dev->txq.qlen >= TX_QLEN))
				netif_tx_wake_all_queues(dev->net);
			tasklet_schedule(&dev->bh);
		}
	}

	return 0;
}


static const struct usb_device_id products[] = {
	{
	 USB_DEVICE(0x0a46, 0x9621), /* Davicom USB 9621 */
	},
	{},
};

MODULE_DEVICE_TABLE(usb, products);

static struct usb_driver dm9621_driver = {
	.name 		= "dm9621",
	.id_table 	= products,
	.probe 		= dm9621_probe,
	.disconnect 	= dm9621_disconnect,
	.suspend 	= dm9621_suspend,
	.resume 	= dm9621_resume,
};


static int __init dm9621_init(void)
{
	return usb_register(&dm9621_driver);
}

static void __exit dm9621_exit(void)
{
	usb_deregister(&dm9621_driver);
}

module_init(dm9621_init);
module_exit(dm9621_exit);

MODULE_AUTHOR("ZHT");
MODULE_DESCRIPTION("Davicom DM9621 USB 2.0 ethernet driver");
MODULE_LICENSE("GPL");

