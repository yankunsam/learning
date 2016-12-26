/**********************
 * 第一个模块的例子
 * Author: zht
 * Date: 2015-04-15
 **********************/
#include <linux/module.h>
#include <linux/sched.h>

//模块的入口函数，在insmod时调用
static int __init my_init(void)
{
	printk("Hi, kernel, loops_per_jiffy = %ld\n", loops_per_jiffy);
	return 0;
}

//模块的出口函数，在rmmod时调用
static void __exit my_exit(void)
{
	printk("Au revoir\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

