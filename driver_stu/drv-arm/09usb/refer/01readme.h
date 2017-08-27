/*******************
 * USB总线特点
 *******************/

1.物理连接
USB设备具有热插拔，即插即用的特点，可以从总线上获得+5V，小于等于500mA的电流;
根据USB系统规范，USB总线上总共可连接127个设备;
usb电缆级联的总长度不能超过30米;


2.usb地址
USB设备和USB主机间采用树形结构，主从通讯模式，通讯只能由主机发起;
在usb总线上，由usb主机为每个连接在总线上的usb设备(包含usb集线器及根集线器)分配一个地址，usb主机将通过设备地址访问设备；
每个usb设备新加入总线时都具有默认的地址0，在设备的枚举过程中，主机会为设备分配一个新的地址，当设备的枚举过程结束后，usb主机就会一直用新的设备地址和设备通讯了;
由于设备不能超过127个，因此usb采用7位地址;


3.数据传输
usb1.1和2.0为半双工传输，采用4根电缆，两根数据线D+和D-用于差分数据传输，另两根线Vbus和GND为usb设备供电。usb电缆最长不要超过5米;
usb3.0采用全双工传输，8根线缆，在usb2.0的基础上增加了2对高速传输专用的数据线;

usb1.1协议支持：
1.5Mbps的低速数据传输(low speed);
12Mbps的全速数据传输(full speed);
usb2.0协议增加:
480Mbps的高速数据传输(high speed);
usb3.0协议增加：
2.4Gbps(全双工)的超高速数据传输(super speed);


/***************************
 * usb的描述符(descriptor)
 ***************************/
描述符提供了描述设备属性和特点的信息。当一个新的usb设备插入到usb总线后，usb主机首先要获得这个设备的描述符，从而确定这是个什么样的设备，然后才能开始后续的操作。
标准的描述符共有5种：
*设备描述符(device descriptor)
*配置描述符(configuration descriptor)
*接口描述符(interface descriptor)
*端点描述符(endpoint descriptor)
*字符串描述符(string descriptor)
在设备的枚举阶段，usb设备将按照一定的顺序向主机提供这些描述符。

(2)类(class)
usb设备连接到usb总线后，要想让设备工作起来，还需要加载对应的驱动程序。对于按照寄存器访问的设备，每个设备由于寄存器的名字，访问地址等一般是不相同的，所以要分别加载不同的驱动。由于市场上常常充满了大量不同公司生产的功能类似的设备，操作系统需要被迫为每个设备都提供不同的驱动，这会占用大量的资源。

针对这一情况，usb协议放弃了对设备寄存器，地址等的规定，采用全新的方式描述设备，并根据设备功能对设备进行分类。这样，usb设备只要遵循usb类规范，在插入usb总线后，就可以直接使用usb主机端提供的usb类驱动，完全不必再自行设计驱动程序了。

usb类为最终用户提供了很大的方便，比如我们常用的U盘设备，绝大多数都是采用大容量存储类(mass-storage class)设计的，这样，只要u盘插入的系统可以提供大容量存储类的驱动就可以了，不必为每个u盘都安装驱动程序。

usb规范中明确规定的设备类包括:
*语音设备类(audio device)
-针对麦克风，音响等语音/音频设备
*通信设备类(communications device)
-针对电话，调制解调器等设备
*芯片/智能卡接口设备类(chip/smart card interface devices)
-针对符合ISO/IEC7816规范的设备
*设备固件更新类(device firmware upgrade)
-用于更新usb设备上的固件
*影像设备(imaging device)
-针对扫描仪，数码相机等设备
*人机交互设备类(human interface device)
-针对鼠标，键盘，游戏杆等设备
*IrDA设备类(IrDA bridge device)
-针对IrDA(红外)设备
*大容量存储设备类(mass storage device)
针对CD-ROM，U盘等设备
*物理接口设备类(physical interface device)
-针对具有实时物体反馈的设备
*电源设备类(power device)
针对电源控制等设备
*打印机设备类(printer device)
-针对打印机设备
*监视器设备类(monitor device)
-针对显示器等设备


(3)功能(function)/接口(interface)
从用户的角度来看,usb设备可以提供各类功能,而从设备角度来说,用接口来描述一项单一的功能.一个物理的usb设备内部可能有多个不同的接口(比如一个既有鼠标又有游戏杆的设备)


