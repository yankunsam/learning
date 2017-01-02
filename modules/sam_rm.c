#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include "/home/sam/fork/linux/fs/proc/internal.h"
struct proc_dir_entry *proc_entry;

#if 1
ssize_t proc_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	char data[20] ="sam";
	simple_read_from_buffer(buf, size, ppos, data, 3);

	return 0;
}
#endif
static struct file_operations proc_fops = {
.read = proc_read,
};
static int __init  hello_init(void)
{
	printk("hello,I am coming\n");
	proc_entry = proc_create("sam_rm",777,NULL,&proc_fops);
	proc_entry->proc_fops = &proc_fops;
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
