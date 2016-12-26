/*****************************
 * 本文件展示了i2c代码如何生成i2c_client
 * 下面的代码要求在板子的初始化过程中调用，或者在i2c核心代码运行前调用
 * 注意！真正完成下面工作的地方，一般应该是arch/arm/mach-exynos/mach-tiny4412.c
 * Author: zht
 * Date: 2014-05-26
 *****************************/
#include <linux/i2c.h>
#include <plat/ft5x0x_touch.h>

//准备和电容屏对应的硬件信息
static struct ft5x0x_i2c_platform_data ft5x0x_pdata = {
	.gpio_irq = EXYNOS4_GPX1(6),
	.irq_cfg = S3C_GPIO_SFN(0xf),
	.screen_max_x	= 800,
	.screen_max_y	= 480,
	.pressure_max	= 255,
};

//为i2c1控制器上的所有i2c设备准备i2c_board_info
//当i2c控制器的驱动运行时，会根据i2c_board_info数组生成对应的i2c_client
static struct i2c_board_info i2c1_devs[] = {
	[0] = {
		.type = "沙悟净", //我是谁
		.addr = (0x70 >> 1), //0x38
		.platform_data = &ft5x0x_pdata,
	},
};


static int __init my_init(void)
{
	//注册一个i2c控制器下的所有i2c_board_info设备
	//注册要在i2c控制器驱动运行前完成
	//1代表的主控制器的编号
	return i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
}

static void __exit my_exit(void)
{
	//不需要注销i2c_board_info设备
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("ZHT");
MODULE_LICENSE("GPL");

