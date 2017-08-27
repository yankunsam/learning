/*************************
 * 利用开发板上的4个按键进行atomic_t计数的测试
 * 用普通变量和atomic_t变量进行计数，理论上讲，普通变量可能会丢计数
 * author: zht
 * date: 2014-07-16
 *************************/
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/proc_fs.h>
#include <linux/gpio.h>
#include <linux/atomic.h>

#include <plat/gpio-cfg.h>
#include <mach/gpio.h>

#define KEY_NUM	 	4

//按键的描述
struct btn_desc {
	int gpio;
	int number;
	char *name;  //中断处理函数的名字
};

static struct btn_desc buttons[] = {
	{ EXYNOS4_GPX3(2), 0, "atom0" },
	{ EXYNOS4_GPX3(3), 1, "atom1" },
	{ EXYNOS4_GPX3(4), 2, "atom2" },
	{ EXYNOS4_GPX3(5), 3, "atom3" },
};

static int manual_i = 0;
static atomic_t atom_i = ATOMIC_INIT(0);


static int atomic_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int ret = 0;
	ret += sprintf(page, "manual_i = %d; atom_i = %d\n", manual_i, atomic_read(&atom_i));

	return ret;
}


/* 中断处理函数: 可以为4个按键提供服务 */
static irqreturn_t 
key_service(int irq, void *dev_id)
{
	//int i;
	//for (i=0; i<100; i++) {
		manual_i++;
		atomic_inc(&atom_i);
	//}

	return IRQ_HANDLED; /* IRQ_NONE */
}


static int __init my_init(void)
{
	int i, j, ret;
	unsigned long flags;

	for (i=0; i<KEY_NUM; i++) {
		/* 注册中断处理函数 */
		flags = //IRQF_TRIGGER_FALLING;
			IRQF_TRIGGER_LOW;

		ret = request_irq(gpio_to_irq(buttons[i].gpio),
			key_service, 
			flags, 
			buttons[i].name,
			&buttons[i]);
		if (ret) {
			printk("Cannot request irq %d\n", gpio_to_irq(buttons[i].gpio));
			goto err;
		}
	}

	create_proc_read_entry("proc_atomic", 0,
		NULL, atomic_proc_read, NULL);

	return 0;
err:
	for (j=0; j<i; j++)
		free_irq(gpio_to_irq(buttons[j].gpio), &buttons[j]);
	return ret;
}

static void __exit my_exit(void)
{
	int i;

	remove_proc_entry("proc_atomic", NULL);

	for (i=0; i<KEY_NUM; i++)
		free_irq(gpio_to_irq(buttons[i].gpio), &buttons[i]);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZHT");

