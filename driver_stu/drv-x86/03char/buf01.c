/*********************
 * 用户态的ioctl测试
 * $>buf01 /dev/char0 reset
 * $>buf01 /dev/char0 resize 500
 * Author: zht
 * Date: 2015-04-16
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//要从驱动中获得ioctl号的定义
#define BUF_TYPE	'B'
#define BUF_RESET	_IO(BUF_TYPE, 1)
#define BUF_RESIZE	_IOW(BUF_TYPE, 2, int)

int main(int argc, char *argv[])
{
	int fd, ret, value;

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", argv[1]);
		exit(1);
	}

	if (strncmp(argv[2], "reset", 5)==0) {
		ret = ioctl(fd, BUF_RESET);
	}
	else if (strncmp(argv[2], "resize", 6)==0) {
		value = atoi(argv[3]);
		ret = ioctl(fd, BUF_RESIZE, value);
	}
	else {
		printf("Please use reset|resize\n");
		exit(1);
	}

	if (ret == 0)
		printf("ioctl %s OK\n", argv[2]);
	else
		printf("ioctl %s Error\n", argv[2]);
	exit(0);
}


