/****************************
 * led的测试例子1
 * 直接访问寄存器(ioremap/readl/writel)；
 * 将4个led灯识别为4个设备(/dev/led0, led1...)；
 * 用$>echo on|off|swap >/dev/led0 来控制设备
 * 用proc文件来获取灯的当前状态
 * Author: zht
 * Date: 2015-04-20
 *****************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define LED_MAJOR	70
#define LED_NUM		4

//定义LED的物理信息
#define GPIO_BASE	0x11000000
#define GPIO_SIZE	0x1000
#define GPM4CON		0x2E0
#define GPM4DAT		0x2E4


//定义私有结构体
struct led_priv {
	int led_num; //0~3,可以用于寄存器偏移
	int led_state; //on:1; off:0
	struct cdev led_cdev;
	dev_t dev_id;
};
static struct led_priv *leds[LED_NUM];

//四个led灯使用相同的寄存器，因此只要ioremap一次
static void __iomem *vir_base;


//proc文件的读函数
static int 
led_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	//显示4个led的设备号，以及对应的状态
}

//准备file_operations
static int
led_open(struct inode *inode, struct file *filp)
{
	//找到要操作的灯对应的led_priv
	//将led_priv存入filp->private_data;
	return 0;
}

static int
led_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static ssize_t
led_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct led_priv *priv;
	char tmp[10] = {0};
	int value;
	//用户态用echo on|off的方式来控制led的亮灭
	//在write中，首先要copy_from_user(tmp,buf,3);
	//用strncmp对tmp中的字符串进行比较
	//如果为"on"，则点亮对应的led，需要设置GPM4DAT寄存器的特定bit位，不能影响其他的bit位
	//对寄存器的操作经常用读--修改--写
	//点亮Led需要将对应的bit位清零
	//value = readl(vir_base+GPM4DAT);
	//value &= ~(1 << priv->led_num);
	//writel(value, (vir_base+GPM4DAT));
	//如果为"off"，则关闭对应的led
	//value |= (1 << priv->led_num);
	//如果为"swap"，则反转led的当前状态
	//value ^= (1 << priv->led_num);
	//更新priv->led_state;

	return count;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.open = led_open,
	.release = led_release,
	.write = led_write,
};

static int __init my_init(void)
{
	//以下操作执行1次
	//vir_base = ioremap(GPM_BASE, GPM_SIZE);
	//create_proc_read_entry();

	//以下操作执行4次
	//为私有结构体分配空间
	//leds[i] = kzalloc();
	//初始化led_num和led_state成员
	//要把led对应的GPIO设置为输出：
	//value = readl(vir_base+GPM4CON);
	//value &= ~(0xF << leds[i]->led_num*4);
	//value |= (0x1 << leds[i]->led_num*4);
	//writel(value, (vir_base+GPM4CON);
	//为led分配设备号
	//cdev_init & cdev_add
	//注意错误处理

	return 0;
}

static void __exit my_exit(void)
{
	//以下执行一次
	//remove_proc_entry();
	//iounmap();
	//以下执行4次
	//cdev_del();
	//kfree();
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

