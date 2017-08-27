/*************************
 * 4412看门狗的完整char驱动
 * 支持用write和ioctl控制，支持切换中断和reset模式
 * author: zht
 * date: 2014-08-25
 *************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/time.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include "regs-wdt.h"

//定义默认常量，如喂狗间隔，工作模式等
#define MODE_IRQ	1
#define MODE_RESET	2
#define WDT_DEF_MODE	MODE_IRQ
#define WDT_DEF_TIME	10

//定义ioctl命令
#define WDT_TYPE	'W'
#define WDT_ON		_IO(WDT_TYPE, 1)
#define WDT_OFF		_IO(WDT_TYPE, 2)
#define WDT_FEED	_IO(WDT_TYPE, 3)
#define WDT_CHGTIME 	_IOW(WDT_TYPE, 4, int)
#define WDT_CHGMODE	_IOW(WDT_TYPE, 5, int)

//定义全局变量
static u32 wdt_base;
static u32 wdt_size;
static struct resource *wdt_res;
static void __iomem *vir_base;

static int wdt_irq;  //中断号
static int wdt_time; //喂狗间隔秒数
static int wdt_count; //喂狗间隔的计数
static int wdt_mode; //狗的模式

static struct clk *wdt_clk;
static spinlock_t wdt_lock;


/******************
 * 启动看门狗
 ******************/
static void wdt_start(void)
{
	u32 wtcon;

	//默认使用128分频
	wtcon = readl(vir_base + WTCON);
	wtcon |= WTCON_ENABLE | WTCON_DIV128;

	if (wdt_mode == MODE_RESET) {
		wtcon |= WTCON_RSTEN;
		wtcon &= ~WTCON_INTEN;
	} 
	else {
		wtcon |= WTCON_INTEN;
		wtcon &= ~WTCON_RSTEN;
	}
	printk("WDT: start, wdt_count=%d, WTCON=0x%x\n", wdt_count, wtcon);
	writel(wdt_count, vir_base + WTDAT);
	writel(wdt_count, vir_base + WTCNT);
	udelay(10);
	writel(wtcon, vir_base + WTCON);
}


/*******************
 * 停止看门狗
 *******************/
static void wdt_stop(void)
{
	u32 wtcon;

	wtcon = readl(vir_base + WTCON);
	wtcon &= ~(WTCON_ENABLE | WTCON_RSTEN | WTCON_INTEN);
	writel(wtcon, vir_base + WTCON);
}


/*******************
 * 喂狗
 *******************/
static void wdt_keepalive(void)
{
	writel(wdt_count, vir_base + WTCNT);
}


/***********************
 * 以秒为单位设置喂狗间隔
 * 参数为要间隔的秒数
 ***********************/
static int wdt_set_heartbeat(int timeout)
{
	u32 freq = clk_get_rate(wdt_clk);
	u32 count;
	u32 presc = 1;
	u32 wtcon;

	if (timeout < 1)
		return -EINVAL;

	//默认对PCLK进行128分频
	freq /= 128;
	count = timeout * freq;

	if (count >= 0x10000) {
		for (presc = 1; presc <= 0x100; presc++) {
			if ((count/presc) < 0x10000)
				break;
		}

		if ((count/presc) >= 0x10000) {
			printk("timeout %d too big\n", timeout);
			return -EINVAL;
		}
	}

	wdt_time = timeout;
	count /= presc;
	wdt_count = count;

	printk("WDT: timeout=%dS, presc=%d, wdt_count=%d\n", wdt_time, presc, wdt_count);

	/* 更新WTCON和WTDAT */
	wtcon = readl(vir_base + WTCON);
	wtcon &= ~WTCON_PRESCALE_MASK;
	wtcon |= WTCON_PRESCALE(presc-1);
	writel(wtcon, vir_base + WTCON);

	writel(wdt_count, vir_base + WTDAT);

	return 0;
}

/**************************
 * 切换看门狗的响应模式(只在ioctl中调用)
 **************************/
