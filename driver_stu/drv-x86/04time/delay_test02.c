/************************
 * 基于睡眠的延迟例子
 * schedule_timeout
 * author: zht
 * date: 2012-08-24
 ************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/time.h>
#include <linux/delay.h>


static int 
proc_delay_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	struct timeval tval1, tval2;
	int ret = 0;

	/* get current time */
	do_gettimeofday(&tval1);

	/* delay 3s */
	//set_current_state(TASK_INTERRUPTIBLE);
	set_current_state(TASK_UNINTERRUPTIBLE);
	schedule_timeout(3*HZ);

	do_gettimeofday(&tval2);

	/* show the time */
	ret += sprintf(page+ret, "-----Current Time-----\n");
	ret += sprintf(page+ret, "timeval  = %lds : %ldus\n", tval1.tv_sec, tval1.tv_usec);

	ret += sprintf(page+ret, "-----Delay 3s-----\n");
	ret += sprintf(page+ret, "timeval  = %lds : %ldus\n", tval2.tv_sec, tval2.tv_usec);

	return ret;
}


static int __init my_init(void)
{
	create_proc_read_entry("proc_delay02", 0,
		NULL, proc_delay_read, NULL);

	return 0;
}

static void __exit my_exit(void)
{
	remove_proc_entry("proc_delay02", NULL);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

