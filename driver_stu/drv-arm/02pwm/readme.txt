
说明：
本目录下是两个和pwm相关的驱动例子。
buzz_test01.c是用IO操作控制蜂鸣器的响或不响。

buzz_test02.c是用内核的pwm库接口来控制蜂鸣器，可以通过输出不同的频率的方波来控制蜂鸣器的声音。
buzz01.c是和buzz_test02.c配套的用户态测试程序。

注意！第二个例子在使用前，要修改arch/arm/mach-exynos/mach-tiny4412.c文件。
在该文件中找到如下内容：
#ifdef CONFIG_TINY4412_BUZZER
	&s3c_device_timer[0],
#endif
修改如下：
//#ifdef CONFIG_TINY4412_BUZZER
	&s3c_device_timer[0],
//#endif

改完后，重新编译并烧写一次zImage即可。



