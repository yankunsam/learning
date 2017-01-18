#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include "/home/sam/fork/linux/fs/proc/internal.h"
#include <linux/seq_file.h>
#include <asm/uaccess.h>
struct proc_dir_entry *proc_entry;
static int proc_show(struct seq_file *seq, void *offset)
{
	seq_printf(seq,"hello\n");
	return 0;
}
int proc_open(struct inode *inode, struct file *file)
{
	single_open(file,proc_show,NULL);
	return 0;
}
static const  struct file_operations proc_fops = {
	.owner = THIS_MODULE,
	.read = seq_read,
	.open = proc_open,
	//.release = single_release,
	.release = NULL,
};
static int __init hello_init(void)
{
	printk("hello,I am coming\n");
    pr_info("hello\n");
	proc_entry = proc_create("sam_rm",0,NULL,&proc_fops);
	return 0;

}
static void __exit hello_exit(void)
{
	proc_remove(proc_entry);
	printk("hello,I am leaving\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sam");
