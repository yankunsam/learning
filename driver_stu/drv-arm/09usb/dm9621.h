/**************************
 * DM9621芯片的头文件
 * author: zht
 * date: 2013-12-19
 **************************/
#ifndef __DM9621_H__
#define __DM9621_H__

#define	RX_QLEN 	60
#define	TX_QLEN 	60

/* 发送队列stop后，必须在此时间内被唤醒，否则发送超时 */
#define TX_TIMEOUT_JIFFIES	(5*HZ)

/* 在遇到一些错误后可能会发生rx/tx的throttle，在我们报告太多的错误前，khubd可能会将网卡disconnect()(khubd采用HZ/4轮询) */
#define THROTTLE_JIFFIES	(HZ/8)

/* 用于等待sk_buff队列中的所有sk_buff完成 */
#define UNLINK_TIMEOUT_MS	3


/* dm9621网卡的私有结构体，封装net_device */
struct dm9621_priv {
	struct usb_device	*udev;
	struct usb_interface	*intf;
	wait_queue_head_t	*wait;
	unsigned char		suspend_count;

	//in&out中为bulkin和bulkout端点的pipe值
	//maxpacket为bulkout端点的最大包长度
	//rx_urb_size为接收urb的最大长度
	//(1500+14+4(crc)+4(head))
	unsigned int	in, out;
	unsigned int	maxpacket;
	size_t		rx_urb_size;

	//中断端点及其urb(只需分配一次，轮循提交)
	struct usb_host_endpoint *status;
	struct urb	*interrupt;

	//网络设备和mii的结构体
	struct net_device	*net;
	int			msg_enable;
	struct mii_if_info	mii;

	/* 无论接收或发送完成的sk_buff都会放入done队列 */
	struct sk_buff_head	rxq;
	struct sk_buff_head	txq;
	struct sk_buff_head	done;

	struct usb_anchor	deferred;
	struct timer_list	delay;
	struct tasklet_struct	bh;
	struct work_struct	kevent;

	unsigned long		flags;
#define EVENT_TX_HALT		0
#define EVENT_RX_HALT		1
#define EVENT_RX_MEMORY		2
#define EVENT_LINK_RESET	3
#define EVENT_DEV_ASLEEP 	4 //autosuspend
#define EVENT_DEV_OPEN		5
};


/* 记录每个加入队列的skb的状态 */
enum skb_state {
	illegal = 0,
	tx_start, tx_done,
	rx_start, rx_done, rx_cleanup,
	unlink_start
};


//利用skb->cb[48]来存放skb_data结构体
struct skb_data {
	struct urb 		*urb;
	struct dm9621_priv	*dev;
	enum skb_state		state;
	size_t			length;
};


/***********************
 * 函数原型声明
 ***********************/
static int 
dm9621_rx_fixup(struct dm9621_priv *dev, struct sk_buff *skb);
static struct sk_buff * 
dm9621_tx_fixup(struct dm9621_priv *dev, struct sk_buff *skb, gfp_t flags);
static void 
dm9621_int_fixup(struct dm9621_priv *dev, struct urb *urb);

static void dm9621_kevent(struct work_struct *work);
static void dm9621_defer_kevent(struct dm9621_priv *dev, int work);
static void dm9621_bh(unsigned long param);
static void dm9621_defer_bh(struct dm9621_priv *dev, 
			struct sk_buff *skb, struct sk_buff_head *list);

static int rx_submit(struct dm9621_priv *dev, 
			struct urb *urb, gfp_t flags);
static void dm9621_skb_return(struct dm9621_priv *dev, 
			struct sk_buff *skb);
static void rx_process(struct dm9621_priv *dev, 
			struct sk_buff *skb);
static void rx_complete(struct urb *urb);
static void intr_complete(struct urb *urb);
static void tx_complete(struct urb *urb);

static int  dm9621_unlink_urbs(struct dm9621_priv *dev, 
			struct sk_buff_head *q);
static void dm9621_terminate_urbs(struct dm9621_priv *dev);

static int  dm9621_link_reset(struct dm9621_priv *dev);




/****************************
 * 以下为dm9621的命令号和寄存器偏移
 ****************************/

/* control requests */
#define DM_READ_REGS	0x00
#define DM_WRITE_REGS	0x01
#define DM_WRITE_REG	0x03

/* registers */
#define DM_NET_CTRL	0x00
#define DM_RX_CTRL	0x05
#define DM_FLOW_CTRL	0x0a
#define DM_SHARED_CTRL	0x0b
#define DM_SHARED_ADDR	0x0c
#define DM_SHARED_DATA	0x0d	/* low + high */
#define DM_EE_PHY_L	0x0d 	/* 低字节 */
#define DM_EE_PHY_H	0x0e	/* 高字节 */
#define DM_PHY_ADDR	0x10	/* 6 bytes */
#define DM_MCAST_ADDR	0x16	/* 8 bytes */
#define DM_GPR_CTRL	0x1e
#define DM_GPR_DATA	0x1f

//dm9620.c中新增的
#define DM_PID      	0x2a	//2A&2B为Product ID
#define DM_TX_CRC_CTRL	0x31	//发送checksum(不是CRC)
#define DM_RX_CRC_CTRL	0x32	//接收checksum
#define DM_SMIREG       0x91	//Mode control
#define DM_USBADDR	0x96	//usb地址(我加的)
#define DM_USBDA	0xf0	//usb device addr(我加的)
#define USB_CTRL	0xf4	//usb control

//不知用途，来自dm9620.c
#define PHY_SPEC_CFG	20
#define DM_TXRX_M       0x5C

#define DM_MAX_MCAST	64
#define DM_MCAST_SIZE	8
#define DM_EEPROM_LEN	256

//以下9621和9601有不同
//9621的pin13如果拉高，则采用4字节的包头;
//否则采用9601兼容模式(电路图上已经拉高)
#define DM_TX_OVERHEAD		2 /* 2 byte header */
#define DM_RX_OVERHEAD_9601	7 /* 3 byte header + 4 byte crc tail */
#define DM_RX_OVERHEAD		8 /* 4 byte header + 4 byte crc tail */
#define DM_TIMEOUT		1000
#define DM_MODE9621     	0x80
#define DM_TX_CS_EN		0 //发送checksum使能
#define DM9621_PHY_ID		1 //读PHY寄存器时使用


#endif /* __DM9601_H__ */