static int wdt_chgmode(u32 mode)
{
	u32 wtcon;

	wtcon = readl(vir_base+WTCON);
	if (mode == MODE_IRQ) {
		wtcon &= ~WTCON_RSTEN;
		wtcon |= WTCON_INTEN;
		wdt_mode = MODE_IRQ;
	}
	else if (mode == MODE_RESET) {
		wtcon &= ~WTCON_INTEN;
		wtcon |= WTCON_RSTEN;
		wdt_mode = MODE_RESET;
	}
	else {
		printk("WDT: unsupport mode %d\n", mode);
		return -1;
	}
	writel(wtcon, vir_base+WTCON);

	return 0;
}


/**************************
 * /proc/proc_wdt文件的读函数
 **************************/
static int 
wdt_proc_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
	int wtcon, wtdat, wtcnt, ret = 0;

	spin_lock(&wdt_lock);
	wtcon = readl(vir_base + WTCON);
	wtcnt = readl(vir_base + WTCNT);
	wtdat = readl(vir_base + WTDAT);
	spin_unlock(&wdt_lock);

	ret += sprintf(page+ret, "====WDT(irq %d)====\n", wdt_irq);
	ret += sprintf(page+ret, "watchdog %sactive, reset %sabled, interrupt %sabled\n", 
		 (wtcon & WTCON_ENABLE) ?  "" : "in",
		 (wtcon & WTCON_RSTEN) ? "en" : "dis",
		 (wtcon & WTCON_INTEN) ? "en" : "dis");
	ret += sprintf(page+ret, "Heartbeat = %ds; wdt_count = %d;\n", wdt_time, wdt_count);
	ret += sprintf(page+ret, "WTDAT = %d; WTCNT = %d\n", wtdat, wtcnt);

	return ret;
}


/***************
 * 看门狗中断
 ***************/
static irqreturn_t 
wdt_service(int irq, void *dev_id)
{
	struct timeval tval;

	do_gettimeofday(&tval);
	printk("我饿死了: %lds\n", tval.tv_sec);
	//清除中断标志
	writel(0, vir_base + WTCLRINT);

	return IRQ_HANDLED;
}


/*************************
 * fops->write
 * $>echo on|feed|off >/dev/wdt0
 *************************/
static ssize_t
wdt_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	char tmp[10] = {0};

	if (copy_from_user(tmp, buf, 4))
		return -ENOMEM;
	
	//根据传入的字符串，控制狗的行为
	spin_lock(&wdt_lock);

	if (strncmp(tmp, "on", 2) == 0)
		wdt_start();
	else if (strncmp(tmp, "off", 3) == 0)
		wdt_stop();
	else if (strncmp(tmp, "feed" ,4) == 0)
		wdt_keepalive();
	else 
		printk("Use: $>echo on|off|feed >/dev/xxx\n");

	spin_unlock(&wdt_lock);
	
	return count;
}


/****************************
 * fops-->unlocked_ioctl
 * 为了简化ioctl函数，每个命令都有专门的子函数
*****************************/
static long 
wdt_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	int ret = 0;

	//在访问寄存器之前，获得锁
	spin_lock(&wdt_lock);
	switch (req) {
	case WDT_ON: 
		wdt_start();
		break;
	case WDT_OFF:
		wdt_stop();
		break;
	case WDT_FEED:
		wdt_keepalive();
		break;
	case WDT_CHGTIME:
		ret = wdt_set_heartbeat(arg);
		break;
	case WDT_CHGMODE:
		ret = wdt_chgmode(arg);
		break;
	default:
		printk("Cannot support ioctl: 0x%x\n", req);
		ret = -1;
	}
	spin_unlock(&wdt_lock);

	return ret;
}


static struct file_operations wdt_fops = {
	.owner 	= THIS_MODULE,
	.write	= wdt_write,
	.unlocked_ioctl = wdt_ioctl,
};

//name为/dev下的设备文件名
static struct miscdevice wdt_misc = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= "wdt0",
	.fops	= &wdt_fops,
};


/**********************
 * platform_driver->probe
 **********************/