(4)端点(endpoint)
端点是usb设备和usb主机的通讯管道。每一个端点都有自己的端点号，一个设备最多有16个端点(用4位端点号区分)，端点号由设备自行分配。每个端点只支持一种传输方式，除了支持控制传输的端点外，每个端点是单向的。



3.usb的通信
usb的通讯可以分为3层：
信号层：最底层，传输单元为包(packet)，其传输由usb物理器件负责
协议层：传输单元为事务处理(transaction)，对应设备的endpoint
数据传输层：传输单元为传输(transfer)，对应设备的interface

(1)包packet
一个数据包最多由5个部分组成：
同步字段(SYNC)；PID字段；数据字段；CRC字段；包结尾字段(EOP)

pid字段为包标识符，表明包的类型，共有10种：
a.令牌包
输出(OUT); 输入(IN); 桢起始(SOF); 设置(setup)
b.数据包
数据0(DATA0); 数据1(DATA1)
C.握手包
确认(ACK); 不确认(NAK); 停止(STALL)
d.专用包
前同步(PRE)
out,in和setup包中包含了设备的地址和端点号(7位地址+4位端点号)；
sof包包含11位的桢号；
data0和data1包中包含8到1023个字节的数据(在发送数据包之前，必须先由主机发送一个out/in/setup包，从而确定数据包的发送对象以及方向)
ack/nak/stall包中只有pid类型，不含数据，ack可以由主机或设备发送，而nak和stall只能由设备发送




/***************************
 * USB驱动程序
 ***************************/

USB是主机和外围总线间的一种连接方式，最高支持480Mbps的通信速率。USB在技术上采用单主方式实现，USB设备在没有主控制器要求的情况下是不能发送数据的。USB设备连接到USB集线器上，两者通过4线电缆(地线，电源线和两根差分信号线)

USB协议规定了一些特定的类型标准，如果一个USB设备遵循这些类型标准，就不需要特定的驱动程序，这些类型称为类(class)。类型包括存储设备，键盘、鼠标、游戏杆、网络设备，调制解调器等。不符合标准类型的USB设备需要特定的驱动程序。

USB驱动主要有3类：
(1)USB host driver
(2)USB device driver
(3)USB gadget driver

USB设备驱动构架在USB核心上，USB核心为驱动程序提供了一个访问设备硬件的接口，不必考虑当前采用的host控制器。架构间的关系如下：
USB设备驱动 -> USB核心(usb协议栈) ->USB host驱动(UHCI/OHCI/EHCI驱动)
 
和USB设备相关的概念包括配置，接口，设置和端点。配置描述了一个USB设备的特性，一个配置可以包括多个接口；USB设备驱动绑定到接口而不是整个设备上；一个接口通过若干端点和USB主控制器通信；一个接口可以选择多种设置，每种设置采用不同的端口特性。
* - devices have one (usually) or more configs;
* - configs have one (often) or more interfaces;
* - interfaces have one (usually) or more settings;
* - each interface setting has zero or(usually) more endpoints.
Devices may also have class-specific or vendor-specific descriptors.


1.端点(usb_host_endpoint)
---------------------------
USB通过端点(endpoint)通信，端点是单或双方向的，从主机到设备或从设备到主机，可以看作是一个管道。
USB有4种不同的端点类型：
(1)控制(control)
通常用于配置设备，获取设备信息，发送命令到设备，获取设备状态等。每个设备都有一个"端点0"控制端点。USB协议保证控制端点的带宽。控制传输常常分为三个阶段：
*设置阶段(setup)
由一个setup包和一个data包组成
*数据阶段(data)
数据阶段是可选的，既可以没有，也可以传输多个数据包。数据阶段的方向由设置阶段决定，由一个in/out包引导一个data包
*状态阶段(status)
由in/out包和一个零长度的data包组成，in/out的方向和数据阶段正相反

(2)中断(interrupt)
以固定的速率传输少量数据。USB的鼠标和键盘主要采用中断方式传输。USB协议保证中断端点的带宽。

(3)批量(bulk)
用于传输大量数据。类似于TCP，数据可靠性有保证，传输时间无保证。常用于打印机，存储设备，网络设备等

(4)等时(isochronous)
类似于UDP，协议不保证数据可靠到达。常用于音频和视频设备

