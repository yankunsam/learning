/******************************
 * video设备支持的视频标准测试
 * 电视卡等设备支持，camera一般不支持
 * 用法：
 * $>std01
 * $>std01 /dev/video0 NTSC|SECAM|PAL
 * 参数1：设备文件名，默认为video0
 * 参数2：不同的模拟制式，默认为PAL制式
 * Author: zht
 * Date: 2015-01-23
 ******************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV 	"/dev/video0"
#define DEF_STD		"PAL"
#define SIZE		30

//id中定义PAL & NTSC & SECAM等电视信号的制式
v4l2_std_id std_id = 0;
struct v4l2_standard std = {0};
char dev_name[SIZE+1] = {0};
char std_name[SIZE+1] = {0};


int main(int argc, char *argv[])
{
	int fd, ret;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
		snprintf(std_name, SIZE, DEF_STD);
	}
	else if (argc == 3) {
		snprintf(dev_name, SIZE, argv[1]);
		snprintf(std_name, SIZE, argv[2]);
	}
	else {
		printf("Use $>std01 /dev/xxx xx\n");
		exit(1);
	}

	//打开设备文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("=====open %s=====\n", dev_name);

	//(1)执行命令VIDIOC_G_STD
	ret = ioctl(fd, VIDIOC_G_STD, &std_id);
	if (ret == -1) {
		printf("不支持模拟视频格式(VIDIOC_G_STD)\n");
		std_id = 0; //V4L2_STD_UNKNOWN = 0
		goto out;
	}
	printf("支持模拟视频格式: std_id = 0x%llx\n", std_id);

	//(2)执行命令VIDIOC_ENUMSTD
	std.index = 0;
	while (ioctl(fd, VIDIOC_ENUMSTD, &std) == 0) {
		if (std.id & std_id) {
			printf("- video standard %s", std.name);
			std.index++;
		}
	}

	//(3)执行命令VIDIOC_S_STD
	if (strncmp(std_name,"PAL",3) == 0) {
		std_id = V4L2_STD_PAL;
	}
	else if (strncmp(std_name,"NTSC",4)==0) {
		std_id = V4L2_STD_NTSC;
	}
	else if (strncmp(std_name,"SECAM",5)==0) {
		std_id = V4L2_STD_SECAM;
	}
	else {
		printf("Cannot support std: %s\n", std_name);
		goto out;
	}

	ret = ioctl(fd, VIDIOC_S_STD, &std_id);
	if (ret == -1) {
		printf("Set standard 0x%llx error(VIDIOC_S_STD)\n", std_id);
		goto out;
	}
	printf("Set standard: %s\n", std_name);

	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}

