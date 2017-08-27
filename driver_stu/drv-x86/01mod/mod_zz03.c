/*********************
 * 访问其他模块导出的符号
 * Author: zht
 * Date: 2015-04-15
 *********************/
#include <linux/module.h>

//要声明外部的变量或函数
extern int value_a;
extern void func_a(int);


static int __init my_init(void)
{
	printk("In zz03.c, call func_a()\n");
	func_a(50);
	printk("In zz03,c, set value_a\n");
	value_a = 23;
	printk("In zz03.c, call_func_a()\n");
	func_a(60);

	return 0;
}

static void __exit my_exit(void)
{}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");




