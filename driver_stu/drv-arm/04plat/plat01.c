/*********************
 * 寄存器raw驱动的测试程序
 * $>plat01 /dev/raw0 r 0x4
 * $>plat01 /dev/raw0 w 0x4 0x5 //向偏移0x4写入0x5
 * 参数为设备文件名和寄存器偏移
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//定义ioctl命令
//利用命令参数传递寄存器偏移和值
struct one_reg {
	int offset;
	int value;
};

#define PLAT_TYPE	'P'
#define GET_REG		_IOW(PLAT_TYPE, 1, struct one_reg)
#define SET_REG		_IOW(PLAT_TYPE, 2, struct one_reg)


int main(int argc, char **argv)
{
	int fd, offset;
	char *end;
	struct one_reg reg = {0};

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		perror(argv[1]);
		exit(1);
	}

	//获得寄存器偏移
	offset = strtoul(argv[3], &end, 16);
	if (offset > 0x1000) {
		printf("Please use 0~0x1000\n");
		exit(1);
	}

	//根据argv[2]判断是读还是写
	if (argv[2][0] == 'r') {
		reg.offset = offset;
		ioctl(fd, GET_REG, &reg);
		printf("R 0x%x = 0x%x\n", offset, reg.value);
	} 
	else if (argv[2][0] == 'w') {
		reg.offset = offset;
		reg.value = strtoul(argv[4], &end, 16);
		ioctl(fd, SET_REG, &reg);
		printf("W 0x%x = 0x%x\n", reg.offset, reg.value);
	}
	else {
		printf("Use: $>plat01 /dev/xxx r|w offset value\n");
		exit(1);
	}

	close(fd);
	exit(0);
}

