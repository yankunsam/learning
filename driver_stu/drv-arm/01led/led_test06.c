/**************************
 * 用定时器来实现led灯的闪烁
 * 用gpio库操作led
 * 使用定时器来实现led灯的闪烁
 * Author: zht
 * Date: 2014-10-25
 **************************/
#include <linux/module.h>
#include <linux/slab.h> //kzalloc
#include <linux/timer.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/gpio.h> //gpio_to_irq
#include <plat/gpio-cfg.h>
#include <mach/gpio.h> //GPIO号

#define LED_MAJOR	75
#define LED_NUM		4

//4个led的GPIO号
#define LED0 		EXYNOS4X12_GPM4(0)
#define LED1 		EXYNOS4X12_GPM4(1)
#define LED2 		EXYNOS4X12_GPM4(2)
#define LED3 		EXYNOS4X12_GPM4(3)

//ioctl命令号
#define LED_TYPE	'L'
#define LED_START	_IOW(LED_TYPE,1,int)
#define LED_STOP	_IO(LED_TYPE,2)
#define LED_INTERVAL	_IOW(LED_TYPE,3,int)

static int led_gpios[] = {LED0, LED1, LED2, LED3};

struct led_priv {
	int led_num; //led灯的GPIO号
	struct timer_list led_timer;
	int interval;
	struct cdev led_cdev;
	int dev_id;
};
static struct led_priv *leds[LED_NUM];


//4个灯共用同一个定时器处理函数
static void
led_timer_func(unsigned long data)
{
	struct led_priv *tmp = (void *)data;
	int value = gpio_get_value(tmp->led_num);

	//切换LED灯的状态
	if (value)
		gpio_set_value(tmp->led_num, 0);
	else
		gpio_set_value(tmp->led_num, 1);
	
	//再次启动定时器
	mod_timer(&tmp->led_timer, jiffies+tmp->interval);
}


static int 
proc_led_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int i, ret = 0;

	ret += sprintf(page+ret, "----LED 0~%d states----\n", (LED_NUM-1));
	for (i=0; i<LED_NUM; i++) {
		ret += sprintf(page+ret, 
			"Led %d:%d: %s; %d ticks\n", 
			MAJOR(leds[i]->dev_id), 
			MINOR(leds[i]->dev_id), 
			(gpio_get_value(leds[i]->led_num) ? "off" : "on"), leds[i]->interval);
	}

	return ret;
}


static int 
led_open(struct inode *inode, struct file *filp)
{
	struct led_priv *tmp = container_of(inode->i_cdev, struct led_priv, led_cdev);

	filp->private_data = tmp;

	return 0;
}


static int 
led_release(struct inode *inode, struct file *filp)
{
	return 0;
}


static long 
led_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	struct led_priv *tmp = filp->private_data;

	switch (req) {
	case LED_START:	/* start flash */
	if (arg == 0 || arg > 10*HZ) {
		printk("Interval should be between 1~10*HZ ticks\n");
		break;
	}
	tmp->interval = (int)arg;
	mod_timer(&tmp->led_timer, jiffies+tmp->interval);
	break;
	
	case LED_STOP:	/* stop flash */
	del_timer(&tmp->led_timer);
	tmp->interval = 0;
	break;

	case LED_INTERVAL: /* new interval */
	if (arg == 0 || arg > 10000) {
		printk("Interval should be between 1~10000\n");
		break;
	}
	tmp->interval = (int)arg;
	break;

	default:
	printk("cannot support request: 0x%x\n", req);
	return -EFAULT;
	}

	return 0;
}


static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.open	= led_open,
	.release = led_release,
	.unlocked_ioctl = led_ioctl,
};


static int __init my_init(void)
{
	int i, ret = 0;

	//1.分配私有结构体并初始化定时器
	for (i=0; i<LED_NUM; i++) {
		leds[i] = (struct led_priv *)kzalloc(sizeof(*leds[i]), GFP_KERNEL);
		if (!leds[i]) {
			ret = -ENOMEM;
			goto err_alloc;
		}
		leds[i]->interval = 0;
		setup_timer(&leds[i]->led_timer,
			led_timer_func, 
			(unsigned long)leds[i]);
	}

	//2.初始化LED对应的IO
	for (i=0; i<LED_NUM; i++) {
		ret = gpio_request(led_gpios[i], "leds");
		if (ret) {
			printk("Cannot request gpio %d\n", led_gpios[i]);
			goto err_led;
		}
		s3c_gpio_cfgpin(led_gpios[i], S3C_GPIO_OUTPUT);
		gpio_set_value(led_gpios[i], 1);
		leds[i]->led_num = led_gpios[i];
	}

	//3.分配设备号并注册
	for (i=0; i<LED_NUM; i++) {
		leds[i]->dev_id = MKDEV(LED_MAJOR, i);
		cdev_init(&leds[i]->led_cdev, &led_fops);
		cdev_add(&leds[i]->led_cdev, leds[i]->dev_id, 1);
	}

	//4.创建proc文件
	create_proc_read_entry("led_timer", 0, NULL,
		proc_led_read, NULL);

	return 0;
err_led:
	for (i=0; i<LED_NUM; i++) {
		if (leds[i]->led_num)
			gpio_free(leds[i]->led_num);
	}
err_alloc:
	for (i=0; i<LED_NUM; i++) {
		kfree(leds[i]);
	}
	return ret;
}


static void __exit my_exit(void)
{
	int i;
	for (i=0; i<LED_NUM; i++) {
		del_timer(&leds[i]->led_timer);
		cdev_del(&leds[i]->led_cdev);
		gpio_free(leds[i]->led_num);
		kfree(leds[i]);
	}
	remove_proc_entry("led_timer", NULL);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

