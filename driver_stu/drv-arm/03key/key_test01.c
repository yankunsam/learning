/************************
 * 按键的测试例子1
 * 测试中断的注册/注销
 * 测试中断的触发模式(沿或电平)
 * 测试中断的disable/enable
 * Author: zht
 * Date: 2015-04-23
 *************************/
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/gpio.h> //gpio_to_irq
#include <mach/gpio.h> //gpio号

#define KEY_NUM	4
#define KEY1 gpio_to_irq(EXYNOS4_GPX3(2))
#define KEY2 gpio_to_irq(EXYNOS4_GPX3(3))
#define KEY3 gpio_to_irq(EXYNOS4_GPX3(4))
#define KEY4 gpio_to_irq(EXYNOS4_GPX3(5))


//按键的计数
static int irq1_cnt, irq2_cnt;
static int irq_disabled;

//按键1的中断处理，可以用沿触发
static irqreturn_t
key1_service(int irq, void *dev_id)
{
	printk("key1 %d: %d times\n", \
		irq, ++irq1_cnt);
	return IRQ_HANDLED;
}

//按键2的中断处理，可以用电平触发
static irqreturn_t
key2_service(int irq, void *dev_id)
{
	printk("key2 %d: %d times\n", \
		irq, ++irq2_cnt);
	return IRQ_HANDLED;
}

//按键3的处理，按键后disable按键2
static irqreturn_t
key3_service(int irq, void *dev_id)
{
	disable_irq(KEY2);
	printk("key2 disabled %d times\n", \
		++irq_disabled);
	return IRQ_HANDLED;
}

//按键4的处理，按下后enable按键2
static irqreturn_t
key4_service(int irq, void *dev_id)
{
	if (irq_disabled == 0)
		return IRQ_NONE;

	enable_irq(KEY2);
	printk("key2 disabled %d times\n", \
		--irq_disabled);
	return IRQ_HANDLED;
}

static int __init my_init(void)
{
	int ret, flags;

	//注册key1的中断
	flags = IRQF_TRIGGER_RISING | \
			IRQF_TRIGGER_FALLING;
	ret = request_irq(KEY1,
			key1_service, flags,
			"mykey1", NULL);
	if (ret) {
		printk("Cannot request irq %d\n", KEY1);
		return ret;
	}

	//注册key2的中断
	flags = IRQF_TRIGGER_LOW;
	ret = request_irq(KEY2,
			key2_service, flags,
			"mykey2", NULL);
	if (ret) {
		free_irq(KEY1, NULL);
		printk("Cannot request irq %d\n", KEY2);
		return ret;
	}

	//注册key3的中断
	flags = IRQF_TRIGGER_FALLING;
	ret = request_irq(KEY3,
			key3_service, flags,
			"mykey3", NULL);
	if (ret) {
		free_irq(KEY2, NULL);
		free_irq(KEY1, NULL);
		printk("Cannot request irq %d\n", KEY3);
		return ret;
	}

	//注册key4的中断
	flags = IRQF_TRIGGER_FALLING;
	ret = request_irq(KEY4,
			key4_service, flags,
			"mykey4", NULL);
	if (ret) {
		free_irq(KEY3, NULL);
		free_irq(KEY2, NULL);
		free_irq(KEY1, NULL);
		printk("Cannot request irq %d\n", KEY4);
		return ret;
	}
	
	return 0;
}

static void __exit my_exit(void)
{
		free_irq(KEY1, NULL);
		free_irq(KEY2, NULL);
		free_irq(KEY3, NULL);
		free_irq(KEY4, NULL);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

