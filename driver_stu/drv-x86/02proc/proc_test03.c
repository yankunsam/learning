/*****************************
 * proc文件和list_head的测试例子
 * 用链表将echo的多个字符串存储在一起
 * 在3.10内核以后，proc文件的读写接口被取消，内核换用seq_file来实现proc文件的读写
 * 参考proc_test04.c
 * Author: zht
 * Date: 2015-04-16
 *****************************/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/list.h>

//定义链表的头结构体，只会分配一个
struct proc_head {
	//最好加一把锁，spinlock_t lock;
	struct list_head head;
	int file_size; //记录所有字符串的总大小
};

//定义链表的数据结构体，用户态每次echo都会分配一个
struct proc_item {
	char *str;
	struct list_head item;
};

//声明一个全局的链表头
static struct proc_head mylist;


//proc文件的读函数
static int my_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	struct proc_item *tmp;
	//遍历链表，将每个字符串的内容写入page
	//可以用list_for_each或list_for_each_entry遍历
	//将字符串的总大小mylist.file_size也写入page
	ret = sprintf(page, "file_size = %d bytes\n", mylist.file_size);
	list_for_each_entry(tmp, &mylist.head, item) {
		ret += sprintf(page+ret, "%s", tmp->str);
	}

	return ret;
}

//proc文件的写函数，每次echo时调用
static int my_proc_write(struct file *filp, const char __user *buf, unsigned long count, void *data)
{
	struct proc_item *tmp;

	//分配proc_item以及对应的字符串空间
	tmp = (struct proc_item *)kzalloc(sizeof(*tmp), GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;
	tmp->str = (char *)kzalloc(count+1, GFP_KERNEL);
	if (!tmp->str) {
		kfree(tmp);
		return -ENOMEM;
	}

	//从用户态拷贝数据，并初始化list_head
	if (copy_from_user(tmp->str, buf, count)) {
		kfree(tmp->str);
		kfree(tmp);
		return -EFAULT;
	}
	INIT_LIST_HEAD(&tmp->item);

	//将新的成员加入链表(或list_add_tail)
	//更新proc_list->file_size
	list_add_tail(&tmp->item, &mylist.head);
	mylist.file_size += count;

	return count;
}

static int __init my_init(void)
{
	struct proc_dir_entry *file;

	//初始化链表头
	mylist.file_size = 0;
	INIT_LIST_HEAD(&mylist.head);

	//创建proc文件并关联读写接口
	file = create_proc_entry("abc_list",
			0644, NULL);
	if (!file) {
		printk("Cannot create /proc/abc_list\n");
		return -1;
	}
	file->read_proc = my_proc_read;
	file->write_proc = my_proc_write;
	return 0;
}

static void __exit my_exit(void)
{
	//然后再删除proc文件，首先释放链表
	//remove_proc_entry
	//list_for_each_entry_safe(pos, n, ...) {
	//	list_del(pos);
	//	kfree(pos->str);
	//	kfree(pos);
	//}
	struct proc_item *tmp, *n;
	remove_proc_entry("abc_list", NULL);
	list_for_each_entry_safe(tmp, n, &mylist.head, item) {
		list_del(&tmp->item);
		kfree(tmp->str);
		kfree(tmp);
	}
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");
