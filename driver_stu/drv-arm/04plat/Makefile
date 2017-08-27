# Makefile for external module

KERNEL := /var/local/kernel/linux35_tiny4412

obj-m := plat_dev01.o plat_dev02.o plat_dev03.o plat_test03.o 
myko1 := plat_dev01.ko 
myko2 := plat_dev02.ko 
myko3 := plat_dev03.ko 
myko4 := plat_test03.ko
myelf := udev01
mysrc := udev01.c

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	adb remount
	adb push $(myko1) /system/lib/modules/
	adb push $(myko2) /system/lib/modules/
	adb push $(myko3) /system/lib/modules/
	adb push $(myko4) /system/lib/modules/
install-elf:
	arm-linux-gcc -static -o $(myelf) $(mysrc)
	adb remount
	adb push $(myelf) /system/bin/
clean:
	make -C $(KERNEL) M=`pwd` clean


