/******************************
 * platform_driver的测试例子1
 * pdrv只是在原有驱动的外面增加了一个外壳，以前学过的东西不变
 * pdrv提供了和pdev直接的一些新的互动方法
 * 硬件信息来自于platform_device
 * Author: zht
 * Date: 2015-04-28
 *******************************/
#include <linux/module.h>
#include <linux/platform_device.h> //pdrv
//以前char驱动需要哪些头文件，都可以加上
//char驱动的核心头文件
#include <linux/fs.h>
#include <linux/cdev.h> //miscdevice.h
#include <linux/uaccess.h>
//proc文件的头文件
#include <linux/proc_fs.h>
//如果是3总线设备，且直接访问寄存器
#include <linux/ioport.h>
#include <linux/io.h>
//如果是用io库
#include <linux/gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio.h>
//如果使用pwm库
#include <linux/pwm.h>
//如果设备有中断或下半部，不用irqs.h
#include <linux/interrupt.h> //request_irq & tasklet_struct
#include <linux/workqueue.h> //work_struct
//如果使用定时器
#include <linux/timer.h> //timer_list
//如果代码运行中需要延迟
#include <linux/delay.h> //udelay & mdelay
#include <linux/wait.h> //wait_queue_head_t
//如果代码需要锁保护
#include <asm/atomic.h> //<linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>

//define一些常量，但是不应包括硬件信息
#define DEF_MAJOR	80

//如果驱动支持多个硬件，则应该定义私有结构体
//struct xx_priv { ... };

//如果支持proc文件，则提供proc的读写函数

//如果支持timer_list，则提供timer_func()

//如果支持中断，则提供irq_service()

//如果支持中断下半部，则提供tasklet或work_struct对应的函数

//如果是char驱动，则提供file_operations

//要提供有效的锁保护，访问硬件时，可以直接访问寄存器，也可以使用内核提供好的函数库

/*************************************/

//以下内容为新增，提供对platform_driver的支持

//取代了以前在my_init()中完成的工作
//probe函数只会初始化一个硬件
//当注册的pdev通过名字和pdrv匹配时，由设备模型相关代码负责调用probe函数一次
//如果有多个pdev和pdrv匹配，则probe调用多次
static int 
my_probe(struct platform_device *pdev)
{
	//将硬件信息从pdev中取出来打印
	struct resource *res;
	printk("===probe() %s:%d===\n", \
		pdev->name, pdev->id);

	//获得IO资源
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		printk("Cannot get IOMEM resource\n");
		return -1;
	}
	printk("MEM from 0x%x to 0x%x\n", \
		res->start, res->end);

	//获得中断资源
	res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res) 
		printk("No irq\n");
	else 
		printk("irq %d\n", res->start);

	return 0;
}

static int
my_remove(struct platform_device *pdev)
{
	printk("===remove() %s:%d===\n", \
		pdev->name, pdev->id);
	return 0;
}

//通过id数组，说明驱动可以支持哪些设备
static struct platform_device_id my_ids[] = {
	{ "孙悟空", 0},
	{ "猪八戒", 0},
	{ "沙和尚", 0},
	{ "白龙马", 0},
	{},
};

static struct platform_driver my_pdrv = {
	.probe = my_probe,
	.remove = my_remove,
	.driver = {
		.name = "西天旅游团",
	},
	.id_table = my_ids,
};

static int __init my_init(void)
{
	//如果有某些东西可以多个设备共享，比如proc文件，那么仍然在my_init中完成
	//注册platform_driver
	return platform_driver_register(&my_pdrv);
}

static void __exit my_exit(void)
{
	platform_driver_unregister(&my_pdrv);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