批量和控制是异步的，由驱动按需要使用；
等时和中断是周期性的，一旦启用就要分配带宽；

用于描述端点的结构体有两个，usb_host_endpoint和usb_endpoint_descriptor。根据USB设备枚举时传来的信息填充：
<linux/usb.h>
struct usb_host_endpoint {
  struct usb_endpoint_descriptor  desc;
  struct list_head  urb_list;
  void  *hcpriv;
  struct ep_device *ep_dev;
  /* For sysfs info */
  unsigned char *extra;   
  /* Extra descriptors */
  int extralen;
  int enabled;
};

<linux/usb/ch9.h>
/* 根据设备端点描述符的内容填充 */
struct usb_endpoint_descriptor {
  __u8  bLength;
  __u8  bDescriptorType;
  __u8  bEndpointAddress;
  __u8  bmAttributes;
  __le16 wMaxPacketSize;
  __u8  bInterval;
/* 下面两个只用在音频设备的端点上，所以，使用 USB_DT_ENDPOINT*_SIZE in bLength, not sizeof. */
  __u8  bRefresh;
  __u8  bSynchAddress;
} __attribute__ ((packed));

#define USB_DT_ENDPOINT_SIZE       7
#define USB_DT_ENDPOINT_AUDIO_SIZE 9  
/* Audio extension */

@bEndpointAddress
特定端点的USB地址。bit7中还包含了端点的方向。可以结合宏USB_DIR_OUT(0，从主机到设备)和USB_DIR_IN(0x80，从设备到主机)使用。
一个设备最多16个端点(4位端点号)，和传输方向结合后，可形成32个管道：
USB_ENDPOINT_NUMBER_MASK 0x0f
USB_ENDPOINT_DIR_MASK    0x80

@bmAttributes
端点的类型。结合USB_ENDPOINT_XFERTYPE_MASK使用
USB_ENDPOINT_XFERTYPE_MASK  0x03 
USB_ENDPOINT_XFER_CONTROL   0
USB_ENDPOINT_XFER_ISOC      1
USB_ENDPOINT_XFER_BULK      2
USB_ENDPOINT_XFER_INT       3

@wMaxPacketSize
端点一次可以处理的最大字节数。驱动可以发送大于此值的数据到端点

@bInterval
中断类型端点的时间间隔。以ms为单位


2.接口(usb_interface)
---------------------------
一个接口对应一个功能，而一个功能需要一个驱动程序，所以包含多个接口的设备需要有多个驱动程序。接口可以有不同的setting，最初状态为setting0

<linux/usb.h>
struct usb_host_interface {
  struct usb_interface_descriptor desc;
  /*desc.bNumEndpoint说明本接口使用几个端点*/    
  struct usb_host_endpoint *endpoint;
  /*本接口所包含端点的数组头*/
  char *string; 
  unsigned char *extra;
  int extralen;
};
/*一个接口有几个setting，就会填充几个usb_host_interface，但同一时间只有其中一个可用 */

<linux/usb/ch9.h>
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
  }__attribute__((packed));
USB_DT_INTERFACE_SIZE  9 
上面的结构体是在设备枚举时填充的，而内核使用usb_interface来描述接口，类似于pci_dev，usb核心会在调用usb驱动时传入usb_interface.

<linux/usb.h>
struct usb_interface {
  struct usb_host_interface *altsetting;
  struct usb_host_interface *cur_altsetting;
  unsigned num_altsetting;
/*在usb_interface中，可以选择不同的接口setting*/
  ...
  int minor; /* 当使用usb major时有用(180) */
  struct device dev;
  struct device *usb_dev; /* usb class */
  ...
};
如果调用了usb_register_dev，则在usb_driver的probe函数中将通过usbcore分配的minor保存到usb_interface->minor中


3.配置(usb_host_config)
---------------------------
USB接口被捆绑为配置。一个设备可以有多个配置，同一时刻只能激活其中之一。

*设备通常有一个或多个配置(config)
*配置通常有一个或多个接口(interface)
*接口通常有一个或多个设置(setting)
*接口没有或者有一个以上的端点(endpoint)

