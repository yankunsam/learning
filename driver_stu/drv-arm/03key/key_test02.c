/*************************
 * 用按键中断测试tasklet下半部
 * Author: zht
 * Date: 2015-04-24
 *************************/
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/time.h> //timeval & timespec
#include <linux/gpio.h>
#include <mach/gpio.h>

#define KEY_IRQ gpio_to_irq(EXYNOS4_GPX3(2))

//用于封装下半部函数的结构体
struct tasklet_struct mytask;
static int up_cnt = 0; //上半部的计数
static int bo_cnt = 0; //下半部的计数

//上半部的执行函数，用request_irq注册
static irqreturn_t 
up_service(int irq, void *dev_id)
{
	up_cnt++;
	tasklet_hi_schedule(&mytask);
	return IRQ_HANDLED;
}

//下半部的执行函数，在上半部中触发
static void
bo_service(unsigned long data)
{
	bo_cnt++;
	printk("UP %d; BO %d\n", up_cnt, bo_cnt);
}

static int __init my_init(void)
{
	int ret, flags;
	//1.初始化tasklet_struct
	tasklet_init(&mytask, bo_service, 0);

	//2.注册上半部
	flags = IRQF_TRIGGER_LOW;
	ret = request_irq(KEY_IRQ, up_service,
			flags, "mytasklet", NULL);
	if (ret) {
		printk("Cannot request irq %d\n", KEY_IRQ);
		return -1;
	}

	return 0;
}

static void __exit my_exit(void)
{
	free_irq(KEY_IRQ, NULL);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

