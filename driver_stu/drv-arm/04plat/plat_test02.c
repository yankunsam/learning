/********************************
 * 针对platform设备提供char驱动
 * 驱动实现ioctl命令，可以获得和设置给定寄存器
 * Author: zht
 * Date: 2014-08-20
 ********************************/
#include <linux/module.h>
#include <linux/slab.h> //kzalloc
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <linux/platform_device.h>

#define PLAT_MAJOR 	80

//定义ioctl命令
//利用命令参数传递寄存器偏移和值
struct one_reg {
	int offset;
	int value;
};

#define PLAT_TYPE	'P'
#define GET_REG		_IOW(PLAT_TYPE, 1, struct one_reg)
#define SET_REG		_IOW(PLAT_TYPE, 2, struct one_reg)

//私有结构体
struct plat_priv {
	int phy_base;
	int phy_size;
	void __iomem *vir_base;
	dev_t dev_id;
	struct cdev plat_cdev;
};

static int cur_minor = 0;


//准备file_operations
static int
plat_open(struct inode *inode, struct file *filp)
{
	struct plat_priv *tmp = container_of(inode->i_cdev, struct plat_priv, plat_cdev);
	filp->private_data = tmp;

	return 0;
}


static long
plat_ioctl(struct file *filp, unsigned int req, unsigned long arg)
{
	struct plat_priv *tmp = filp->private_data;
	struct one_reg reg;
	
	if (copy_from_user(&reg, (void *)arg, sizeof(reg)))
		return -EFAULT;

	if (reg.offset > (tmp->phy_size-4)) {
		printk("Out of range: 0x%x to 0x%x\n", \
			tmp->phy_base, \
			tmp->phy_base + tmp->phy_size);
		return -EIO;
	}

	if (req == GET_REG) {
		reg.value = readl(tmp->vir_base + reg.offset);
		if (copy_to_user((void *)arg, &reg, sizeof(reg)))
			return -EFAULT;
	}
	else if (req == SET_REG) {
		writel(reg.value, tmp->vir_base+reg.offset);
	} 
	else {
		printk("Cannot support ioctl 0x%x\n", req);
		return -1;
	}

	return 0;
}

//由于多个设备可以共用同一个操作函数集，因此file_ops可以放在全局的位置
static struct file_operations plat_fops = {
	.owner = THIS_MODULE,
	.open = plat_open,
	.unlocked_ioctl = plat_ioctl,
};


//准备platform_driver
static int 
plat_probe(struct platform_device *pdev)
{
	struct plat_priv *priv;
	struct resource *res;

	printk("Test02: probe() %s:%d\n", \
		pdev->name, pdev->id);

	//1.从pdev中获得并检测硬件信息
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		printk("Cannot get IOMEM resource\n");
		return -1;
	}

	//2.分配并初始化私有结构体
	priv = (struct plat_priv *)kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv) 
		return -ENOMEM;
	priv->phy_base = res->start;
	priv->phy_size = res->end - res->start + 1;

	//3.request_mem_region & ioremap
	//如果不是正式的驱动，可以只ioremap
	priv->vir_base = ioremap(priv->phy_base, priv->phy_size);
	if (!priv->vir_base) {
		kfree(priv);
		return -EIO;
	}

	//4.分配设备号，注册file_operations
	priv->dev_id = MKDEV(PLAT_MAJOR, cur_minor++);
	cdev_init(&priv->plat_cdev, &plat_fops);
	priv->plat_cdev.owner = THIS_MODULE;
	cdev_add(&priv->plat_cdev, priv->dev_id, 1);

	//5.将私有结构体的指针存入platform_device
	platform_set_drvdata(pdev, priv);

	return 0;
}


//在pdev注销或pdrv注销时调用
static int
plat_remove(struct platform_device *pdev)
{
	struct plat_priv *priv = platform_get_drvdata(pdev);

	printk("Test02: remove() %s:%d\n", \
		pdev->name, pdev->id);
	cdev_del(&priv->plat_cdev);
	iounmap(priv->vir_base);
	kfree(priv);

	return 0;
}

static struct platform_device_id my_ids[] = {
	{ .name = "孙悟空" },
	{ .name = "猪八戒" },
	{ .name = "沙和尚" },
	{ .name = "白龙马" },
	{},
};

static struct platform_driver my_pdrv = {
	.probe = plat_probe,
	.remove = plat_remove,
	.driver = {
		.name = "西天旅游团",
	},
	.id_table = my_ids,
};

static int __init my_init(void)
{
	//注册platform_driver
	return platform_driver_register(&my_pdrv);
}

static void __exit my_exit(void)
{
	//注销pdrv
	platform_driver_unregister(&my_pdrv);
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

