modules_cur := sam_rm.ko
obj-m := sam_rm.o
KERNEL :=/home/sam/fork/linux/
all:
	make -C $(KERNEL) M=`pwd` $(modules_cur)
install:
	#make -C $(KERNEL) M=`pwd` modules_install
	sudo insmod $(modules_cur)
clean:
	make -C $(KERNEL) M=`pwd` clean
	sudo rmmod $(modules_cur)

