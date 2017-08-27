/************************
 * 工作队列的测试1(work queue)
 * 在events/x内核线程中执行下半部工作
 * 在工作队列的下半部执行函数中可以睡眠
 * Author: zht
 * Date: 2014-11-20
 ************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/time.h>
#include <linux/smp.h>

#define DEF_IRQ 	12

//声明工作的封装结构体和其他变量
static struct work_struct mywork;
static struct timespec up_time, bo_time;
static int up_cnt, bo_cnt;
static int up_cpu, bo_cpu;


//下半部执行函数
static void 
bo_service(struct work_struct *data)
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

	//默认情况下，上下半部在同一cpu上执行
	//可以唤醒给定cpu上的events/x线程执行下半部
	//schedule_work(&mywork);
	schedule_work_on(0, &mywork);

	return IRQ_HANDLED;
}


static int __init my_init(void)
{
	int ret;

	//初始化工作队列
	INIT_WORK(&mywork, bo_service);

	ret = request_irq(DEF_IRQ, up_service, 
		IRQF_SHARED, "wq_test1", &mywork);
	if (ret) {
		printk("cannot request irq %d\n", DEF_IRQ);
		return ret;
	}
		
	return 0;
}


static void __exit my_exit(void)
{
	free_irq(DEF_IRQ, &mywork);
	flush_scheduled_work();
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHANG");
MODULE_LICENSE("GPL");

