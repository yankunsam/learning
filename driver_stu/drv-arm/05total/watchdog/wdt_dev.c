/***************************
 * 看门狗的platform_device
 * Author: zht
 * Date: 2014-11-11
 ***************************/
#include <linux/module.h>
#include <linux/platform_device.h>
#include <mach/irqs.h>

//定义看门狗的物理地址信息
#define WDT_BASE 	0x10060000
#define WDT_SIZE	0x10

//准备资源数组，用于描述硬件信息
static struct resource wdt_res[] = {
	[0] = {
		.start = WDT_BASE,
		.end = WDT_BASE + WDT_SIZE - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = IRQ_WDT,
		.end = IRQ_WDT,
		.flags = IORESOURCE_IRQ,
	},
};

//准备release函数
static void wdt_release(struct device *tmp)
{
	struct platform_device *pdev = container_of(tmp, struct platform_device, dev);
	printk("Release %s:%d\n", pdev->name, pdev->id);
}

//准备platform_device
static struct platform_device wdt_pdev = {
	.name = "up4412-wdt",
	.id = -1,
	.num_resources = ARRAY_SIZE(wdt_res),
	.resource = wdt_res,
	.dev = {
		.release = wdt_release,
	},
};

static int __init my_init(void)
{
	//注册platform_device
	return platform_device_register(&wdt_pdev);
}

static void __exit my_exit(void)
{
	//注销platform_device
	platform_device_unregister(&wdt_pdev);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