<linux/usb.h>
struct usb_host_config {
  struct usb_config_descriptor desc;
  char *string;
  ...
  struct usb_interface *interface[USB_MAXINTERFACES];
  struct usb_interface_cache *intf_cache[USB_MAXINTERFACES];
/*xx_cache中为usb_host_interface分配了空间，而usb_interface只有指针*/
  unsigned char *extra; /*Extra descriptors*/
  int extralen;
};
#define USB_MAXINTERFACES  32

<linux/usb/ch9.h>
struct usb_config_descriptor {
  __u8  bLength;
  __u8  bDescriptorType;
  __le16 wTotalLength;
/*属于此配置的所有接口描述符和端点描述符的总大小*/
  __u8  bNumInterfaces;
  __u8  bConfigurationValue;
  __u8  iConfiguration;
  __u8  bmAttributes;
  __u8  bMaxPower;
} __attribute__ ((packed));
USB_DT_CONFIG_SIZE  9

/* from config descriptor bmAttributes */
USB_CONFIG_ATT_ONE (1 << 7) /*必须设置*/
USB_CONFIG_ATT_SELFPOWER (1 << 6) /*自供电*/
USB_CONFIG_ATT_WAKEUP(1 << 5) /*可唤醒 */
USB_CONFIG_ATT_BATTERY(1 << 4) /*电池供电*/



4.设备(usb_device)
---------------------------
内核用usb_device描述整个设备，一个设备可以包含多个usb_interface。所以，可能有多个usb_driver对应同一个usb_device。

<linux/usb.h>
struct usb_device {
  int devnum; /* Address on USB bus */
  char devpath [16];   
  /* Use in messages: /port/port/... */
  enum usb_device_state   state;
  enum usb_device_speed   speed; 
  ...
  unsigned int toggle[2];
  /* 每个端口一位:([0] = IN, [1] = OUT) */
  struct usb_device *parent;
  struct usb_bus *bus;
  struct usb_host_endpoint ep0;
  struct device dev;
  struct usb_device_descriptor descriptor;
  struct usb_host_config *config;
/*config的数量在device_des~的bNumConfigurations*/
  struct usb_host_config *actconfig;
  /*usb_host_config包含usb_interface的指针*/
  struct usb_host_endpoint *ep_in[16];
  struct usb_host_endpoint *ep_out[16];
  ...
#ifdef CONFIG_USB_DEVICE_CLASS
  struct device *usb_classdev;
#endif
#ifdef CONFIG_USB_DEVICEFS
  struct dentry *usbfs_dentry;
#endif
  struct usb_device *children[USB_MAXCHILDREN];
  ...
};

<linux/usb/ch9.h>
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
USB_DT_DEVICE_SIZE  18

usb_interface和usb_device具有父子关系：
#define interface_to_usbdev(intf) \
        container_of(intf->dev.parent, struct usb_device, dev)

*设备通常有一个或多个配置(config)
*配置通常有一个或多个接口(interface)
*接口通常有一个或多个设置(setting)
*接口没有或者有一个以上的端点(endpoint)

结构体间的关系：
(1)usb_device->actconfig
指向usb_host_config(对应config);

(2)usb_host_config->interface
指向usb_interface的指针数组(对应interface)

(3)usb_interface->cur_altsetting
指向usb_host_interface(对应setting);

(4)usb_host_interface->endpoint
指向usb_host_endpoint的数组，数组长度保存在desc.bNumEndpoint(对应endpoint);

(5)usb_host_endpoint
包含和本端点相关的urb的链表头urb_list(对应urb);



5.在用户空间获得usb信息
---------------------------
如果内核支持usbfs，那么在/proc/bus/usb中会有当前系统usb设备的一些信息；如果内核支持sysfs，则在/sys下会有相应内容。

(1)usbfs
usbfs缺省mount到/proc/bus/usb目录下。实现代码在linux/drivers/usb/core/inode.c中。
/proc/bus/usb下文件的说明和操作方式，请参考Documentations/usb/proc_usb_info.txt。
其中devices文件是ascii形式的信息，而001/002形式的文件是二进制信息，还可以通过ioctl操作。支持的IOCTL命令在<linux/usbdevice_fs.h>，参考linux/drivers/usb/core/devio.c。
ioctl命令需要在驱动usb_driver中提供ioctl函数支持，一般只有集线器需要。


(2)lsusb
使用lsusb-v命令，可以查看当前系统usb设备描述符的详细信息，前提是必须支持usbfs。
查看文件/usr/share/usb.ids，列出了目前支持的usb设备的vendor，product，interface等信息。在该文件的最后，还列出了标准usb设备类的class，subclass，protocol等信息。

