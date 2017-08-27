/************************
 * 创建可读写的proc文件的例子
 * Author: zht
 * Date: 2015-04-16
 ************************/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h> //jiffies
#include <linux/uaccess.h> //copy_to_user & copy_from_user

//保存用户态每次echo的字符串(只能存一个)
//下一次echo，会覆盖前一次的内容
static char *str;

//proc的写函数
static int my_proc_write(struct file *filp, const char __user *buf, unsigned long count, void *data)
{
	char *tmp;
	tmp = (char *)kzalloc(count+1, GFP_KERNEL);
	if (tmp == NULL)
		return -ENOMEM;

	//copy_from_user(to,from,cnt)
	if (copy_from_user(tmp,buf,count)) {
		kfree(tmp);
		return -EFAULT;
	}

	kfree(str); //可以kfree(NULL)
	str = tmp;
	return count;	
}


//proc的读函数
static int my_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	ret = sprintf(page, "kernel time is %ld\n", jiffies);
	ret += sprintf(page+ret, "str is %s\n", str);
	return ret;
}


static int __init my_init(void)
{
	//创建proc文件abc_rw，并关联读写函数
	struct proc_dir_entry *file;

	file = create_proc_entry("abc_rw",
			0666, NULL);
	if (!file) {
		printk("Cannot create /proc/abc_rw\n");
		return -1;
	}
	file->read_proc = my_proc_read;
	file->write_proc = my_proc_write;

	return 0;
}

static void __exit my_exit(void)
{
	//删除proc文件
	remove_proc_entry("abc_rw", NULL);
	kfree(str);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

