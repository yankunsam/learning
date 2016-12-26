/******************************
 * 对usb相关结构体的总结(省略不常用的成员)
 * 以下来自于<linux/usb.h>
 ******************************/

//1.和endpoint对应的结构体(usb.h)
//封装端点描述符
struct usb_host_endpoint {
	struct usb_endpoint_descriptor	desc;
	struct list_head urb_list;
	void	*hcpriv;
	struct ep_device *ep_dev; /* 用于sysfs */
	...
};


//2.和interface的setting对应的结构体
//封装interface描述符
struct usb_host_interface {
	struct usb_interface_descriptor	desc;
	//endpoint结构体的数组头
	//数组有desc.bNumEndpoint个成员
	struct usb_host_endpoint *endpoint;
	...
};


//3.和interface对应的结构体(匹配usb_driver)
//封装了device结构体
struct usb_interface {
	//为了长期保存，属于一个interface的多个setting常常保存在usb_interface_cache中
	struct usb_host_interface *altsetting;
	struct usb_host_interface *cur_altsetting;
	unsigned num_altsetting;

	//如果生成usb的char设备，次设备号存在这里
	int minor; 	

	//封装的device结构体
	struct device dev;
	struct device *usb_dev;
	...
};

//和usb_interface对应的几个宏
//usb_interface的作用和platform_device类似
#define	to_usb_interface(d) container_of(d, struct usb_interface, dev)

//设置和获得drvdata
void *usb_get_intfdata(struct usb_interface *intf);
void usb_set_intfdata(struct usb_interface *intf, void *data);

//增加和递减usb_interface的计数
struct usb_interface *usb_get_intf(struct usb_interface *intf);
void usb_put_intf(struct usb_interface *intf);

/* 最大值是随便取的 */
#define USB_MAXINTERFACES	32
#define USB_MAXIADS		16
#define USB_MAXCHILDREN		31 //hub下的端口数量

//4.通过计数长期保存一组setting值
struct usb_interface_cache {
	unsigned num_altsetting; //setting的数量
	//setting的变长数组
	struct usb_host_interface altsetting[0];

	struct kref ref;
};
#define	ref_to_usb_interface_cache(r) \
	container_of(r, struct usb_interface_cache, ref)
#define	altsetting_to_usb_interface_cache(a) \
	container_of(a, struct usb_interface_cache, altsetting[0])


//5.对应一个usb的configure
//封装config描述符
struct usb_host_config {
	struct usb_config_descriptor	desc;

	/* 本配置可能包含的usb_interface(最多32个) */
	struct usb_interface *interface[USB_MAXINTERFACES];
	/* 每个usb_interface对应的setting */
	struct usb_interface_cache *intf_cache[USB_MAXINTERFACES];
	...
};


/* 已分配的usb设备地址的位图(128位) */
struct usb_devmap {
	unsigned long devicemap[128 / (8*sizeof(unsigned long))];
};


//每个usb_bus分配一个
//和实际存在的usb host一一对应
struct usb_bus {
	struct device *controller; //主机host的结构体
	int busnum;	//总线号
	const char *bus_name; //固定ID，如PCI slot名等
	//host是否使用DMA或PIO
	u8 uses_dma;
	u8 uses_pio_for_control;

	//下一个打开设备的号(round-robin); 
	//设备地址的位图
	int devnum_next; 
	struct usb_devmap devmap;

	//根HUB的设备; usb_bus的链表
	struct usb_device *root_hub;
	struct list_head bus_list;
	...
};


//对应一个usb设备(用于匹配usb_device_driver)
//封装device描述符
struct usb_device {
	struct usb_device_descriptor descriptor;

	int	devnum;
	char	devpath[16];
	enum usb_device_state	state;
	enum usb_device_speed	speed;

	unsigned int toggle[2];
	struct usb_device *parent;
	struct usb_bus *bus;

	struct device dev;

	struct usb_host_config *config;
	struct usb_host_config *actconfig;

