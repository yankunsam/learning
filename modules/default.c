#include <linux/module.h>
static int __init hello_init(void)
{
    pr_info("hello\n");
	return 0;

}
static void __exit hello_exit(void)
{
	printk("hello,I am leaving\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sam");
