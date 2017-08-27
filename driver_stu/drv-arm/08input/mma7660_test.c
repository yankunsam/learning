/*******************************
 * 三轴方向/移动传感器驱动
 * 可测量x/y/z三轴坐标、移动方向、加速度等信息
 * 采用6bit AD
 * Author: zht
 * Date: 2013-12-06
 *******************************/
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input-polldev.h>
#include <linux/hwmon.h>
#include <linux/hwmon-sysfs.h>
#include <linux/mma7660.h>

#define MMA7660_NAME		"mma7660"
#define POLL_INTERVAL		100 //轮循间隔100ms
#define INPUT_FUZZ		4
#define INPUT_FLAT		4

#define __need_retry(__v)	(__v & (1 << 6))
#define __is_negative(__v)	(__v & (1 << 5))


static struct i2c_client	*mma7660_client;
static struct device		*hwmon_dev;
static struct input_polled_dev	*mma7660_idev;
static struct mma7660_platform_data	*plat_data;

static int last_tilt = 0;
static int oper_mode;

static const char *mma7660_bafro[] = {
	"Unknown", "Front", "Back"
};
static const char *mma7660_pola[] = {
	"Unknown",
	"Left", "Right",
	"Rsvd", "Rsvd",
	"Down", "Up",
	"Rsvd",
};


//获得x/y/z轴的加速度(g)值
//index: 0==x; 1==y; 2==z
static int mma7660_read_xyz(struct i2c_client *client, int idx, int *xyz)
{
	int val;

	do {
		val = i2c_smbus_read_byte_data(client, idx + MMA7660_XOUT);
		if (val < 0) {
			dev_err(&client->dev, "Read register %02x failed, %d\n", idx + MMA7660_XOUT, val);
			return -EIO;
		}
	} while (__need_retry(val));

	*xyz = __is_negative(val) ? (val | ~0x3f) : (val & 0x3f);

	return 0;
}


//获得设备的移动信息
//通过tilt返回方向信息(上下左右前后)
static int mma7660_read_tilt(struct i2c_client *client, int *tilt)
{
	int val;

	do {
		val = i2c_smbus_read_byte_data(client, MMA7660_TILT);
		if (val < 0) {
			dev_err(&client->dev, "Read register %02x failed, %d\n",
					MMA7660_TILT, val);
			return -EIO;
		}
	} while (__need_retry(val));

	*tilt = (val & 0xff);

	return 0;
}


//初始化MMA7660
static int mma7660_initialize(struct i2c_client *client)
{
	int val;

	/* 进入test mode来探测芯片 */
	i2c_smbus_write_byte_data(client, MMA7660_MODE, 0x00);
	mdelay(10);
	i2c_smbus_write_byte_data(client, MMA7660_MODE, 0x04);
	mdelay(10);
	i2c_smbus_write_byte_data(client, MMA7660_XOUT, 0x3f);
	i2c_smbus_write_byte_data(client, MMA7660_YOUT, 0x01);
	i2c_smbus_write_byte_data(client, MMA7660_ZOUT, 0x15);
	val = i2c_smbus_read_byte_data(client, MMA7660_ZOUT);
	if (val != 0x15) {
		dev_err(&client->dev, "no device\n");
		return -ENODEV;
	}

	/* 进入standby mode对芯片进行配置 */
	i2c_smbus_write_byte_data(client, MMA7660_MODE, 0x00);
	mdelay(10);

	/* 采用率: 64Hz/16Hz; Filt: 3 samples  */
	i2c_smbus_write_byte_data(client, MMA7660_SR, ((2<<5) | (1<<3) | 1));

	/* 睡眠计数 */
	i2c_smbus_write_byte_data(client, MMA7660_SPCNT, 0xA0);

	/* Tap detect and debounce ~4ms */
	i2c_smbus_write_byte_data(client, MMA7660_PDET, 4);
	i2c_smbus_write_byte_data(client, MMA7660_PD, 15);

	/* 使能除Auto-Sleep以外的其他中断 */
	i2c_smbus_write_byte_data(client, MMA7660_INTSU, 0xe7);

	/* IPP, Auto-wake, auto-sleep and standby */
	i2c_smbus_write_byte_data(client, MMA7660_MODE, 0x59);
	mdelay(10);

	/* Save current tilt status */
	mma7660_read_tilt(client, &last_tilt);

	mma7660_client = client;
	return 0;
}


/***************************
 * device_attribute->show
 * 属性文件registers的显示函数
 * 显示传感器寄存器的内容(范围从0x0~0xA)
 ***************************/
