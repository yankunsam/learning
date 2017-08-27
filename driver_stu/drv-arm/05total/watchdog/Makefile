# 用于外部模块的Makefile
# (必须连接到一个编译好的内核)
# Author: zht
# Date: 2014-10-29
obj-m := wdt_dev.o wdt_test02.o
KERNEL := /var/local/kernel/linux35_tiny4412/

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	arm-linux-gcc -static -o wdt01 wdt01.c
	adb remount
	adb push wdt_dev.ko /system/bin
	adb push wdt_test02.ko /system/bin
	adb push wdt01 /system/bin
clean:
	make -C $(KERNEL) M=`pwd` clean