	struct usb_host_endpoint ep0;
	struct usb_host_endpoint *ep_in[16];
	struct usb_host_endpoint *ep_out[16];

	int maxchild;
	struct usb_device **children;

	atomic_t urbnum;
	...
};
#define	to_usb_device(d) container_of(d, struct usb_device, dev)

//从usb_interface找到usb_device
//两者内部的device有父子关系
struct usb_device *interface_to_usbdev(struct usb_interface *intf);

//增加和递减usb_device的计数
struct usb_device *usb_get_dev(struct usb_device *dev);
void usb_put_dev(struct usb_device *dev);

//usb设备加锁/解锁
//可用于usb_device和usb_interface，使用内部的device结构体带的mutex_lock
#define usb_lock_device(udev)		device_lock(&(udev)->dev)
#define usb_unlock_device(udev)		device_unlock(&(udev)->dev)
#define usb_trylock_device(udev)	device_trylock(&(udev)->dev)

//获得usb设备的路径
int usb_make_path(struct usb_device *dev, char *buf, size_t size)
{
	int actual;
	actual = snprintf(buf, size, "usb-%s-%s", dev->bus->bus_name, dev->devpath);
	return (actual >= (int)size) ? -1 : actual;
}

//usb_interface和usb_driver的匹配
//usb_device_id定义在<linux/mod_devicetable.h>
struct usb_device_id {
	//匹配哪个域
	__u16	match_flags;
	__u16	idVendor;
	__u16	idProduct;
	...
};

#define USB_DEVICE_ID_MATCH_DEVICE \
		(USB_DEVICE_ID_MATCH_VENDOR | \
		 USB_DEVICE_ID_MATCH_PRODUCT)

//用USB_DEVICE宏可以初始化一个usb_device_id
#define USB_DEVICE(vend, prod) \
	.match_flags = USB_DEVICE_ID_MATCH_DEVICE, \
	.idVendor = (vend), \
	.idProduct = (prod)


//动态usb_device_id(构成链表)
struct usb_dynids {
	spinlock_t lock;
	struct list_head list;
};

struct usb_dynid {
	struct list_head node;
	struct usb_device_id id;
};

struct usbdrv_wrap {
	struct device_driver driver;
	//非0用于usb_device_driver(匹配usb_device);
	//0用于usb_driver(匹配usb_interface)
	int for_devices;
};


//和usb_interface匹配的驱动
//由用户驱动提供，类似于platform_driver
struct usb_driver {
	const char *name;

	int (*probe) (struct usb_interface *intf,
		     const struct usb_device_id *id);
	void (*disconnect) (struct usb_interface *intf);
	int (*suspend) (struct usb_interface *intf, pm_message_t message);
	int (*resume) (struct usb_interface *intf);
	...
	const struct usb_device_id *id_table;
	struct usb_dynids dynids;
	struct usbdrv_wrap drvwrap;
	...
};
#define	to_usb_driver(d) container_of(d, struct usb_driver, drvwrap.driver)


//和usb_device匹配的驱动
//由usb系统提供，纯粹凑数用，驱动人员不用考虑
struct usb_device_driver {
	const char *name;

	int (*probe) (struct usb_device *udev);
	void (*disconnect) (struct usb_device *udev);
	int (*suspend) (struct usb_device *udev, pm_message_t message);
	int (*resume) (struct usb_device *udev, pm_message_t message);
	struct usbdrv_wrap drvwrap;
	...
};
#define	to_usb_device_driver(d) container_of(d, struct usb_device_driver, \
		drvwrap.driver)

//对应整个usb总线(只有一个)
//前面的usb_bus是每个usb主机一个的
extern struct bus_type usb_bus_type;

//usb_driver的注册和注销函数
//别忘了准备MODULE_DEVICE_TABLE(usb, ...)
int usb_register_driver(struct usb_driver *, struct module *, const char *);
extern void usb_deregister(struct usb_driver *);

