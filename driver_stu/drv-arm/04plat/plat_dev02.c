/**************************
 * 针对4412内部的ChipID的例子
 * 准备并注册platform_device
 * Author: zht
 * Date: 2015-04-27
 **************************/
#include <linux/module.h>
#include <linux/platform_device.h>
#include <mach/irqs.h>

//定义设备的物理信息
#define DEV_BASE	0x10000000
#define DEV_SIZE	0x8

//定义设备的名字和ID
#define DEV_NAME	"猪八戒"
#define DEV_ID		(-1)

//准备资源数组
static struct resource dev_res[] = {
	//[0] = DEFINE_RES_MEM(),
	//[1] = DEFINE_RES_IRQ(),
	[0] = {
		.start = DEV_BASE,
		.end = DEV_BASE+DEV_SIZE-1,
		.flags = IORESOURCE_MEM,
	},
};

//release函数，则pdev注销时调用
static void 
my_dev_release(struct device *tmp)
{
	struct platform_device *pdev = container_of(tmp, struct platform_device, dev);
	printk("Release %s-->%d\n", pdev->name, pdev->id);
}


//准备platform_device
//如果设备需要注销，需要提供device->release函数
static struct platform_device my_pdev = {
	.name = DEV_NAME,
	.id = DEV_ID,
	.num_resources = ARRAY_SIZE(dev_res),
	.resource = dev_res,
	.dev = {
		.release = my_dev_release,
	},
};

//在模块的入口中注册pdev，在出口中注销pdev
static int __init my_init(void)
{
	return platform_device_register(&my_pdev);
}

static void __exit my_exit(void)
{
	platform_device_unregister(&my_pdev);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

