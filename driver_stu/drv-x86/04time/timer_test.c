/*****************************
 * timer_list的测试例子
 * 通过读/proc/proc_timer文件来启动一个定时器
 * 设定定时器循环执行500次
 * Author: zht
 * Date: 2014-08-14
 *****************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/timer.h> /* timer_list */
#include <linux/smp.h>

#define DEF_INTERVAL 	(HZ/10) /* 循环间隔的ticks */
#define DEF_TIMES	500 /* 循环500次 */

static struct timer_list mytimer;
static int interval; //循环的间隔
static int times; //剩余的执行次数


//定时器的执行函数
//由硬件定时器的中断处理函数调用
static void 
timer_func(unsigned long data)
{
	int cpu = smp_processor_id();

	printk("Timer %d: in cpu %d, " \
		"task is %s, pid is %d\n", \
		times, cpu, current->comm, current->pid);

	if (times-- > 1) {
		//mod_timer(&mytimer, jiffies + interval);
		mytimer.expires = jiffies + interval;
		add_timer(&mytimer);
	}
}


/************************
 * 当用户态用cat读proc文件时，启动timer_list
 * cat启动timer后，马上退出，不会等待到timer执行完
 ************************/
int proc_timer(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;

	//如果times当前为0，则启动定时器
	if (!times) {
		times = DEF_TIMES;
		mod_timer(&mytimer, jiffies + interval);
		ret += sprintf(page+ret, "Start timer in %ld, execute %d times\n", jiffies, times);
	} else {
		ret += sprintf(page+ret, "Timer still running, please try again\n");
	}

	return ret;
}


static int __init my_init(void)
{
	//1.初始化定时和相关变量
	interval = DEF_INTERVAL;
	times = 0;
	setup_timer(&mytimer, timer_func, 0);

	//2.创建proc文件
	create_proc_read_entry("proc_timer", 0, 
		NULL, proc_timer, NULL);

	return 0;
}


static void __exit my_exit(void)
{
	remove_proc_entry("proc_timer", NULL);
	del_timer(&mytimer);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

