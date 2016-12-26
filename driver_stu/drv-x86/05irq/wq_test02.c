/**************************
 * 工作队列的测试例子2
 * 创建一组自己的内核线程abc/x来执行下半部
 * Author: zht
 * Date: 2014-11-20
 **************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/time.h>
#include <linux/smp.h>

#define DEF_IRQ 	12

//声明新的工作队列
static struct workqueue_struct *new_queue;

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

	//唤醒默认的内核线程执行下半部
	//或唤醒给定cpu上的内核线程执行下半部
	queue_work(new_queue, &mywork);
	//queue_work_on(1, new_queue, &mywork);

	return IRQ_HANDLED;
}


static int __init my_init(void)
{
	int ret;

	//创建新的工作队列
	//参数为新建内核线程的前缀
	new_queue = create_workqueue("abc");
	if (!new_queue) {
		printk("Cannot create new workqueue\n");
		ret = -1;
		goto err_wq;
	}

	//初始化work_struct
	INIT_WORK(&mywork, bo_service);

	//注册中断处理函数
	ret = request_irq(DEF_IRQ, up_service, 
		IRQF_SHARED, "wq_test2", &mywork);
	if (ret) {
		printk("cannot request irq %d\n", DEF_IRQ);
		goto err_irq;
	}

	return 0;
err_irq:
	destroy_workqueue(new_queue);
err_wq:
	return ret;
}


static void __exit my_exit(void)
{
	free_irq(DEF_IRQ, &mywork);

	//刷新并销毁工作队列
	flush_workqueue(new_queue);
	destroy_workqueue(new_queue);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