//驱动注册时推荐使用封装宏
#define usb_register(driver) \
	usb_register_driver(driver, THIS_MODULE, KBUILD_MODNAME)


/************************************
 * 以下为URB的支持，用于usb的异步请求
 ************************************/

//以下标志用于urb->transfer_flags(仅列出可能用到的)
//URB_DIR_IN/OUT自动在usb_submit_urb()时设置
#define URB_SHORT_NOT_OK 	0x0001	/* report short reads as errors */
#define URB_NO_TRANSFER_DMA_MAP	0x0004	/* urb->transfer_dma valid on submit */
#define URB_ZERO_PACKET		0x0040	/* Finish bulk OUT with short packet */
#define URB_FREE_BUFFER		0x0100	/* Free transfer buffer with the URB */

/* 以下标记由usbcore和HCD使用 */
#define URB_DIR_IN	0x0200 //从设备到主机
#define URB_DIR_OUT	0
#define URB_DIR_MASK	URB_DIR_IN

#define URB_DMA_MAP_SINGLE	0x00010000	/* Non-scatter-gather mapping */
#define URB_DMA_MAP_PAGE	0x00020000	/* HCD-unsupported S-G */
#define URB_MAP_LOCAL		0x00080000	/* HCD-local-memory mapping */
#define URB_SETUP_MAP_SINGLE	0x00100000	/* Setup packet DMA mapped */
#define URB_SETUP_MAP_LOCAL	0x00200000	/* HCD-local setup packet */
...


//urb的链表(关联一个等待队列)
struct usb_anchor {
	struct list_head urb_list;
	wait_queue_head_t wait;
	spinlock_t lock;
	unsigned int poisoned:1;
};
void init_usb_anchor(struct usb_anchor *anchor);


//urb的回调函数
typedef void (*usb_complete_t)(struct urb *);


//urb，用于和usb设备上的端点进行通讯
struct urb {
	struct kref kref; //urb的计数
	int unlinked;	//unlink的错误码

	//urb链表，由owner使用或链接到anchor
	struct list_head urb_list;
	struct list_head anchor_list;

	struct usb_anchor *anchor;
	struct usb_device *dev;
	struct usb_host_endpoint *ep;

	//pipe信息(包含端点号、方向和类型)
	unsigned int pipe;

	//非ISO端点的返回值
	int status;

	//端点的缓冲区以及传输长度
	unsigned int transfer_flags;
	void *transfer_buffer;
	dma_addr_t transfer_dma;
	u32 transfer_buffer_length;
	u32 actual_length;

	//只用于控制端点
	unsigned char *setup_packet;
	dma_addr_t setup_dma;

	//用于INT/ISO端点的间隔值
	int interval;

	//回调函数(常常将私有结构体赋给context)
	void *context;
	usb_complete_t complete;
	...
};


//初始化控制传输用的urb
void usb_fill_control_urb(struct urb *urb,
	struct usb_device *dev,	
	unsigned int pipe,
	unsigned char *setup_packet,
	void *transfer_buffer, 
	int buffer_length,
	usb_complete_t complete_fn, 
	void *context);

//初始化bulk传输用的urb
void usb_fill_bulk_urb(struct urb *urb,
     struct usb_device *dev,
     unsigned int pipe,
     void *transfer_buffer,
     int buffer_length,
     usb_complete_t complete_fn,
     void *context);

//初始化int传输用的urb
void usb_fill_int_urb(struct urb *urb,
    struct usb_device *dev,
    unsigned int pipe,
    void *transfer_buffer,
    int buffer_length,
    usb_complete_t complete_fn,
    void *context,
    int interval)
{
	if (dev->speed == USB_SPEED_HIGH || 
	    dev->speed == USB_SPEED_SUPER)
		urb->interval = 1 << (interval - 1);
	else
		urb->interval = interval;
	urb->start_frame = -1;
	...
}


