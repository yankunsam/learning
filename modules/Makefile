name = init
modules_cur := $(name).ko
obj-m := $(name).o
KERNEL := /home/sam/8lab_work/linux
all:
	make -C $(KERNEL) M=`pwd` $(modules_cur)
install:
	#make -C $(KERNEL) M=`pwd` modules_install
	sudo insmod $(modules_cur)
clean:
	make -C $(KERNEL) M=`pwd` clean
	sudo rmmod $(modules_cur)