(3)sysfs
在/sys下，无论是物理usb设备(usb_device)还是单独的usb接口(usb_interface)，在sysfs中均表示为单独的设备。
而usb主控制器对应usb总线。
以usb鼠标为例，我机器上的目录为：
$>ls /sys/devices/pci0000:00/0000:00:04.2/usb1/1-2/1-2:1.0
目录说明：
(1)0000:00:04.2
是usb主机控制器所对应的pci设备号
(2)usb1
是该控制器的根集线器编号，同时也是usb总线的编号
(3)1-2
设备名，1是该设备所在的集线器编号，2是设备所插入的端口号
(4)1-2:1.0
接口名。1-2是设备名，1.0为配置1，接口0

总之，在sysfs中usb设备的命名为：
  根集线器-集线器端口号:配置.接口
如果有多级的usb集线器，则为：
  根集线器-集线器端口号-集线器端口号:配置.接口


(4)sysfs下的usb主控制器(PCI信息)
我机器的usb主控制器在/sys下的内容如下：
$>ls /sys/devices/pci0000:00/0000:00:04.3
...
irq         (12)
class       (0x0c0300)
vendor      (0x1106)                
device      (0x3038)
local_cpus  (1)
resource
resource4
pools
usb_host:usb_host2@ (指向class/usb_host/usb_host2/)
driver@
(指向/bus/pci/drivers/uhci_hcd/) 
usb2/  (包含了usb总线2下的设备)

$>cat pools
poolinfo - 0.1
uhci_qh            12   42   96  1
uhci_td             2   85   48  1
buffer-2048         0    0 2048  0
buffer-512          0    0  512  0
buffer-128          0    0  128  0
buffer-32           1  128   32  1

$>cat uevent
DRIVER=uhci_hcd
PHYSDEVBUS=pci
PHYSDEVDRIVER=uhci_hcd
PCI_CLASS=C0300
PCI_ID=1106:3038
PCI_SUBSYS_ID=0925:1234
PCI_SLOT_NAME=0000:00:04.3
MODALIAS=pci:v00001106d00003038sv00000925sd00001234bc0Csc03i00


(5)sysfs下的usb总线(host控制器信息)
$>ls /sys/devices/pci0000:00/0000:00:04.3/usb2
...
bcdDevice           (0206)
bConfigurationValue (1,可写入以改变配置)
bDeviceClass        (09)
bDeviceProtocol     (00)
bDeviceSubClass     (00)
bmAttributes        (e0)
bMaxPacketSize0     (64)
bMaxPower           (0mA)
bNumConfigurations  (1)
bNumInterfaces      (1)
busnum              (2)
dev                 (189:128)
devnum              (1)
idProduct           (0000)
idVendor            (0000)
manufacturer        (Linux 2.6.24 uhci_hcd)
maxchild            (2,4端口hub为4)
product             (UHCI Host Controller)
quirks              (0x0)
serial              (0000:00:04.3)
speed               (12)
urbnum              (73)
version             (1.10,高速host为2.0)
driver@             (/bus/usb/drivers/usb/)
subsystem@          (bus/usb/)
ep_00@  
(/class/usb_endpoint/usbdev2.1_ep00/)
usb_device:usbdev2.1@ 
(/class/usb_device/usbdev2.1/)
usb_endpoint:usbdev2.1_ep00@
(/class/usb_endpoint/usbdev2.1_ep00/)
2-0:1.0/            (根hub的接口)           
2-1/                (总线下的设备)


(6)根hub接口
$>ls .../usb2/2-0:1.0
bAlternateSetting   (0)
bInterfaceClass     (09)
bInterfaceNumber    (00)
bInterfaceProtocol  (00)
bInterfaceSubClass  (00)
bNumEndpoints       (01)
uevent
bus@    (/bus/usb)
driver@ (/bus/usb/drivers/hub)
ep_81@  (/class/usb_endpoint/usbdev2.1_ep81)
usb_endpoint:usbdev2.1_ep81@
(/class/usb_endpoint/usbdev2.1_ep81)

