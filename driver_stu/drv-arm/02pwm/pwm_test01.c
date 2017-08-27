/*********************
 * pwm的测试例子1
 * 针对pwm0，连接开发板上的Buzzer
 * 使用gpio库来配置IO引脚GPD0_0
 * 使用pwm库来设置定时器time0
 * Author: zht
 * Date: 2015-04-21
 *********************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>
#include <linux/pwm.h>
#include <linux/gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio.h>

#define PWM_IO	EXYNOS4_GPD0(0) //GPIO号
#define PWM_ID	0  //0号通道

//定义ioctl号，使能/关闭/改变频率/改变占空比等
#define PWM_TYPE	'P'
#define PWM_ON
#define PWM_OFF
#define PWM_FREQ_UP
#define PWM_FREQ_DOWN
...

static int freq_cur = 0;
static int duty_cur = 0;
static struct pwm_device *dev;

//用proc文件显示当前的状态

//用ioctl来实现PWM控制
static long
pwm_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	//使用pwm_enable/pwm_disable/pwm_config
	//使能，关闭，改变频率等
}

static struct file_operations pwm_fops = {
	...
};

static struct miscdevice pwm_misc = {
	.minor = ...,
	.name = "mypwm",
	.fops = &pwm_fops,
};

static int __init my_init(void)
{
	//首先配置gpio
	//gpio_request
	//s3c_gpio_cfgpin(); 配置为pwm输出
	//接下来申请pwm通道
	//dev = pwm_request(PWM_ID, ...);
	//创建proc文件
	//misc_register();
	return 0;
}

static void __exit my_exit(void)
{
	//misc_deregister();
	//remove_proc_entry();
	//pwm_free();
	//gpio_free();
}


}







