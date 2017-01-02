#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include "/home/sam/fork/linux/fs/proc/internal.h"
#include <linux/seq_file.h>
#include <asm/uaccess.h>
struct proc_dir_entry *proc_entry;
struct proc_data{
	int i;
};

#if 1
ssize_t proc_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	//char data[3] ="s";
	signed char data = 'a';	
	//simple_read_from_buffer(buf, size, ppos, data, 3);
	copy_to_user(buf,&data,1);
	return 1;
}
#endif
static int proc_show(struct seq_file *seq, void *offset)
{
	seq_printf(seq,"hello\n");
	return 0;
}
int proc_open(struct inode *inode, struct file *file)
{
	struct proc_data meta;
	meta.i = 1;
	single_open(file,proc_show,NULL);
	return 0;
}
static struct file_operations proc_fops = {
	.read = seq_read,
	.open = proc_open,
};
static int __init hello_init(void)
{
	printk("hello,I am coming\n");
	proc_entry = proc_create("sam_rm",0,NULL,&proc_fops);
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
