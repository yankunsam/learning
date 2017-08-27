/*****************************
 * 准备adc设备的platform_device
 * Author: zht
 * Date: 2014-08-22
 *****************************/
#include <linux/module.h>
#include <linux/platform_device.h>
#include <mach/irqs.h>

#define ADC_BASE	0x126C0000
#define ADC_SIZE	0x20

static void adc_release(struct device *dev)
{
	printk("Release adc device\n");
}

static struct resource adc_res[] = {
	[0] = {
		.start = ADC_BASE,
		.end = ADC_BASE + ADC_SIZE - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = IRQ_ADC,
		.end = IRQ_ADC,
		.flags = IORESOURCE_IRQ,
	},
};

static struct platform_device adc_pdev = {
	.name = "up4412-adc",
	.id = -1,
	.num_resources = ARRAY_SIZE(adc_res),
	.resource = adc_res,
	.dev = {
		.release = adc_release,
	},
};

static int __init my_init(void)
{
	return platform_device_register(&adc_pdev);
}

static void __exit my_exit(void)
{
	platform_device_unregister(&adc_pdev);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

