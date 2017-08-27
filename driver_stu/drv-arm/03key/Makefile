# Makefile for external module

obj-m := spin_test01.o 
KERNEL := /var/local/kernel/linux35_tiny4412
myko := spin_test01.ko
myelf := buzz01
mysrc := buzz01.c

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	adb remount
	adb push $(myko) /system/lib/modules/
install-elf:
	arm-linux-gcc -static -o $(myelf) $(mysrc)
	adb remount
	adb push $(myelf) /system/bin/
clean:
	make -C $(KERNEL) M=`pwd` clean