void usb_init_urb(struct urb *urb);
struct urb *usb_alloc_urb(int iso_packets, gfp_t mem_flags);
void usb_free_urb(struct urb *urb); //即usb_pub_urb
struct urb *usb_get_urb(struct urb *urb);

int usb_submit_urb(struct urb *urb, gfp_t mem_flags);
int usb_unlink_urb(struct urb *urb);
void usb_kill_urb(struct urb *urb);
void usb_block_urb(struct urb *urb);

//usb_anchor相关
void usb_kill_anchored_urbs(struct usb_anchor *anchor);
void usb_unlink_anchored_urbs(struct usb_anchor *anchor);
void usb_anchor_urb(struct urb *urb, struct usb_anchor *anchor);
void usb_unanchor_urb(struct urb *urb);
int usb_anchor_empty(struct usb_anchor *anchor);
struct urb *usb_get_from_anchor(struct usb_anchor *anchor);

//返回1则urb的方向为IN(从设备到主机); 否则为0
int usb_urb_dir_in(struct urb *urb)
{
	return (urb->transfer_flags & URB_DIR_MASK) 
		== URB_DIR_IN;
}

//返回1则urb的方向为OUT(从主机到设备); 否则为0
int usb_urb_dir_out(struct urb *urb)
{
	return (urb->transfer_flags & URB_DIR_MASK) 
		== URB_DIR_OUT;
}

void *usb_alloc_coherent(struct usb_device *dev, size_t size,
	gfp_t mem_flags, dma_addr_t *dma);
void usb_free_coherent(struct usb_device *dev, size_t size,
	void *addr, dma_addr_t dma);


/************************
 * 以下为usb的同步请求传输
 ************************/

//以ms为单位
#define USB_CTRL_GET_TIMEOUT	5000
#define USB_CTRL_SET_TIMEOUT	5000

//同步传输一个control的请求
int usb_control_msg(struct usb_device *dev, 
	unsigned int pipe, __u8 request, 
	__u8 requesttype, __u16 value, 
	__u16 index, void *data, 
	__u16 size, int timeout);

//传输中断和bulk消息
int usb_interrupt_msg(struct usb_device *usb_dev, 
	unsigned int pipe, void *data, 
	int len, int *actual_length, 
	int timeout);

int usb_bulk_msg(struct usb_device *usb_dev, 
	unsigned int pipe, void *data, 
	int len, int *actual_length,
	int timeout);

//通过调用usb_control_msg向usb设备发送标准请求
//获得usb设备描述符，字符串描述符等
int usb_get_descriptor(struct usb_device *dev, 
	unsigned char desctype, unsigned char descindex, 
	void *buf, int size);
int usb_get_status(struct usb_device *dev,
	int type, int target, void *data);
int usb_string(struct usb_device *dev, 
	int index, char *buf, size_t size);

//更新usbcore中的状态
int usb_clear_halt(struct usb_device *dev, int pipe);
int usb_reset_configuration(struct usb_device *dev);
int usb_set_interface(struct usb_device *dev, int ifnum, int alternate);
void usb_reset_endpoint(struct usb_device *dev, unsigned int epaddr);


/**********************************
 * urb->pipe的定义
 * bit[7]=0(Out); =1(In)
 * bit[14:8]=7位的设备地址(0~127)
 * bit[18:15]=4位的endpoint号(0~15)
 * bit[31:30]=2位的端点传输类型
 * 	00(ISO); 01(Int); 10(Ctrl); 11(Bulk)
 **********************************/
#define PIPE_ISOCHRONOUS	0
#define PIPE_INTERRUPT		1
#define PIPE_CONTROL		2
#define PIPE_BULK		3

//以下宏用于取出PIPE中的不同部分
#define usb_pipein(pipe)	((pipe) & USB_DIR_IN)
#define usb_pipeout(pipe)	(!usb_pipein(pipe))

#define usb_pipedevice(pipe)	(((pipe) >> 8) & 0x7f)
#define usb_pipeendpoint(pipe)	(((pipe) >> 15) & 0xf)

