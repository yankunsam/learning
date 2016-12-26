/*******************
 * 用户态的测试
 * $>usb01 /dev/dm96 r1 0x28 //读寄存器0x28
 * $>usb01 /dev/dm96 rx 0x28 10 //从0x28开始读10个字节
 * $>usb01 /dev/dm96 w1 0x30 0x5 //将0x5写入寄存器0x30
 * Author: zht
 * Date: 2014-01-14
 *******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

struct usb_one_reg {
	char offset;
	char value;
};

struct usb_all_regs {
	char offset;
	char size;
	char values[256];
};

//ioctl号
#define USB_TYPE	'U'
#define USB_R_REG	_IOW(USB_TYPE, 1, struct usb_one_reg)
#define USB_W_REG	_IOW(USB_TYPE, 2, struct usb_one_reg)
#define USB_R_REGS	_IOW(USB_TYPE, 3, struct usb_all_regs)


int main(int argc, void **argv)
{
	char *endptr;
	int i, fd, ret, offset, size, value;
	struct usb_one_reg one;
	struct usb_all_regs all;

	//打开设备文件
	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("open %s error\n", argv[1]);
		exit(1);
	}
	printf("open %s\n", argv[1]);

	//根据参数执行对应行为
	if (strncmp("r1", argv[2], 2) == 0) {
		offset = strtol(argv[3], &endptr, 16);
		one.offset = (char)offset;
		one.value = 0;
		ret = ioctl(fd, USB_R_REG, &one);
		if (ret)
			printf("reg 0x%x read err\n", offset);
		else 
			printf("Rreg 0x%x: 0x%x\n", offset, one.value&0xff);
	}
	else if (strncmp("w1", argv[2], 2) == 0) {
		offset = strtol(argv[3], &endptr, 16);
		value = strtol(argv[4], &endptr, 16);
		one.offset = (char)offset;
		one.value = (char)value;
		ret = ioctl(fd, USB_W_REG, &one);
		if (ret)
			printf("reg 0x%x write err\n", offset);
		else 
			printf("Wreg 0x%x: 0x%x\n", offset, value&0xff);
	}
	else if (strncmp("rx", argv[2], 2) == 0) {
		offset = strtol(argv[3], &endptr, 16);
		size = strtol(argv[4], &endptr, 10);
		all.offset = (char)offset;
		all.size = (char)size;

		ret = ioctl(fd, USB_R_REGS, &all);
		if (ret) {
			printf("reg 0x%x to 0x%x read err\n", offset, (offset+size-1));
		} else {
			printf("===Rreg 0x%x to 0x%x===\n", offset, (offset+size-1));
			for (i=1; i<=size; i++) {
				printf("0x%x\t", all.values[i-1]&0xff);
				if (i%6 == 0)
					printf("\n");
			}
			printf("\n");
		}
	}
	else {
		printf("Please use: r1|w1|rx\n");
		exit(1);
	}

	close(fd);
	exit(0);
}

