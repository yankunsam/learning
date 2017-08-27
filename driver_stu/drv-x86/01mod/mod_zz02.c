/*********************
 * 导出符号的测试例子
 * 用EXPORT_SYMBOL导出模块中的变量或函数
 * Author: zht
 * Date: 2015-04-15
 *********************/
#include <linux/module.h>

//如果.c文件编译进zImage，那么static的作用成立
int value_a = 10;
EXPORT_SYMBOL(value_a);

void func_a(int tmp)
{
	printk("In zz02.c-->func_a, tmp = %d, value_a = %d\n", tmp, value_a);
}
EXPORT_SYMBOL(func_a);

static int __init my_init(void)
{
	return 0;
}

static void __exit my_exit(void)
{}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");




