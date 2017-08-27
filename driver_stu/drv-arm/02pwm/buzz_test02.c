/**************************
 * buzzer设备的char驱动
 * 蜂鸣器连接PWM0，对应的GPIO为GPD0_0
 * 改变PWM的频率可改变音调，改变占空比可改变音量(?)
 * Author: zht
 * Date: 2014-08-14
 **************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/pwm.h>
#include <linux/proc_fs.h>

#include <linux/gpio.h>
#include <mach/gpio.h>
#include <plat/gpio-cfg.h>

#define STEPS		500	//设定频率的步长

#define PWM_TYPE	'P'
#define PWM_START	_IO(PWM_TYPE, 1)
#define PWM_STOP	_IO(PWM_TYPE, 2)
#define PWM_SET_FREQ	_IOW(PWM_TYPE, 3, int)
#define PWM_SET_DUTY	_IOW(PWM_TYPE, 4, int)
#define PWM_HIGH	_IO(PWM_TYPE, 5) //改变频率
#define PWM_LOW		_IO(PWM_TYPE, 6)
#define PWM_UP		_IO(PWM_TYPE, 7) //改变占空比
#define PWM_DOWN	_IO(PWM_TYPE, 8)

#define DEVICE_NAME	"buzz"
#define PWM_ID		0 //pwm的通道号
#define PWM_GPIO	EXYNOS4_GPD0(0)
#define NS_IN_1S	(1000000000UL) //每秒含的ns数


static struct pwm_device *buzzer;
static int cur_freq = 1000;	//默认频率，范围从1到10000
static int cur_duty = 5;	//默认占空比为5/10，范围从0到10


//文件/proc/buzz_info的读函数
static int 
pwm_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	ret += sprintf(page, "===== Buzzer =====\n");
	ret += sprintf(page+ret, "GPIO: %d; freq = %d; duty = %d/10\n", PWM_GPIO, cur_freq, cur_duty);

	return ret;
}


/*********************
 * 启动PWM
 *********************/
static void buzz_start(void) 
{
	int period_ns = NS_IN_1S / cur_freq;

	//设定GPIO为pwm输出
	s3c_gpio_cfgpin(PWM_GPIO, S3C_GPIO_SFN(2));

	//配置pwm的占空比和频率; 使能pwm
	pwm_config(buzzer, period_ns*cur_duty/10, period_ns);
	pwm_enable(buzzer);
}


/*****************
 * 停止PWM
 *****************/
static void buzz_stop(void) 
{
	//设定GPIO为输出
	s3c_gpio_cfgpin(PWM_GPIO, S3C_GPIO_OUTPUT);

	pwm_config(buzzer, 0, NS_IN_1S/cur_freq);
	pwm_disable(buzzer);
}


/******************
 * 设定PWM的频率
 ******************/
static void buzz_set_freq(int freq) 
{
	int period_ns = NS_IN_1S / freq;

	cur_freq = freq;
	pwm_config(buzzer, period_ns*cur_duty/10, period_ns);
}


/*******************
 * 设定PWM的占空比
 *******************/
static void buzz_set_duty(int duty)
{
	int period_ns = NS_IN_1S / cur_freq;

	cur_duty = duty;
	pwm_config(buzzer, period_ns*cur_duty/10, period_ns);
}


/***********************
 * file_operations->unlocked_ioctl
 ***********************/
static long 
buzz_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	int val;

	switch (req) {
	case PWM_START:
		buzz_start();
		break;
	case PWM_STOP:
		buzz_stop();
		break;
	case PWM_SET_FREQ:
		if (arg <= 0 || arg > 10000)
			return -EINVAL;
		buzz_set_freq(arg);
		break;
	case PWM_SET_DUTY:
		if (arg < 0 || arg > 10)
			return -EINVAL;
		buzz_set_duty(arg);
		break;
	case PWM_HIGH:
		val = cur_freq + STEPS;
		if (val > 10000)
			val = 10000;
		buzz_set_freq(val);
		break;
	case PWM_LOW:
		val = cur_freq - STEPS;
		if (val <= 0)
			val = 1;
		buzz_set_freq(val);
		break;
	case PWM_UP:
		val = cur_duty + 1;
		if (val > 10)
			val = 10;
		buzz_set_duty(val);
		break;
	case PWM_DOWN:
		val = cur_duty - 1;
		if (val < 0)
			val = 0;
		buzz_set_duty(val);
		break;
	default:
		printk("Cannot support ioctl 0x%x\n", req);
		return -EINVAL;
	}

	return 0;
}


static struct file_operations buzz_ops = {
	.owner		= THIS_MODULE,
	.unlocked_ioctl	= buzz_ioctl,
};

static struct miscdevice buzz_misc = {
	.minor 		= MISC_DYNAMIC_MINOR,
	.name 		= DEVICE_NAME,
	.fops 		= &buzz_ops,
};

static int __init my_init(void) 
{
	int ret;

	//1.申请和BUZZER连接的GPIO
	ret = gpio_request(PWM_GPIO, DEVICE_NAME);
	if (ret) {
		printk("request GPIO %d for buzzer(pwm) failed\n", PWM_GPIO);
		return ret;
	}

	//2.GPIO默认为输出0
	s3c_gpio_cfgpin(PWM_GPIO, S3C_GPIO_OUTPUT);
	gpio_set_value(PWM_GPIO, 0);

	//3.申请PWM通道(根据电路图，buzzer连接pwm0，因此申请的通道号为0)
	//返回一个pwd_device结构体的指针
	buzzer = pwm_request(PWM_ID, DEVICE_NAME);
	if (IS_ERR(buzzer)) {
		printk("request pwm %d for %s failed\n", PWM_ID, DEVICE_NAME);
		ret = PTR_ERR(buzzer);
		goto pwm_err;
	}

	//4.默认关闭PWM
	buzz_stop();

	//5.创建文件/proc/buzz_info
	create_proc_read_entry("buzz_info", 0, NULL, pwm_proc_read, NULL);

	//6.注册misc设备
	ret = misc_register(&buzz_misc);
	if (ret) {
		printk("=====%s: register error=====\n", DEVICE_NAME);
		goto misc_err;
	}
	else {
		printk("=====%s: register OK=====\n", DEVICE_NAME);
	}

	return 0;
misc_err:
	remove_proc_entry("buzz_info", NULL);
	pwm_free(buzzer);
pwm_err:
	gpio_free(PWM_GPIO);
	return ret;
}


static void __exit my_exit(void) 
{
	remove_proc_entry("buzz_info", NULL);
	misc_deregister(&buzz_misc);
	buzz_stop();
	pwm_free(buzzer);
	gpio_free(PWM_GPIO);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHT");

