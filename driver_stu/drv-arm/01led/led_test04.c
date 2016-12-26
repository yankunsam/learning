/****************************
 * LED的char驱动2
 * (1)通过ioctl来控制led灯，4个灯组合成一个misc设备
 * (2)用miscdevice来替代cdev，可以自动生成/dev下的设备文件
 * (3)用linux专门提供的gpio库函数
 * Author: zht
 * Date: 2014-08-14
 ****************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>

#include <linux/gpio.h> //include/linux
#include <plat/gpio-cfg.h> //arch/arm/plat-samsung/include/plat
#include <mach/gpio.h>  //arch/arm/mach-exynos/include/mach

#define DEVICE_NAME "abc"

//on/off命令的参数为要控制哪个灯(0~3)
#define LED_TYPE	'L'
#define LED_ON		_IOW(LED_TYPE, 1, int)
#define LED_OFF		_IOW(LED_TYPE, 2, int)

static int led_gpios[] = {
	EXYNOS4X12_GPM4(0),
	EXYNOS4X12_GPM4(1),
	EXYNOS4X12_GPM4(2),
	EXYNOS4X12_GPM4(3),
};

#define LED_NUM		ARRAY_SIZE(led_gpios)

//proc的读函数
static int led_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int i, ret = 0;
	
	ret += sprintf(page, "=====LED 0~%d state=====\n", (LED_NUM-1));
	for (i=0; i<LED_NUM; i++) {
		ret += sprintf(page+ret, "LED%d : %s; gpio: %d\n", i, gpio_get_value(led_gpios[i]) ? "off" : "on", led_gpios[i]);
	}

	return ret;
}


/**************************
 * file_operations->unlocked_ioctl
 **************************/
static long 
up4412_leds_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	if (arg >= LED_NUM) 
		return -EINVAL;

	//1:灯灭; 0:灯亮
	switch (req) {
	case LED_ON:
		gpio_set_value(led_gpios[arg], 0);
		break;
	case LED_OFF:
		gpio_set_value(led_gpios[arg], 1);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static struct file_operations led_fops = {
	.owner		= THIS_MODULE,
	.unlocked_ioctl	= up4412_leds_ioctl,
};

//name是/dev/下设备文件的名字
static struct miscdevice up4412_led_dev = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &led_fops,
};


//fixme: 错误处理有问题
static int __init my_init(void) 
{
	int ret;
	int i;

	//依次为每个灯申请GPIO. 配置为输出，默认关灯
	for (i = 0; i < LED_NUM; i++) {
		ret = gpio_request(led_gpios[i], "myLED");
		if (ret) {
			printk("%s: request GPIO %d for LED failed, ret = %d\n", DEVICE_NAME, led_gpios[i], ret);
			return ret;
		}
		s3c_gpio_cfgpin(led_gpios[i], S3C_GPIO_OUTPUT);
		gpio_set_value(led_gpios[i], 1);
	}

	//注册led设备
	ret = misc_register(&up4412_led_dev);
	if (ret) 
		printk("%s init error\n", DEVICE_NAME);
	else 
		printk("%s init OK\n", DEVICE_NAME);

	//创建proc/leds_misc文件
	create_proc_read_entry("leds_misc", 0444, NULL, led_proc_read, NULL);

	return ret;
}

static void __exit my_exit(void) {
	int i;

	remove_proc_entry("leds_misc", NULL);
	misc_deregister(&up4412_led_dev);
	for (i = 0; i < LED_NUM; i++) {
		gpio_free(led_gpios[i]);
	}
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHT");