static ssize_t 
mma7660_show_regs(struct device *dev, struct device_attribute *attr, char *buf)
{
	int reg, val;
	int i, len = 0;

	for (reg = 0; reg < 0x0b; reg++) {
		val = i2c_smbus_read_byte_data(mma7660_client, reg);
		len += sprintf(buf + len, "REG: 0x%02x = 0x%02x ...... [ ", reg, val);
		for (i = 7; i >= 0; i--) {
			len += sprintf(buf + len, "%d", (val >> i) & 1);
			if ((i % 4) == 0) {
				len += sprintf(buf + len, " ");
			}
		}
		len += sprintf(buf + len, "]\n");
	}

	return len;
}


/**************************
 * device_attribute->store
 * 属性文件registers的写函数
 * 写传感器寄存器(范围0x0~0xA)
 **************************/
static ssize_t 
mma7660_write_reg(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned int reg, val;
	int ret;

	//从buf中读入16进制的寄存器偏移和值
	//返回值为读入的单元数量(正确为2)
	ret = sscanf(buf, "%x %x", &reg, &val);
	if (ret == 2) {
		if (reg >= 0 && reg <= 0x0a) {
			i2c_smbus_write_byte_data(mma7660_client, reg, val);
			val = i2c_smbus_read_byte_data(mma7660_client, reg);
			printk("REG: 0x%02x = 0x%02x\n", reg, val);
		}
	}

	return count;
}

//声明sensor_device_attribute
static SENSOR_DEVICE_ATTR(registers, S_IRUGO | S_IWUGO,
		mma7660_show_regs, mma7660_write_reg, 0);


/************************
 * device_attribute->show
 * 属性文件all_axis_g的显示函数
 * 显示x/y/z等3个方向的加速度(g)值
 ************************/
static ssize_t 
mma7660_show_xyz_g(struct device *dev, struct device_attribute *attr, char *buf)
{
	int axis[3];
	int i;

	//参数i用于选定x/y/z方向，g值通过axis[i]回传
	for (i = 0; i < 3; i++) {
		mma7660_read_xyz(mma7660_client, i, &axis[i]);
	}

	return sprintf(buf, "%3d, %3d, %3d\n", axis[0], axis[1], axis[2]);
}


/************************
 * device_attribute->show
 * 属性文件x|y|z_axis_g的显示函数
 * 显示x/y/z等3个方向的加速度(g)值，index代表对应的轴
 ************************/
static ssize_t 
mma7660_show_axis_g(struct device *dev, struct device_attribute *attr, char *buf)
{
	int n = to_sensor_dev_attr(attr)->index;
	int val;

	mma7660_read_xyz(mma7660_client, n, &val);

	return sprintf(buf, "%3d\n", val);
}


/**************************
 * device_attribute->show
 * 属性文件tilt_status的显示函数
 * 显示设备的移动和姿态信息(上下左右前后|Tap/Shake)
 **************************/
static ssize_t 
mma7660_show_tilt(struct device *dev, struct device_attribute *attr, char *buf)
{
	int val = 0, len = 0;

	mma7660_read_tilt(mma7660_client, &val);

	len += sprintf(buf + len, "%s", mma7660_bafro[val & 0x03]);
	len += sprintf(buf + len, ", %s", mma7660_pola[(val >> 2) & 0x07]);
	if (val & (1 << 5)) {
		len += sprintf(buf + len, ", Tap");
	}
	if (val & (1 << 7)) {
		len += sprintf(buf + len, ", Shake");
	}
	len += sprintf(buf + len, "\n");

	return len;
}

//声明5个sensor_device_attribute
//参数index: 0/1/2分别代表x/y/z轴(0也表示所有轴)
static SENSOR_DEVICE_ATTR(x_axis_g, S_IRUGO, mma7660_show_axis_g, NULL, 0);
static SENSOR_DEVICE_ATTR(y_axis_g, S_IRUGO, mma7660_show_axis_g, NULL, 1);
static SENSOR_DEVICE_ATTR(z_axis_g, S_IRUGO, mma7660_show_axis_g, NULL, 2);
static SENSOR_DEVICE_ATTR(all_axis_g, S_IRUGO, mma7660_show_xyz_g, NULL, 0);
static SENSOR_DEVICE_ATTR(tilt_status, S_IRUGO, mma7660_show_tilt, NULL, 0);