#define usb_pipetype(pipe)	(((pipe) >> 30) & 3)
#define usb_pipeisoc(pipe)	(usb_pipetype((pipe)) == PIPE_ISOCHRONOUS)
#define usb_pipeint(pipe)	(usb_pipetype((pipe)) == PIPE_INTERRUPT)
#define usb_pipecontrol(pipe)	(usb_pipetype((pipe)) == PIPE_CONTROL)
#define usb_pipebulk(pipe)	(usb_pipetype((pipe)) == PIPE_BULK)

//以下宏用于构建pipe
unsigned int __create_pipe(struct usb_device *dev,
		unsigned int endpoint)
{
	return (dev->devnum << 8) | (endpoint << 15);
}

//构建ctrl传输用的pipe
#define usb_sndctrlpipe(dev, endpoint)	\
	((PIPE_CONTROL << 30) | __create_pipe(dev, endpoint))
#define usb_rcvctrlpipe(dev, endpoint)	\
	((PIPE_CONTROL << 30) | __create_pipe(dev, endpoint) | USB_DIR_IN)
//构建bulk传输用的pipe
#define usb_sndbulkpipe(dev, endpoint)	\
	((PIPE_BULK << 30) | __create_pipe(dev, endpoint))
#define usb_rcvbulkpipe(dev, endpoint)	\
	((PIPE_BULK << 30) | __create_pipe(dev, endpoint) | USB_DIR_IN)
//构建Int传输用的pipe
#define usb_sndintpipe(dev, endpoint)	\
	((PIPE_INTERRUPT << 30) | __create_pipe(dev, endpoint))
#define usb_rcvintpipe(dev, endpoint)	\
	((PIPE_INTERRUPT << 30) | __create_pipe(dev, endpoint) | USB_DIR_IN)


//根据pipe号，找到usb_device中的usb_host_endpoint
struct usb_host_endpoint *
usb_pipe_endpoint(struct usb_device *dev, unsigned int pipe)
{
	struct usb_host_endpoint **eps;
	eps = usb_pipein(pipe) ? dev->ep_in : dev->ep_out;
	return eps[usb_pipeendpoint(pipe)];
}

//返回端点支持的最大packet长度
__u16 
usb_maxpacket(struct usb_device *udev, int pipe, int is_out)
{
	struct usb_host_endpoint *ep;
	unsigned epnum = usb_pipeendpoint(pipe);

	if (is_out) {
		ep = udev->ep_out[epnum];
	} else {
		ep = udev->ep_in[epnum];
	}
	if (!ep)
		return 0;

	return usb_endpoint_maxp(&ep->desc);
}


//将usb的错误码转换为用户空间可识别的错误码
int usb_translate_errors(int error_code)
{
	switch (error_code) {
	case 0:
	case -ENOMEM:
	case -ENODEV:
	case -EOPNOTSUPP:
		return error_code;
	default:
		return -EIO;
	}
}

/* Events from the usb core */
#define USB_DEVICE_ADD		0x0001
#define USB_DEVICE_REMOVE	0x0002
#define USB_BUS_ADD		0x0003
#define USB_BUS_REMOVE		0x0004
extern void usb_register_notify(struct notifier_block *nb);
extern void usb_unregister_notify(struct notifier_block *nb);



/****************************
 * 以下内容来自于<usb/ch9.h>
 ****************************/

#define USB_DIR_OUT	0	//主机到设备
#define USB_DIR_IN	0x80	//设备到主机

//命令类型，用于setup包中的bRequestType域
#define USB_TYPE_MASK		(0x03 << 5)
#define USB_TYPE_STANDARD	(0x00 << 5)
#define USB_TYPE_CLASS		(0x01 << 5)
#define USB_TYPE_VENDOR		(0x02 << 5)
#define USB_TYPE_RESERVED	(0x03 << 5)

