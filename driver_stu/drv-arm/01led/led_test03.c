/***********************
 * led的测试例子2
 * 用GPIO库接口来替代直接寄存器访问
 * 用miscdevice替代cdev向VFS注册
 * 用ioctl替代write来控制LED
 * Author: zht
 * Date: 2015-04-21
 ***********************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h> 
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio.h>

#define LED_NUM		4

//定义IOCTL命令号(参数为led的编号0~3)
#define LED_TYPE	'L'
#define LED_ON		_IOW(LED_TYPE, 1, int)
#define LED_OFF		_IOW(LED_TYPE, 2, int)
#define LED_SWAP	_IOW(LED_TYPE, 3, int)


//由于将4个led识别为一个设备，可以不用设计私有结构体，用全局变量即可

//声明gpio号的数组
static int led_gpios[LED_NUM] = {
	EXYNOS4X12_GPM4(0),
	EXYNOS4X12_GPM4(1),
	EXYNOS4X12_GPM4(2),
	EXYNOS4X12_GPM4(3),
};

//实现file_operations
//由于open/release函数直接返回0，因此可以不实现

//arg为要操作那个LED，范围从0～3
static long 
led_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	int ret;
	if (arg > 3) {
		printk("Only support led 0~3\n");
		return -1;

	switch (req) {
	case LED_ON:
		gpio_set_value(led_gpios[arg], 0);
		break;
	case LED_OFF:
		...;
	case LED_SWAP:
		...;
	default:
		printk("Cannot support ioctl 0x%x\n", req);
		return -1;
	}
	return 0;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = led_ioctl,
};

static struct miscdevice led_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "myleds",
	.fops = &led_fops,
};

static int __init my_init(void)
{
	//以下执行4次
	//gpio_request(); 4个led可以叫相同的名字
	//s3c_gpio_cfgpin(); S3C_GPIO_OUTPUT
	//gpio_set_value(); 默认将led关闭
	
	//以下执行1次
	//create_proc_read_entry("gpio_led", ...);
	//ret = misc_register();
	return 0;
err:
	...;
}

static void __exit my_exit(void)
{
	//以下执行1次
	//remove_proc_entry();
	//misc_deregister();
	//以下执行4次
	//gpio_free();
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");