//将6个sensor_device_attribute组合为属性数组
static struct attribute* mma7660_attrs[] = {
	&sensor_dev_attr_registers.dev_attr.attr,
	&sensor_dev_attr_x_axis_g.dev_attr.attr,
	&sensor_dev_attr_y_axis_g.dev_attr.attr,
	&sensor_dev_attr_z_axis_g.dev_attr.attr,
	&sensor_dev_attr_all_axis_g.dev_attr.attr,
	&sensor_dev_attr_tilt_status.dev_attr.attr,
	NULL
};

static const struct attribute_group mma7660_group = {
	.attrs		= mma7660_attrs,
};


//向input子系统报告x/y/z轴的加速度信息(g)
static void mma7660_report_abs(void)
{
	int axis[3];
	int i;

	for (i = 0; i < 3; i++) {
		mma7660_read_xyz(mma7660_client, i, &axis[i]);
	}

	input_report_abs(mma7660_idev->input, ABS_X, axis[0]);
	input_report_abs(mma7660_idev->input, ABS_Y, axis[1]);
	input_report_abs(mma7660_idev->input, ABS_Z, axis[2]);
	input_sync(mma7660_idev->input);

	//printk("3-Axis ... %3d, %3d, %3d\n", axis[0], axis[1], axis[2]);
}


/***********************
 * input_polled_dev->poll
 * 函数基于delayed_work周期性调用
 * 每次调用后向input子系统报告x/y/z轴的g值
 ***********************/
static void mma7660_dev_poll(struct input_polled_dev *dev)
{
	mma7660_report_abs();
}


/************************
 * work_struct->func
 * 在3-axis传感器的中断处理函数中触发
 ************************/
static void mma7660_worker(struct work_struct *work)
{
	int bafro, pola, shake, tap;
	int val = 0;

	mma7660_read_tilt(mma7660_client, &val);

	/* TODO: report it ? */
	bafro = val & 0x03;
	if (bafro != (last_tilt & 0x03)) {
		printk("%s\n", mma7660_bafro[bafro]);
	}

	pola = (val >> 2) & 0x07;
	if (pola != ((last_tilt >> 2) & 0x07)) {
		printk("%s\n", mma7660_pola[pola]);
	}

	shake = (val >> 5) & 0x01;
	if (shake && shake != ((last_tilt >> 5) & 0x01)) {
		printk("Shake\n");
	}

	tap = (val >> 7) & 0x01;
	if (tap && tap != ((last_tilt >> 7) & 0x01)) {
		printk("Tap\n");
	}

	/* Save current status */
	last_tilt = val;
}

DECLARE_WORK(mma7660_work, mma7660_worker);


//3-axis传感器的中断处理函数
static irqreturn_t 
mma7660_interrupt(int irq, void *dev_id)
{
	schedule_work(&mma7660_work);

	return IRQ_HANDLED;
}


/**********************
 * i2c_driver->probe
 **********************/
static int __devinit 
mma7660_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
	struct input_dev *idev;
	int poll_interval = POLL_INTERVAL;
	int input_fuzz = INPUT_FUZZ;
	int input_flat = INPUT_FLAT;
	int ret;

	//1.检查I2C控制器是否支持按字节访问MMA7660
	ret = i2c_check_functionality(adapter,
		I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_BYTE_DATA);
	if (!ret) {
		dev_err(&client->dev, "I2C check functionality failed\n");
		return -ENXIO;
	}

	plat_data = (struct mma7660_platform_data *)client->dev.platform_data;
	if (plat_data == NULL) {
		dev_err(&client->dev, "lack of platform data!\n");
		return -ENODEV;
	}

	/* Get parameters from platfrom data */
	if (plat_data->poll_interval > 0)
		poll_interval = plat_data->poll_interval;
	if (plat_data->input_fuzz > 0)
		input_fuzz = plat_data->input_fuzz;
	if (plat_data->input_flat > 0)
		input_flat = plat_data->input_flat;

	//初始化MMA7660传感器
	if (mma7660_initialize(client) < 0) {
		goto error_init_client;
	}

	//在给定的kobject(目录)下创建一组属性文件
	ret = sysfs_create_group(&client->dev.kobj, &mma7660_group);
	if (ret) {
		dev_err(&client->dev, "create sysfs group failed!\n");
		goto error_init_client;
	}

	//注册hwmon设备。干啥用？？？
	hwmon_dev = hwmon_device_register(&client->dev);
	if (IS_ERR(hwmon_dev)) {
		dev_err(&client->dev, "hwmon register failed!\n");
		ret = PTR_ERR(hwmon_dev);
		goto error_rm_dev_file;
	}

	/* 分配并初始化一个input_polled_dev */
	mma7660_idev = input_allocate_polled_device();
	if (!mma7660_idev) {
		dev_err(&client->dev, "alloc poll device failed!\n");
		ret = -ENOMEM;
		goto error_rm_hwmon_dev;
	}

	mma7660_idev->poll = mma7660_dev_poll;
	mma7660_idev->poll_interval = poll_interval;

	//初始化input_dev
	idev = mma7660_idev->input;
	idev->name = MMA7660_NAME;
	idev->id.bustype = BUS_I2C;
	idev->id.vendor = 0x12FB;
	idev->id.product = 0x7660;
	idev->id.version = 0x0100;
	idev->dev.parent = &client->dev;

	set_bit(EV_ABS, idev->evbit);
	set_bit(ABS_X, idev->absbit);
	set_bit(ABS_Y, idev->absbit);
	set_bit(ABS_Z, idev->absbit);

	input_set_abs_params(idev, ABS_X, -512, 512, input_fuzz, input_flat);
	input_set_abs_params(idev, ABS_Y, -512, 512, input_fuzz, input_flat);
	input_set_abs_params(idev, ABS_Z, -512, 512, input_fuzz, input_flat);

	//注册input_polled_dev
	ret = input_register_polled_device(mma7660_idev);
	if (ret) {
		dev_err(&client->dev, "register poll device failed!\n");
		goto error_free_poll_dev;
	}

	/* 注册中断处理函数 */
	ret = request_irq(plat_data->irq, mma7660_interrupt,
		IRQF_TRIGGER_FALLING, MMA7660_NAME, idev);
	if (ret) {
		dev_err(&client->dev, "request irq (%d) failed %d\n", plat_data->irq, ret);
		goto error_rm_poll_dev;
	}

	dev_info(&client->dev, "MMA7660 device is probed successfully.\n");

	return 0;

