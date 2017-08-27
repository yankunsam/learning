/***********************
 * 用户态对缓冲区的测试例子
 * $>user01 /dev/xxx reset
 * $>user01 /dev/xxx resize 200
 * Author: zht
 * Date: 2014-11-03
 ***********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//ioctl命令号来自于驱动
#define MEM_TYPE	'Z'
#define MEM_RESET	_IO(MEM_TYPE, 1)
#define MEM_RESIZE	_IOW(MEM_TYPE, 2, int)

int main(int argc, char *argv[])
{
	int fd, ret = 0, value;

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("open %s error\n", argv[1]);
		exit(1);
	}

	if (strncmp(argv[2], "reset", 5) == 0) {		
		ret = ioctl(fd, MEM_RESET);
		printf("Reset %s ok\n", argv[2]);
	}	
	else if (strncmp(argv[2], "resize", 6) == 0) {
		value = atoi(argv[3]);
		ret = ioctl(fd, MEM_RESIZE, value);
		printf("Resize %s to %d bytes\n", argv[2], value);
	}
	else {
		printf("Please use $>user01 reset|resize xxx\n");
	}

	return ret;
}