$>cat uevent
DEVTYPE=usb_interface
DRIVER=hub
PHYSDEVBUS=usb
PHYSDEVDRIVER=hub
DEVICE=/proc/bus/usb/002/001
PRODUCT=0/0/206
TYPE=9/0/0
INTERFACE=9/0/0
MODALIAS=usb:v0000p0000d0206dc09dsc00dp00ic09isc00ip00


(7)USB总线下的设备
$>ls .../0000:00:04.3/usb2/2-1
...
bcdDevice           (0400)
bConfigurationValue (1)
bDeviceClass        (00)
bDeviceProtocol     (00)
bDeviceSubClass     (00)
bmAttributes        (a0)
bMaxPacketSize0     (8)
bMaxPower           (44mA)
bNumConfigurations  (1)
bNumInterfaces      (1)
busnum              (2)
dev                 (189:129)
devnum              (2)
idProduct           (6001)
idVendor            (0403)
manufacturer        (FTDI)
maxchild            (0)
product             (USB Serial Converter)
quirks              (0x0)
serial              (FTDGF9E4)
speed               (12)
uevent
urbnum              (11)
version             (1.10)
bus@    /bus/usb/
driver@ /bus/usb/drivers/usb/
(定义在usb/generic.c中的usb_device_driver，对应usb设备的驱动)
ep_00@  /class/usb_endpoint/usbdev2.2_ep00/
usb_device:usbdev2.2@ /class/usb_device/usbdev2.10/
usb_endpoint:usbdev2.2_ep00@ /class/usb_endpoint/usbdev2.2_ep00/
2-1:1.0/  (2-1设备下的接口0)

$>cat uevent
MAJOR=189
MINOR=129
DEVTYPE=usb_device
DRIVER=usb
PHYSDEVBUS=usb
PHYSDEVDRIVER=usb
DEVICE=/proc/bus/usb/002/02
PRODUCT=403/6001/400
TYPE=0/0/0
BUSNUM=002
DEVNUM=02


(8)设备中的接口
$>ls 0000:00:04.3/usb2/2-1/2-1:1.0
...
bAlternateSetting   (0)
bInterfaceClass     (ff)
bInterfaceNumber    (00)
bInterfaceProtocol  (ff)
bInterfaceSubClass  (ff)
bNumEndpoints       (02)
interface           (USB Serial Converter) 
bus@      /bus/usb
driver@   /bus/usb/drivers/ftdi_sio
ep_02@    /class/usb_endpoint/usbdev2.2_ep02
ep_81@    /class/usb_endpoint/usbdev2.2_ep81
ttyUSB0/  (和usb接口相关的具体设备的内容)


(9)USB串口设备(ttyUSB0)
event_char    (write only)
latency_timer (16)
port_number   (0)
uevent
bus@         /bus/usb-serial/
driver@      /bus/usb-serial/drivers/ftdi_sio/
subsystem@   /bus/usb-serial/
tty:ttyUSB0@ /class/tty/ttyUSB0/

$>cat uevent
DRIVER=ftdi_sio
PHYSDEVBUS=usb-serial
PHYSDEVDRIVER=ftdi_sio



6.usb设备文件和/sys/class
-------------------------------
(1)usb主设备号
<linux/usb.h>
#define USB_MAJOR          180
#define USB_DEVICE_MAJOR   189

(2)usb设备文件
在/dev下，可以找到采用189作为主设备号的设备，如：
usbdev1.1   189, 0    (usb主控制器1，对应总线1)
usbdev1.2   189, 1    (鼠标，接在host1上)
usbdev2.1   189, 128  (usb主控制器2，对应总线2)
usbdev2.2   189, 129  (usb转串口设备，接在host2上)

