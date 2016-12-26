/************************
 * 模块参数的测试例子
 * Author: zht
 * Date: 2015-04-16
 ************************/
#include <linux/module.h>

static int abc = 5;
module_param(abc, int, 0644);

static char *name = "shrek";
module_param(name, charp, 0444);

static int test = 0;
module_param(test, bool, 0644);

static int sizes[] = {10, 20, 30, 40};
module_param_array(sizes, int, NULL, 0644);


static int __init my_init(void)
{
	int i = 0;
	printk("===In init()===\n");
	printk("abc = %d; name is %s; test = %d\n", \
		abc, name, test);

	for (i=0; i<ARRAY_SIZE(sizes); i++)
		printk("sizes[%d] = %d\n", i, sizes[i]);

	return 0;
}

static void __exit my_exit(void)
{
	int i;
	printk("===In exit()===\n");
	printk("abc = %d; name is %s; test = %d\n", \
		abc, name, test);
	for (i=0; i<ARRAY_SIZE(sizes); i++)
		printk("sizes[%d] = %d\n", i, sizes[i]);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

