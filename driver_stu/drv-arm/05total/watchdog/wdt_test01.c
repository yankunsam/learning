/*************************
 * 看门狗的完整char驱动
 * 支持用write和ioctl来控制狗
 * 如：echo on|off|feed >/dev/wdt0；或者写ioctl命令
 * 用request_mem_region/ioremap直接访问寄存器
 * 用miscdevice注册
 * 支持中断处理函数(要清空状态寄存器)
 * 支持proc函数，获取设备工作信息
 * 支持锁保护(用spinlock_t或mutex)
 * 用platform_driver进行封装
 * Author: zht
 * Date: 2014-11-11
 **************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include <linux/spinlock.h> //mutex
#include <linux/delay.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/clk.h> //clk
#include "regs-wdt.h"

//定义默认的喂狗间隔时间(秒)和模式
#define MODE_IRQ	1
#define MODE_RESET	2
#define WDT_DEF_MODE	MOD_IRQ
#define WDT_DEF_TIME	10

//定义ioctl命令号
//CHGTIME命令的参数为新的间隔秒数
#define WDT_TYPE	'W'
#define WDT_ON		_IO(WDT_TYPE, 1)
#define WDT_OFF		_IO(WDT_TYPE, 2)
#define WDT_FEED	_IO(WDT_TYPE, 3)
#define WDT_CHGTIME	_IOW(WDT_TYPE, 4, int)
#define WDT_CHGMODE	_IOW(WDT_TYPE, 5, int)

//定义狗相关的变量
static int wdt_base;
static int wdt_size;
static struct resource *wdt_res;
static void __iomem *vir_base;
static int wdt_irq;

static int wdt_time; //当前的喂狗间隔秒数
static int wdt_cnt; //当前的间隔计数
static int wdt_mode; //当前的模式
static spinlock_t wdt_lock;
static struct clk *wdt_clk; //狗的时钟结构体

//proc文件的读函数
static int
wdt_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	//显示狗当前寄存器的值
	//显示wdt_time等变量的当前值
	//显示。。。
	return ret;
}

//狗的中断处理函数
static irqreturn_t
wdt_service(int irq, void *dev_id)
{
	//printk("I'm hungry...\n");
	//可选：可以通过led,buzzer等通知用户没有喂狗
	//清空WTCLRINT状态寄存器

	return IRQ_HANDLED;
}

//准备file_operations
//为了避免多个人同时控制看门狗，在write/ioctl中应该加入锁保护
//由于write和ioctl中的一些工作是重复的，建议写几个独立的函数，完成喂狗，使能，关闭等工作
//wdt_start
//wdt_stop
//wdt_feed
//wdt_set_time
//wdt_set_mode

static ssize_t
wdt_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	char tmp[10] = {0};
	//copy_from_user获取用户态的命令
	//支持echo on|off|feed命令
	//if (strncmp(tmp, "on", 2) == 0)
	//	...
	//else if (strncmp(tmp, "off", 3) == 0)
	//	...
	//	...

	return count;
}

static long
wdt_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	int ret;

	//先持有锁
	switch (req) {
	case WDT_ON:
		...;
		break;
	case WDT_OFF:
		...;
		break;
	...
	default:
		printk("Cannot support ioctl 0x%x\n", req);
	}

	return 0;
}

static struct file_operations wdt_fops = {
	.owner = THIS_MODULE,
	.write = wdt_write,
	.unlocked_ioctl = wdt_ioctl,
};

static struct miscdevice wdt_misc = {
	.minor = MISC_DYNAMIC_MINOR, 
	.name = "wdt0",
	.fops = wdt_fops,
};

//准备platform_driver
static int
wdt_probe(struct platform_device *pdev)
{
	int ret = 0, freq;
	struct resource *res1, *res2;

	//1.从pdev中获得硬件信息
	res1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res1 || !res2) {
		printk("%s: Cannot get enough resources\n", pdev->name);
		return -EIO;
	}

	//2.看门狗的IO初始化
	wdt_base = res1->start;
	wdt_size = res1->end - res1->start + 1;
	wdt_res = request_mem_region(wdt_base, wdt_size, "wdt-io");
	if (!wdt_res) {
		printk("%s: cannot request mem region\n", pdev->name);
		return -EIO;
	}

	vir_base = ioremap(wdt_base, wdt_size);
	if (!vir_base) {
		printk("%s: cannot ioremap\n", pdev->name);
		ret = -EIO;
		goto err_map;
	}

	//3.找到并使能看门狗的时钟
	//三星在移植linux时，为所有的4412内部外设都准备了一个clk结构体，其中包含了和设备时钟相关的信息。驱动利用名字匹配用clk_get函数来获得该结构体的指针。
	//4412大部分外设的时钟都定义在arch/arm/mach-exynos/clock-exynos4.c中
	wdt_clk = clk_get(&pdev->dev, "watchdog");
	if (IS_ERR(wdt_clk)) {
		printk("%s: cannot get watchdog clock\n", pdev->name);
		ret = PTR_ERR(wdt_clk);
		goto err_clk;
	}
	clk_enable(wdt_clk);
	freq = clk_get_rate(wdt_clk);
	printk("%s: clock rate is %dHZ\n", freq);

	//4.初始化其他的全局变量，并设置看门狗的寄存器
	spin_lock_init(&wdt_lock);
	wdt_time = WDT_DEF_TIME;
	wdt_mode = WDT_DEF_MODE;
	//初始化看门狗的相关寄存器...	
	wdt_cnt = ...;

	//5.注册中断处理函数
	wdt_irq = res2->start;
	ret = request_irq(wdt_irq, 
		wdt_service, 0,
		"wdt-irq", 
		vir_base);
	if (ret) {
		printk("%s: cannot request irq %d\n", wdt_irq);
		goto err_irq;
	}

	//6.创建proc文件
	create_proc_read_entry(
		"wdt_info", 0, NULL, 
		wdt_proc_read, NULL);

	//7.注册miscdevice
	ret = misc_register(&wdt_misc);
	if (ret) {
		printk("%s: cannot register miscdevice\n", pdev->name);
		goto err_misc;
	}

	//8.如果上述全部成功，则驱动准备就绪，最后打印一下成功信息
	printk("...");

	return 0;
err_misc:
	free_irq(wdt_irq, vir_base);
err_irq:
	clk_disable(wdt_clk);
	clk_put(wdt_clk);
err_clk:
	iounmap(vir_base);
err_map:
	release_mem_region(wdt_base, wdt_size);
	return ret;
}


static int
wdt_remove(struct platform_device *pdev)
{
	free_irq(wdt_irq, vir_base);
	misc_deregister(&wdt_misc);
	remove_proc_entry("wdt_info", NULL);
	clk_disable(wdt_clk);
	clk_put(wdt_clk);
	iounmap(vir_base);
	release_mem_region(wdt_base, wdt_size);
	return 0;
}

//准备要支持的设备列表
static struct platform_device_id wdt_ids[] = {
	{"up4412-wdt", 0},
	{"up6410-wdt", 0},
	{"up2440-wdt", 0},
	{}
};

static struct platform_driver wdt_pdrv = {
	.probe = wdt_probe,
	.remove = wdt_remove,
	.id_table = wdt_ids,
	.driver = {
		.name = "mywdt-drv",
	},
};

static int __init my_init(void)
{
	//注册platform_driver
	return platform_driver_register(&wdt_pdrv);
}

static void __exit my_exit(void)
{
	//注销platform_driver
	platform_driver_unregister(&wdt_pdrv);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