这些设备文件由udevd创建，其设备号来源于/sys/class/usb_device。
$>tree /sys/class/usb_device
|-- usbdev1.1
|   |-- dev   (189:129)
|   |-- device -> ../../../devices/pci0000:00/0000:00:04.2/usb1
|   |-- power
|   |   `-- wakeup
|   |-- subsystem -> ../../../class/usb_device
|   `-- uevent
|-- usbdev1.2
|-- usbdev2.1
`-- usbdev2.2
...

其中uevent文件的内容是：
$>cat uevent
MAJOR=189
MINOR=129
PHYSDEVPATH=/devices/pci0000:00/0000:00:04.3/usb2/2-1
PHYSDEVBUS=usb
PHYSDEVDRIVER=usb


(3)端点文件
在/dev下，可以找到采用254作为主设备号的usb端点设备，254应该是由系统自动分配的，如：
usbdev1.1_ep00  254, 0
usbdev1.1_ep81  254, 1
usbdev1.2_ep00  254, 4
usbdev1.2_ep81  254, 5
usbdev2.1_ep00  254, 2
usbdev2.1_ep81  254, 3
usbdev2.2_ep00  254, 6
usbdev2.2_ep02  254, 8
usbdev2.2_ep81  254, 7

这些设备文件由udevd创建，其设备号来源于/sys/class/usb_endpoint，该目录下共8个子目录，对应8个端点:
$>ls /sys/class/usb_endpoint/usbdev2.2_ep02
bEndpointAddress  (02)
bInterval         (00)
bLength           (07)
bmAttributes      (02)
dev               (254:8)
direction         (out)
interval          (0ms)
subsystem@        (/class/usb_endpoint)
type              (Bulk)
uevent
wMaxPacketSize    (0040)

$>cat uevent
MAJOR=254
MINOR=8
PHYSDEVPATH=/devices/pci0000:00/0000:00:04.3/usb2/2-1/2-1:1.0
PHYSDEVBUS=usb
PHYSDEVDRIVER=ftdi_sio


  

=========================
    URB (usb请求块)
=========================
USB驱动程序通过urb(usb请求块)和usb设备通信，urb和skbuff以及kiocb很象。设备驱动可以为一个端点分配多个urb，也可以为不同的端点重用同一个urb。设备中的每个端点都可以处理一个urb队列。

urb的典型生命周期如下：
*由USB驱动程序创建
*分配给一个特定usb设备的特定端点
*由USB驱动程序递交到USB核心
*由USB核心交到对应的USB主控制器驱动程序
*由主控制器传输数据
*当urb结束后，由USB主控制器驱动通知设备驱动

1.urb定义
------------------------
<linux/usb.h>
struct urb {
  struct kref kref;
  void *hcpriv; 
  atomic_t use_count;
  ...
  struct usb_device *dev;
  struct usb_host_endpoint *ep;
  unsigned int pipe; /*用指定函数进行设置*/
  int status; /*(return)non-ISO status */
  
  unsigned int transfer_flags;
  void *transfer_buffer;
  dma_addr_t transfer_dma;
  int transfer_buffer_length;
  int actual_length;(return)
  
  unsigned char *setup_packet;
  /* (in) setup packet (control only) */
  dma_addr_t setup_dma;
  /* (in) dma addr for setup_packet */
  int start_frame; 
        
  int number_of_packets;
  /* (in) number of ISO packets */
  int interval;
  /* (modify)transfer interval(INT/ISO) */
  int error_count;
  /* (return) number of ISO errors*/

  void *context; 
  /* (in) context for completion */
  usb_complete_t complete;
  /* (in) completion routine */
  struct usb_iso_packet_descriptor iso_frame_desc[0]; /* (in) ISO ONLY */
};

参数说明：
(1)struct usb_device *dev (in)
urb要发送到的usb设备

(2)unsigned int pipe (in)
urb要发送到的pipe信息，包括设备号，端点号，传输方向，端点类型等，在驱动中采用如下宏初始化：
unsigned int usb_sndctrlpipe(struct usb_device *dev, unsigned int endpoint);
上面的宏用于初始化一个控制OUT端点。dev中包含了usb设备号，endpoint从interface信息获得。驱动将宏的返回值赋给urb->pipe即可
类似的宏还包括：
usb_rcvctrlpipe(dev,endpoint)
usb_sndisocpipe()
usb_rcvisocpipe()
usb_sndbulkpipe()
usb_rcvbulkpipe()
usb_sndintpipe()
usb_rcvintpipe()

(3)int status (return)
对于非ISOC的urb，status中记录了urb的当前状态，驱动可以在urb的结束回调函数中访问该值。有效值包括：
0: urb传输成功
-ENOENT：urb被usb_kill_urb调用终止
-EPROTO, -EILSEQ, -EOVERFLOW:
设备，设备的固件或者电缆发生了硬件故障
还有其他一些值，参见第三版P336-337，这些错误值定义在asm-generic/errno.h和asm-generic/errno-base.h中

(4)unsigned int transfer_flags (in)
urb的传输类型。可以设置为URB_SHORT_NOT_OK等。可用的标记定义在usb.h

(5)void *transfer_buffer; (in)
收发缓冲区指针，必须通过kmalloc创建

(6)dma_addr_t transfer_dma; (in)
是transfer_buffer的DMA地址

(7)int transfer_buffer_length; (in)
缓冲区长度。对于out端点，该值可以大于设备端点所允许的最大值，HCD会将urb中的大数据块分割非小块传输。不必提交一系列缓冲区小的urb

(8)int actual_length; (return)
urb完成后，返回的实际数据长度

(9)unsigned char *setup_packet; (in)
   dma_addr_t setup_dma; (in)
用于控制urb的数据区。该区中的数据在transfer_buffer前面传送

(10)int start_frame; (modify)
    int number_of_packets; (in)
    int interval; (modify)
    int error_count; (return)
都是针对等时传输(ISO)和中断传输的

(11)void *context; (in)
    usb_complete_t complete;
当urb完全传输或发生错误时，usb核心调用complete函数。context类似于file->private_data，在回调函数中可以用urb->context获得设备结构体
typedef void (*usb_complete_t)(struct urb *);

(12)struct usb_iso_packet_descriptor iso_frame_desc[0];
针对等时urb。是等时数据包的数组，可以在单个urb中定义许多等时传输，还可用于收集单个传输的状态
struct usb_iso_packet_descriptor {
  unsigned int offset;
  unsigned int length;/*expected length*/
  unsigned int actual_length;
  int status;
};



2.创建和销毁urb
------------------------
urb必须采用动态创建和销毁。
(1)分配urb <linux/usb.h>
struct urb *
usb_alloc_urb(int iso_packets, gfp_t mem_flags);
如果不创建等时urb，iso_packets为0；mem_flags传递给kmalloc，失败返回NULL

(2)释放urb
void usb_free_urb(struct urb *urb);


3.初始化urb
------------------------
通过usb_alloc_urb后，需要对返回的urb进行初始化
(1)中断urb
static inline void 
usb_fill_int_urb (struct urb *urb,
     struct usb_device *dev,
     unsigned int pipe,
     void *transfer_buffer,
     int buffer_length,
     usb_complete_t complete_fn,
     void *context,
     int interval);
pipe必须要用前面的usb_sndintpipe等初始化；
transfer_buffer必须用kmalloc分配；

(2)批量urb
static inline void 
usb_fill_bulk_urb (struct urb *urb,
    struct usb_device *dev,
    unsigned int pipe,
    void *transfer_buffer,
    int buffer_length,
    usb_complete_t complete_fn,
    void *context);

(3)控制urb
static inline void 
usb_fill_control_urb (struct urb *urb,
    struct usb_device *dev,
    unsigned int pipe,
    unsigned char *setup_packet,
    void *transfer_buffer,
    int buffer_length,
    usb_complete_t complete_fn,
    void *context);
setup_packet: 设置数据包的数据

(4)等时urb
没有相应的初始化函数，需要手工初始化。例如：
  urb->dev = dev;
  urb->context = uvd;
  urb->pipe = usb_rcvisocpipe(dev, uvd->video_endp-1);
  urb->interval = 1;
  urb->transfer_flags = URB_ISO_ASAP;
  urb->transfer_buffer = cam->sts_buf[i];
  urb->complete = koni_isoc_irq;
  urb->number_of_packets = FRAMES;
  urb->transfer_buffer_len = ...;
  for(j=0; j<FRAMES_PER_DESC; j++) {
    urb->iso_frame_desc[j].offset = j;
    urb->iso_frame_desc[j].length = 1;
  }


 
4.提交urb
------------------------
urb初始化完成后，就可以提交给usb核心了：
(1)提交
int usb_submit_urb(struct urb *urb, gfp_t mem_flags);
成功返回0；
mem_flags可以取GFP_ATOMIC,GFP_NOIO,GFP_KERNEL

(2)回调函数
如果usb_submit_urb调用成功，当urb结束时正好调用一次回调函数。

(3)取消urb
int usb_kill_urb(struct urb *);
int usb_unlink_urb(struct urb *);
kill用于终止一个urb的生命周期，通常在disconnet中调用；
unlink不等urb真正完结就返回，因此调用不会导致睡眠。
