/****************************
 * 可调电阻(模拟温度传感器)的char驱动
 * 使用三星提供的通用adc接口
 * Author: zht
 * Date: 2014-08-22
 ****************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/time.h>
#include <linux/proc_fs.h>
#include <linux/platform_device.h>
#include <plat/adc.h>

#define ADC_MAX_CH	4

struct adc_info {
	int ch;
	int value;
	int time;
};

//定义ioctl命令号，
#define TYPE_ADC	'A'
#define GET_ADC_VALUE	_IOW(TYPE_ADC, 1, struct adc_info)

//将4个adc通道识别为一个设备，不必使用私有结构体
struct s3c_adc_client *client;

static long
adc_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	struct adc_info tmp;
	struct timeval tval;

	if (copy_from_user(&tmp, (void *)arg, sizeof(tmp)))
		return -EFAULT;

	if (tmp.ch >= ADC_MAX_CH) {
		printk("Only support %d channels\n", ADC_MAX_CH);
		return -1;
	}

	tmp.value = s3c_adc_read(client, tmp.ch);
	if (tmp.value < 0) {
		printk("adc read error\n");
		return -1;
	}

	do_gettimeofday(&tval);
	tmp.time = tval.tv_sec;
	if (copy_to_user((void *)arg, &tmp, sizeof(tmp)))
		return -EFAULT;

	return 0;
}

static struct file_operations adc_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = adc_ioctl,
};

static struct miscdevice adc_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "adc",
	.fops = &adc_fops,
};

static int
adc_probe(struct platform_device *pdev)
{
	int ret;

	//1.注册adc_client
	//参数2/3为两个函数指针，参数4为0则说明是普通AD
	client = s3c_adc_register(pdev, NULL, NULL, 0);
	if (IS_ERR(client)) {
		printk("adc: Cannot register adc_client\n");
		return PTR_ERR(client);
	}

	//2.注册miscdevice
	ret = misc_register(&adc_misc);
	if (ret) {
		printk("adc: Cannot register misc_device\n");
		return ret;
	}

	return 0;
}

static int
adc_remove(struct platform_device *pdev)
{
	misc_deregister(&adc_misc);
	return 0;
}

static struct platform_device_id adc_ids[] = {
	{"up4412-adc", 0},
	{"up6410-adc", 0},
	{}
};

static struct platform_driver adc_pdrv = {
	.probe = adc_probe,
	.remove = adc_remove,
	.driver = {
		.name = "adc-driver01",
	},
	.id_table = adc_ids,
};

static int __init my_init(void)
{
	return platform_driver_register(&adc_pdrv);
}

static void __exit my_exit(void)
{
	platform_driver_unregister(&adc_pdrv);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

