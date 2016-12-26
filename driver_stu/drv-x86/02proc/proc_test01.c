/************************
 * 创建只读proc文件的例子
 * Author: zht
 * Date: 2015-04-16
 ************************/
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h> //jiffies

//proc的读函数
static int my_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	ret = sprintf(page, "kernel time is %ld\n", jiffies);
	return ret;
}


static int __init my_init(void)
{
	//创建proc文件abc_ro，并关联读函数
	struct proc_dir_entry *file;

	file = create_proc_entry("abc_ro",
			0444, NULL);
	if (!file) {
		printk("Cannot create /proc/abc_ro\n");
		return -1;
	}
	file->read_proc = my_proc_read;

	return 0;
}

static void __exit my_exit(void)
{
	//删除proc文件
	remove_proc_entry("abc_ro", NULL);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