static int 
wdt_probe(struct platform_device *pdev)
{
	struct resource *res1, *res2;
	int ret, wtcon;

	//1.获得资源
	res1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res1 || !res2) {
		printk("%s: Cannot get enough resources\n", pdev->name);
		return -1;
	}

	//2.准备访问WDT寄存器
	wdt_base = res1->start;
	wdt_size = res1->end-res1->start+1;
	wdt_res = request_mem_region(wdt_base, wdt_size, "4412wdt-res");
	if (!wdt_res) {
		printk("%s: request failed\n", pdev->name);
		return -EIO;
	}

	vir_base = ioremap(wdt_base, wdt_size);
	if (!vir_base) {
		printk("%s: Cannot ioremap\n", pdev->name);
		ret = -EIO;
		goto err_map;
	}

	//3.注册中断处理函数，flags可以为0
	//IRQF_SHARED, IRQF_TRIGGER_FALLING
	wdt_irq = res2->start;
	ret = request_irq(wdt_irq, wdt_service, 
		0, pdev->name, vir_base);
	if (ret) {
		printk("%s: Cannot request irq %d\n", pdev->name, wdt_irq);
		goto err_irq;
	}

	//4.使能时钟
	//clk结构体是三星准备好的，包含时钟信息
	//大部分的clk结构体定义在arch/arm/mach-exynos/clock-exynos4.c
	//所有通过芯片内部PLL提供的时钟都需要执行clk_enable
	wdt_clk = clk_get(&pdev->dev, "watchdog");
	if (IS_ERR(wdt_clk)) {
		printk("WDT: failed to get clock\n");
		ret = PTR_ERR(wdt_clk);
		goto err_clk;
	}
	clk_enable(wdt_clk);

	//5.创建proc文件
	create_proc_read_entry("proc_wdt", 0444, NULL, 
		wdt_proc_read, NULL);

	//6.初始化变量(本例使用默认值，也可以将wdt_time和wdt_mode改造为module_param)
	spin_lock_init(&wdt_lock);
	wdt_time = WDT_DEF_TIME;
	wdt_mode = WDT_DEF_MODE;

	//7.设置默认的喂狗间隔
	wdt_set_heartbeat(wdt_time);

	//8.默认关闭看门狗
	wdt_stop();

	//9.注册miscdevice
	ret = misc_register(&wdt_misc);
	if (ret) {
		printk("%s: cannot register miscdevice\n", pdev->name);
		goto err_misc;
	}

	//10.显示信息
	wtcon = readl(vir_base + WTCON);
	printk("WDT: %savtive, reset %sabled, irq %sabled\n",
		 (wtcon & WTCON_ENABLE) ?  "" : "in",
		 (wtcon & WTCON_RSTEN) ? "en" : "dis",
		 (wtcon & WTCON_INTEN) ? "en" : "dis");
	printk("WDT: clock %ldHZ\n", clk_get_rate(wdt_clk));

	return 0;

err_misc:
	remove_proc_entry("proc_wdt", NULL);
	clk_disable(wdt_clk);
	clk_put(wdt_clk);
err_clk:
	free_irq(wdt_irq, vir_base);	
err_irq:
	iounmap(vir_base);
err_map:
	release_mem_region(wdt_base, wdt_size);
	return ret;
}


/***************************
 * platform_driver->remove
 ***************************/
static int 
wdt_remove(struct platform_device *pdev)
{
	free_irq(wdt_irq, vir_base);
	misc_deregister(&wdt_misc);
	remove_proc_entry("proc_wdt", NULL);

	clk_disable(wdt_clk);
	clk_put(wdt_clk);

	iounmap(vir_base);
	release_mem_region(wdt_base, wdt_size);

	return 0;
}


static struct platform_device_id wdt_ids[] = {
	{"up4412-wdt", 0},
	{"up6410-wdt", 0},
	{"up2440-wdt", 0},
	{}
};

static struct platform_driver wdt_drv = {
	.probe 	= wdt_probe,
	.remove = wdt_remove,
	.driver = {
		.name = "wdt-drv",
	},
	.id_table = wdt_ids,
};


static int __init my_init(void)
{
	return platform_driver_register(&wdt_drv);
}

static void __exit my_exit(void)
{
	platform_driver_unregister(&wdt_drv);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