//命令的接收者，用于setup包中的bRequestType域
#define USB_RECIP_MASK		0x1f
#define USB_RECIP_DEVICE	0x00
#define USB_RECIP_INTERFACE	0x01
#define USB_RECIP_ENDPOINT	0x02
#define USB_RECIP_OTHER		0x03

//标准命令号，用于setup包的bRequest域
#define USB_REQ_GET_STATUS	0x00
#define USB_REQ_CLEAR_FEATURE	0x01
#define USB_REQ_SET_FEATURE	0x03
#define USB_REQ_SET_ADDRESS	0x05
#define USB_REQ_GET_DESCRIPTOR	0x06
#define USB_REQ_SET_DESCRIPTOR	0x07
#define USB_REQ_GET_CONFIGURATION 0x08
#define USB_REQ_SET_CONFIGURATION 0x09
#define USB_REQ_GET_INTERFACE	0x0A
#define USB_REQ_SET_INTERFACE	0x0B
#define USB_REQ_SYNCH_FRAME	0x0C
...

/*****************************
 * usb_ctrlrequest封装setup包(8字节)
 * 用于和端点0之间的控制传输
 *****************************/
struct usb_ctrlrequest {
	__u8 bRequestType;
	__u8 bRequest;
	__le16 wValue;
	__le16 wIndex;
	__le16 wLength;
} __attribute__ ((packed));


//usb描述符的类型(见usb2.0规范的表9.5)
#define USB_DT_DEVICE			0x01
#define USB_DT_CONFIG			0x02
#define USB_DT_STRING			0x03
#define USB_DT_INTERFACE		0x04
#define USB_DT_ENDPOINT			0x05
#define USB_DT_DEVICE_QUALIFIER		0x06
#define USB_DT_OTHER_SPEED_CONFIG	0x07
#define USB_DT_INTERFACE_POWER		0x08
/* these are from a minor usb 2.0 revision (ECN) */
#define USB_DT_OTG			0x09
#define USB_DT_DEBUG			0x0a
#define USB_DT_INTERFACE_ASSOCIATION	0x0b
/* these are from the Wireless USB spec */
#define USB_DT_SECURITY			0x0c
#define USB_DT_KEY			0x0d
#define USB_DT_ENCRYPTION_TYPE		0x0e
#define USB_DT_BOS			0x0f
#define USB_DT_DEVICE_CAPABILITY	0x10
#define USB_DT_WIRELESS_ENDPOINT_COMP	0x11
#define USB_DT_WIRE_ADAPTER		0x21
#define USB_DT_RPIPE			0x22
#define USB_DT_CS_RADIO_CONTROL		0x23
/* From the T10 UAS specification */
#define USB_DT_PIPE_USAGE		0x24
/* From the USB 3.0 spec */
#define	USB_DT_SS_ENDPOINT_COMP		0x30


//1.设备描述符
struct usb_device_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__le16 bcdUSB;
	__u8  bDeviceClass;
	__u8  bDeviceSubClass;
	__u8  bDeviceProtocol;
	__u8  bMaxPacketSize0;
	__le16 idVendor;
	__le16 idProduct;
	__le16 bcdDevice;
	__u8  iManufacturer;
	__u8  iProduct;
	__u8  iSerialNumber;
	__u8  bNumConfigurations;
} __attribute__ ((packed));
#define USB_DT_DEVICE_SIZE	18

//class的编码，出现在设备描述符的bDeviceClass域
#define USB_CLASS_PER_INTERFACE		0
#define USB_CLASS_AUDIO			1
#define USB_CLASS_COMM			2
#define USB_CLASS_HID			3
#define USB_CLASS_PHYSICAL		5
#define USB_CLASS_STILL_IMAGE		6
#define USB_CLASS_PRINTER		7
#define USB_CLASS_MASS_STORAGE		8
#define USB_CLASS_HUB			9
#define USB_CLASS_CDC_DATA		0x0a
#define USB_CLASS_CSCID			0x0b
#define USB_CLASS_CONTENT_SEC		0x0d
#define USB_CLASS_VIDEO			0x0e
#define USB_CLASS_WIRELESS_CONTROLLER	0xe0
#define USB_CLASS_MISC			0xef
#define USB_CLASS_APP_SPEC		0xfe
#define USB_CLASS_VENDOR_SPEC		0xff
#define USB_SUBCLASS_VENDOR_SPEC	0xff


