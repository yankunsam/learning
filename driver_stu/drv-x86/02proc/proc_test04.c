/*************************
 * 使用seq_file接口实现可读写的proc文件
 * 功能同proc_test02.c
 * Author: zht
 * Date: 2014-08-08
 *************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
//new
#include <linux/fs.h> //file_operations
#include <linux/seq_file.h>

static char *str = NULL;

/*********************
 * seq_operations->show
 * 必须返回0，否则什么也显示不出来
 *********************/
static int 
my_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "current kernel time is %ld\n", jiffies);
	seq_printf(m, "str is %s\n", str);

	return 0;
}

/***********************
 * file_operations->open
 ***********************/
static int 
my_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, my_proc_show, NULL);
}

/************************
 * file_operations->write
 ************************/
static ssize_t 
my_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos)
{
	char *tmp = kzalloc((count+1), GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	if (copy_from_user(tmp,buffer,count)) {
		kfree(tmp);
		return -EFAULT;
	}

	kfree(str);
	str = tmp;

	return count;
}

static struct file_operations my_fops = {
	.owner	= THIS_MODULE,
	.open	= my_proc_open,
	.release = single_release,
	.read	= seq_read,
	.llseek	= seq_lseek,
	.write 	= my_proc_write,
};

static int __init my_init(void)
{
	struct proc_dir_entry* file;

	//创建proc文件并关联file_operations
	file = proc_create("abc_rw", 0644, NULL, &my_fops);
	if (!file)
	    return -ENOMEM;

	return 0;
}

static void __exit my_exit(void)
{
	remove_proc_entry("abc_rw", NULL);
	kfree(str);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("aran");
MODULE_LICENSE("GPL");
