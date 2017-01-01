#include <linux/init.h>
#include <linux/module.h>

static int __init  hello_init(void)
{
	printk("hello,I am coming\n");
	return 0;

}
static void __exit hello_exit(void)
{
	printk("hello,I am leaving\n");
}
MODULE_LICENSE("Dual BSD/GPL");
module_init(hello_init);
module_exit(hello_exit);