//2.配置描述符
struct usb_config_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__le16 wTotalLength;
	__u8  bNumInterfaces;
	__u8  bConfigurationValue;
	__u8  iConfiguration;
	__u8  bmAttributes;
	__u8  bMaxPower;
} __attribute__ ((packed));
#define USB_DT_CONFIG_SIZE	9


//3.字符串描述符
//第一个string描述符是特殊的，记录设备支持的语言编码(非Unicode字符)
struct usb_string_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__le16 wData[1]; /* UTF-16LE encoded */
} __attribute__ ((packed));


//4.interface描述符
struct usb_interface_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__u8  bInterfaceNumber;
	__u8  bAlternateSetting;
	__u8  bNumEndpoints;
	__u8  bInterfaceClass;
	__u8  bInterfaceSubClass;
	__u8  bInterfaceProtocol;
	__u8  iInterface;
} __attribute__ ((packed));
#define USB_DT_INTERFACE_SIZE	9


//5.端点描述符
struct usb_endpoint_descriptor {
	__u8  bLength;
	__u8  bDescriptorType;

	__u8  bEndpointAddress;
	__u8  bmAttributes;
	__le16 wMaxPacketSize;
	__u8  bInterval;
} __attribute__ ((packed));
#define USB_DT_ENDPOINT_SIZE	7

//用于bEndpointAddress域
//bit[7]数据方向; bit[3:0]端点号
#define USB_ENDPOINT_NUMBER_MASK	0x0f
#define USB_ENDPOINT_DIR_MASK		0x80

//用于bmAttributes域bit[1:0]
#define USB_ENDPOINT_XFERTYPE_MASK	0x03
#define USB_ENDPOINT_XFER_CONTROL	0
#define USB_ENDPOINT_XFER_ISOC		1
#define USB_ENDPOINT_XFER_BULK		2
#define USB_ENDPOINT_XFER_INT		3

//获得端点号(0~15)
int usb_endpoint_num(struct usb_endpoint_descriptor *);
//获得端点类型
int usb_endpoint_type(struct usb_endpoint_descriptor *);

//端点为IN/OUT则返回true
int usb_endpoint_dir_in(struct usb_endpoint_descriptor *);
int usb_endpoint_dir_out(struct usb_endpoint_descriptor *);

//端点为bulk/control/int等类型返回true
int usb_endpoint_xfer_bulk(struct usb_endpoint_descriptor *);
int usb_endpoint_xfer_control(struct usb_xxx *);
int usb_endpoint_xfer_int(struct usb_xxx *);

//端点为bulk-in/bulk-out返回true
int usb_endpoint_is_bulk_in(struct usb_xxx *epd);
int usb_endpoint_is_bulk_out(struct usb_xxx *epd);

//端点为int-in/int-out则返回true
int usb_endpoint_is_int_in(struct usb_xxx *epd);
int usb_endpoint_is_int_out(struct usb_xxx *epd);

//返回端点的最大packet大小
int usb_endpoint_maxp(struct usb_endpoint_descriptor *epd)
{
	return __le16_to_cpu(epd->wMaxPacketSize);
}

//返回端点的interrupt类型
int usb_endpoint_interrupt_type(struct usb_endpoint_descriptor *epd)
{
	return epd->bmAttributes & USB_ENDPOINT_INTRTYPE;
}

enum usb_device_speed {
	USB_SPEED_UNKNOWN = 0,
	USB_SPEED_LOW, USB_SPEED_FULL, //1.1
	USB_SPEED_HIGH,	//2.0
	USB_SPEED_WIRELESS, //wireless(usb 2.5)
	USB_SPEED_SUPER, //usb 3.0
};



