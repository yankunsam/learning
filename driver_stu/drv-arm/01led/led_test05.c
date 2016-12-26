/***********************
 * led的测试例子3
 * 将4个LED识别为4个设备
 * 每个设备可以按不同的频率闪烁
 * 每个设备都有自己的定时器，但是4个设备可以共用同一个定时器处理函数
 * 用gpio接口库来设置IO
 * 用cdev来注册设备
 * Author: zht
 * Date: 2015-04-22
 ************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/timer.h> //timer_list
#include <linux/gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio.h>

#define LED_MAJOR	75
#define LED_NUM		4

//定义ioctl号,参数为闪烁的间隔，以tick为单位
#define LED_TYPE	'L'
#define LED_START	_IOW(LED_TYPE, 1, int)
#define LED_STOP	_IO(LED_TYPE, 2)
#define LED_SET_INTERVAL _IOW(LED_TYPE, 3, int)

//由于一个驱动要支持多个设备，因此需要设计私有结构体
struct led_priv {
	int led_num; //gpio号
	int led_state; 
	struct timer_list led_timer;
	int interval; //定时器的运行间隔
	dev_t dev_id;
	struct cdev led_cdev;
};

//私有结构体的全局指针数组
static struct led_priv *leds[LED_NUM];

static int led_gpios[LED_NUM] = {
	EXYNOS4X12_GPM4(0),
	EXYNOS4X12_GPM4(1),
	EXYNOS4X12_GPM4(2),
	EXYNOS4X12_GPM4(3),
};

//proc文件的读函数
static int my_proc_read()
{
	显示4个led的当前状态，包括显示间隔等
}

//定时器的执行函数，由于每个timer_list到期后执行的行为类似，因此4个定时器可以共用同一个执行函数
static void led_timer_func(unsigned long data)
{
	struct led_priv *tmp = (void *)data;
	//利用data来区分不同的led_priv
	//切换对应led的状态
	//如果tmp->interval不为0，则重新启动定时器
	//mod_timer();
}

//准备file_operations
static int 
led_open(struct inode *inode, struct file *filp)
{
	struct led_priv *tmp = container_of(inode->i_cdev, struct led_priv, led_cdev);
	filp->private_data = tmp;
	return 0;
}

static long
led_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	//执行LED_START等命令
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.open = led_open,
	.unlocked_ioctl = led_ioctl,
};

static int __init my_init(void)
{
	//以下执行4次
	//分配并初始化led_priv
	//获得led的GPIO号，然后gpio_request
	//s3c_gpio_cfgpin
	//s3c_set_value
	//setup_timer();
	//分配设备号
	//cdev_add
	//以下执行1次
	//create_proc_read_entry();
}

static void __exit my_exit(void)
{
	//remove_proc_entry();
	//以下执行4次
	//del_timer();
	//cdev_del();
	//gpio_free();
	//kfree();
}