error_rm_poll_dev:
	input_unregister_polled_device(mma7660_idev);
error_free_poll_dev:
	input_free_polled_device(mma7660_idev);
error_rm_hwmon_dev:
	hwmon_device_unregister(hwmon_dev);
error_rm_dev_file:
	sysfs_remove_group(&client->dev.kobj, &mma7660_group);
error_init_client:
	mma7660_client = NULL;

	return 0;
}


/***************************
 * i2c_driver->remove
 ***************************/
static int __devexit 
mma7660_remove(struct i2c_client *client)
{
	free_irq(plat_data->irq, mma7660_idev->input);

	input_unregister_polled_device(mma7660_idev);
	input_free_polled_device(mma7660_idev);

	hwmon_device_unregister(hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &mma7660_group);
	mma7660_client = NULL;

	return 0;
}


/************************
 * i2c_driver->suspend
 ************************/
static int 
mma7660_suspend(struct i2c_client *client, pm_message_t state)
{
	int ret;

	//读取MMA7660当前的工作模式
	oper_mode = i2c_smbus_read_byte_data(client, MMA7660_MODE);

	//在suspend前，设置工作模式为0
	ret = i2c_smbus_write_byte_data(client, MMA7660_MODE, 0);
	if (ret)
		printk("%s: set mode (0) for suspend failed, ret = %d\n", MMA7660_NAME, ret);

	return 0;
}


/***********************
 * i2c_driver->resume
 ***********************/
static int 
mma7660_resume(struct i2c_client *client)
{
	int ret;

	//恢复到suspend之前的工作模式
	ret = i2c_smbus_write_byte_data(client, MMA7660_MODE, oper_mode);
	if (ret)
		printk("%s: set mode (%d) for resume failed, ret = %d\n", MMA7660_NAME, oper_mode, ret);

	return 0;
}

static const struct i2c_device_id mma7660_ids[] = {
	{ MMA7660_NAME, 0 },
	{ },
};
MODULE_DEVICE_TABLE(i2c, mma7660_ids);

static struct i2c_driver mma7660_driver = {
	.driver		= {
		.name	= MMA7660_NAME,
	},
	.probe		= mma7660_probe,
	.remove		= mma7660_remove,
	.suspend	= mma7660_suspend,
	.resume		= mma7660_resume,
	.id_table	= mma7660_ids,
};

static int __init my_init(void)
{
	int ret;

	ret = i2c_add_driver(&mma7660_driver);
	printk("MMA7660 sensor driver registered.\n");

	return ret;
}

static void __exit my_exit(void)
{
	i2c_del_driver(&mma7660_driver);
	printk("MMA7660 sensor driver removed.\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Freescale Semiconductor, Inc.");
MODULE_DESCRIPTION("MMA7660 sensor driver");
MODULE_LICENSE("GPL");

