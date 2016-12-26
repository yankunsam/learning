# Makefile for external module

obj-m := led_test06.o 
KERNEL := /var/local/kernel/linux35_tiny4412
myko := led_test06.ko
myelf := led02
mysrc := led02.c

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


