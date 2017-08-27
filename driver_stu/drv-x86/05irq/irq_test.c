/************************
 * 打开/proc/interrupts文件
 * 找到一个经常发生中断的设备，然后注册中断处理函数
 * Author: zht
 * Date: 2014-07-15
 ***********************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/interrupt.h>

//笔记本上的12号中断一般对应ps2鼠标/触摸板/轨迹球
#define IRQ_TEST	12

static int irq_cnt = 0;

//中断处理函数
static irqreturn_t 
irq_service(int irq, void *dev_id)
{
	irq_cnt++;
	printk("IRQ %d: %d times, %s:%d\n", \
		irq, irq_cnt, current->comm, current->pid);

	return IRQ_HANDLED; //IRQ_NONE
}

static int __init my_init(void)
{
	int ret = 0;
	unsigned long flags = IRQF_SHARED;

	ret = request_irq(IRQ_TEST,
		irq_service,
		flags,
		"myirq",
		&irq_cnt);
	if (ret) {
		printk("Cannot request irq %d\n", IRQ_TEST);
		return -1;
	}	

	return 0;
}

static void __exit my_exit(void)
{
	free_irq(IRQ_TEST, &irq_cnt);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

