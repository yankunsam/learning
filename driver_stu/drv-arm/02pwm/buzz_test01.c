/**************************
 * 用于控制buzzer开关的char驱动
 * buzzer用GPD0_0引脚控制开关，"echo on|off"
 * Author: zht
 * Date: 2014-03-26
 **************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>

#include <linux/gpio.h>
#include <mach/gpio.h>
#include <plat/gpio-cfg.h>

//buzzer连接到4412的GPD0_0引脚
#define BUZZ_GPIO	EXYNOS4_GPD0(0)
#define DEVICE_NAME	"buzz"

//buzzer的当前状态(0:off; 1:on)
static int buzz_state;

static int
buzz_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	ret += sprintf(page, "=====Buzz control=====\n");
	ret += sprintf(page+ret, "Use GPD0_0(%d) control buzz\n", BUZZ_GPIO);
	ret += sprintf(page+ret, "Buzzer now %s\n", buzz_state ? "on" : "off");

	return ret;
}


static ssize_t 
buzz_write(struct file *file, const char *buf, size_t count, loff_t *f_pos)
{
	char *tmp = kzalloc(count, GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	if (copy_from_user(tmp, buf, count)) {
		kfree(tmp);
		return -EFAULT;
	}

	if (strncmp(tmp, "on", 2) == 0) {
		buzz_state = 1;
		gpio_set_value(BUZZ_GPIO, buzz_state);
	} 
	else if (strncmp(tmp, "off", 3) == 0) {
		buzz_state = 0;
		gpio_set_value(BUZZ_GPIO, buzz_state);
	}
	else {
		printk("Please use on|off\n");
		return -1;
	}

	kfree(tmp);
	return count;
}

static struct file_operations buzz_fops = {
	.owner = THIS_MODULE,
	.write = buzz_write,
};

static struct miscdevice buzz_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &buzz_fops,
};

static int __init my_init(void)
{
	int ret;

	//请求buzzer的GPIO
	ret = gpio_request(BUZZ_GPIO, "Buzzer");
	if (ret) {
		printk("request GPIO %d for buzzer failed, ret = %d\n", BUZZ_GPIO, ret);
		return ret;
	}

	//将Buzzer的GPIO设定为输出，默认关闭
	s3c_gpio_cfgpin(BUZZ_GPIO, S3C_GPIO_OUTPUT);
	buzz_state = 0;
	gpio_set_value(BUZZ_GPIO, buzz_state);

	//注册misc设备
	ret = misc_register(&buzz_misc);
	if (ret) {
		printk("4412: Cannot register miscdevice for Buzzer\n");
		gpio_free(BUZZ_GPIO);
		return ret;
	}

	//创建proc文件
	create_proc_read_entry("buzz_info", 0, NULL, buzz_proc_read, NULL);
	printk("zht4412: buzzer initialized\n");
	return 0;
}


static void __exit my_exit(void)
{
	remove_proc_entry("buzz_info", NULL);
	misc_deregister(&buzz_misc);
	gpio_free(BUZZ_GPIO);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

