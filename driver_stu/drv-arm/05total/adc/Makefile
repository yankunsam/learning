# 用于外部模块的Makefile
# (必须连接到一个编译好的内核)
# Author: zht
# Date: 2014-10-29
obj-m := adc_test01.o adc_dev.o
KERNEL := /var/local/kernel/linux35_tiny4412/

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	adb remount
	adb push adc_test01.ko /system/modules/
	adb push adc_dev.ko /system/modules/
install-bin:
	arm-linux-gcc -static -o adc01 adc01.c
	adb remount
	adb push adc01 /system/bin/
clean:
	make -C $(KERNEL) M=`pwd` clean
	rm -f adc01
