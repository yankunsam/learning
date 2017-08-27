# Makefile for external module
obj-m := wait_test.o
KERNEL := /lib/modules/`uname -r`/build

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	make -C $(KERNEL) M=`pwd` modules_install
	depmod -A
clean:
	make -C $(KERNEL) M=`pwd` clean
	rm -f *.order *.symvers *.markers

