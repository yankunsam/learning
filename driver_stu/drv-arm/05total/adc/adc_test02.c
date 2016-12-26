/****************************
 * 可调电阻(模拟温度传感器)的char驱动
 * 直接访问寄存器，并支持ADC转换中断
 * 要运行本例子，要先去掉内核中的ADC接口库
 * Author: zht
 * Date: 2014-08-22
 ****************************/
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/completion.h>
#include <linux/clk.h>
#include "regs-adc.h"

//定义ADC相关信息
#define ADC_MAX_CH	4
#define ADC_PRESC	65
#define ADC_DELAY	10000
#define ADC_12BITS	1
//define ADC_10BITS	1

struct one_result {
	int ch;
	int value;
};

//定义ioctl命令号，
#define TYPE_ADC	'A'
#define GET_VALUE	_IOW(TYPE_ADC, 1, struct one_result)

//将4个adc通道识别为一个设备，不必使用私有结构体
static int phy_base;
static int phy_size;
static void __iomem *vir_base;
static int adc_irq;
static struct clk *adc_clk;
static struct completion comp;

//中断处理函数，清空中断状态寄存器
static irqreturn_t
adc_service(int irq, void *dev_id)
{
        writel(0x0, vir_base+S3C_ADCCLRINT);
	complete(&comp);
	return IRQ_HANDLED;
}


static long
adc_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	struct one_result tmp;
	int ret;

	if (copy_from_user(&tmp, (void *)arg, sizeof(tmp)))
		return -EFAULT;

	if (tmp.ch >= ADC_MAX_CH) {
		printk("Only support %d channels\n", ADC_MAX_CH);
		return -1;
	}

	//启动ADC
	ret = readl(vir_base + S3C_ADCCON);
	ret &= ~ADCCON_SELMASK;
	ret |= ADCCON_ENABLE_START | ADCCON_SEL(tmp.ch);
	writel(ret, vir_base+S3C_ADCCON);

	//等待直到AD操作结束
	wait_for_completion(&comp);

	//读出AD数据
	ret = readl(vir_base+S3C_ADCDAT0);

#if defined(ADC_10BITS)
	tmp.value = ret & ADCDAT_DATA_MASK10;
	if (tmp.value > 1023)
		goto err;
#else	
	tmp.value = ret & ADCDAT_DATA_MASK12;
	if (tmp.value > 4095)
		goto err;
#endif

	if (copy_to_user((void *)arg, &tmp, sizeof(tmp)))
		return -EFAULT;

	return 0;
err:
	printk("adc read error\n");
	return -EIO;
}

static struct file_operations adc_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = adc_ioctl,
};

static struct miscdevice adc_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "raw_adc",
	.fops = &adc_fops,
};


static int
adc_probe(struct platform_device *pdev)
{
	int ret, value;
	struct resource *res1, *res2;

	//获取资源
	res1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!res1 || !res2) {
		printk("Cannot get enough resource\n");
		return -EIO;
	}

	//地址映射
	phy_base = res1->start;
	phy_size = res1->end - res1->start + 1;
	vir_base = ioremap(phy_base, phy_size);
	if (!vir_base) {
		printk("ADC Cannot ioremap: 0x%x\n", phy_base);
		return -EIO;
	}

	//获得并使能ADC的时钟
	adc_clk = clk_get(&pdev->dev, "adc");
	if (IS_ERR(adc_clk)) {
		printk("failed to find adc clock\n");
		ret = PTR_ERR(adc_clk);
		goto err_clk;
	}
	clk_enable(adc_clk);
	printk("ADC clock enabled:%ld Mhz\n", 
		clk_get_rate(adc_clk)/1000000);

	//初始化ADCON & ADCDLY寄存器
	value = ADCCON_PRSCEN | ADCCON_PRSCVL(ADC_PRESC);
#if (defined(ADC_10BITS))
	value |= ADCCON_10BITS;
#else
	value |= ADCCON_12BITS;
	writel(value, vir_base+S3C_ADCCON);
	writel(ADC_DELAY, vir_base+S3C_ADCDLY); 
#endif
	//初始化completion
	init_completion(&comp);

	//注册中断处理函数
	adc_irq = res2->start; 
	ret = request_irq(adc_irq, adc_service,
		IRQF_SHARED, "myadc", vir_base);
	if (ret) {
		printk("ADC: cannot request irq %d\n", adc_irq);
		goto err_irq;
	}

	//注册miscdevice
	ret = misc_register(&adc_misc);
	if (ret) {
		printk("adc: Cannot register misc_device\n");
		goto err_misc;
	}

	return 0;

err_misc:
	misc_deregister(&adc_misc);
err_irq:
	clk_disable(adc_clk);
	clk_put(adc_clk);
err_clk:
	iounmap(vir_base);
	return ret;
}


static int
adc_remove(struct platform_device *pdev)
{
	misc_deregister(&adc_misc);
	clk_disable(adc_clk);
	clk_put(adc_clk);
	iounmap(vir_base);
	
	return 0;
}

static struct platform_device_id adc_ids[] = {
	{"up4412-adc", 0},
	{"up6410-adc", 0},
	{}
};

static struct platform_driver adc_pdrv = {
	.probe = adc_probe,
	.remove = adc_remove,
	.driver = {
		.name = "adc-driver02",
	},
	.id_table = adc_ids,
};

static int __init my_init(void)
{
	return platform_driver_register(&adc_pdrv);
}

static void __exit my_exit(void)
{
	platform_driver_unregister(&adc_pdrv);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

