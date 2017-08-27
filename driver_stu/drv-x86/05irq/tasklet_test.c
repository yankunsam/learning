/****************************
 * tasklet下半部的测试
 * 将原来在中断处理函数中完成的工作，拆分成两部分进行
 * 本例测试上下半部间的时间间隔
 * Author: zht
 * Date: 2014-08-18
 ****************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/time.h> //timespec
#include <linux/delay.h>
#include <linux/smp.h>

#define DEF_IRQ  12

//声明下半部的封装结构体以及记录上下半部信息的变量
static struct tasklet_struct mytask;
static struct timespec up_time, bo_time;
static int up_cnt, bo_cnt;
static int up_cpu, bo_cpu;


//下半部执行函数
static void 
bo_service(unsigned long data)
{
	int interval;

	getnstimeofday(&bo_time);
	interval = bo_time.tv_nsec - up_time.tv_nsec;
	bo_cpu = smp_processor_id();

	//mdelay(10);
	printk("Up %d cpu %d; Bo %d cpu %d; " \
		"%dns; %s\n", \
		up_cnt, up_cpu, ++bo_cnt, bo_cpu, \
		interval, current->comm);
}


//上半部执行函数
static irqreturn_t 
up_service(int irq, void *dev_id)
{
	up_cnt++;
	up_cpu = smp_processor_id();
	getnstimeofday(&up_time);

	/* 触发下半部 */
	//tasklet_schedule(&mytask);
	tasklet_hi_schedule(&mytask);

	return IRQ_HANDLED;
}


static int __init my_init(void)
{
	int ret;

	//初始化tasklet
	tasklet_init(&mytask, bo_service, 0);

	//注册中断处理函数
	ret = request_irq(DEF_IRQ, up_service, \
		IRQF_SHARED, \
		"mytasklet", &mytask);
	if (ret) {
		printk("Cannot request irq %d\n", DEF_IRQ);
		return ret;
	}

	return 0;
}

static void __exit my_exit(void)
{
	free_irq(DEF_IRQ, &mytask);
	tasklet_kill(&mytask);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

