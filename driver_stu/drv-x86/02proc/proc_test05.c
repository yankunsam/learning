/************************
 * 用seq_file接口改造proc_test03.c
 * Author: zht
 * Date: 2014-08-08
 ************************/
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

struct proc_head {
	struct list_head head;
	int file_size;
};

struct proc_item {
	struct list_head item;
	char *str;
};

static struct proc_head *mylist;


/************************
 * seq_operations->show
 ************************/
static int 
my_seq_show(struct seq_file *m, void *v)
{
	struct proc_item *tmp;

	list_for_each_entry(tmp, &mylist->head, item) {
		seq_printf(m, "%s", tmp->str);
	}
	seq_printf(m, "file has %d bytes\n", mylist->file_size);

	return 0;
}


/*************************
 * file_operations->open
 *************************/
static int 
my_seq_open(struct inode *inode, struct file *file)
{
        return single_open(file, my_seq_show, NULL);
}


/*************************
 * file_operations->write
 *************************/
static ssize_t 
my_seq_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	struct proc_item *tmp;

	//为proc_item及字符串分配空间
	tmp = (struct proc_item *)kzalloc(sizeof(*tmp), GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	tmp->str = (char *)kzalloc(count+1, GFP_KERNEL);
	if (!tmp->str) {
		kfree(tmp);
		return -ENOMEM;
	}
	if (copy_from_user(tmp->str, buf, count)) {
		kfree(tmp->str);
		kfree(tmp);
		return -EFAULT;
	}
	
	INIT_LIST_HEAD(&tmp->item);
	list_add_tail(&tmp->item, &mylist->head);
	mylist->file_size += count;

	return count;
}


static struct file_operations my_seq_fops = {
	.owner 	= THIS_MODULE,
        .open	= my_seq_open,
	.release = single_release,
        .read	= seq_read,
	.write	= my_seq_write,
        .llseek	= seq_lseek,
};


static int __init my_init(void)
{
	struct proc_dir_entry *file;

	//分配并初始化链表头
	mylist = (struct proc_head *)kzalloc(sizeof(*mylist), GFP_KERNEL);
	if (!mylist)
		return -ENOMEM;
	mylist->file_size = 0;
	INIT_LIST_HEAD(&mylist->head);

	/* create /proc/abc_seq */
	file = proc_create("abc_seq", 0666,
		NULL, &my_seq_fops);
	if (!file) {
		kfree(mylist);
		printk("Cannot create /proc/abc_seq\n");
		return -1;
	}

	return 0;
}


static void __exit my_exit(void)
{
	struct proc_item *tmp1, *tmp2;

	remove_proc_entry("abc_seq", NULL);	
	list_for_each_entry_safe(tmp1, tmp2, &mylist->head, item) {
		list_del(&tmp1->item);
		kfree(tmp1->str);
		kfree(tmp1);
	}
	kfree(mylist);
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHANG");

