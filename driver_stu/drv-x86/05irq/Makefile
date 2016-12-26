# Makefile for external module
# Author: zht
# Date: 2014-07-14
obj-m := irq_test.o tasklet_test.o wq_test01.o wq_test02.o
KERNEL := /lib/modules/`uname -r`/build

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	make -C $(KERNEL) M=`pwd` modules_install
	depmod -A
clean:
	make -C $(KERNEL) M=`pwd` clean
	rm -f *.order *.symvers *.markers

