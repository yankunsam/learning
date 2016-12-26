# 用于外部模块的Makefile
# (必须连接到一个编译好的内核)
# Author: zht
# Date: 2014-10-29
obj-m := dm9621_test01.o
KERNEL := /var/local/kernel/linux35_tiny4412/

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	adb remount
	adb push dm9621_test01.ko /system/lib/modules/
	arm-linux-gcc -static -o usb01 usb01.c
	adb push usb01 /system/bin/
clean:
	make -C $(KERNEL) M=`pwd` clean

