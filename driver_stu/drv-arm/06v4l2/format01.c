/******************************
 * 遍历显示视频设备支持的格式(format)
 * $>format01
 * $>format01 /dev/video0
 * 参数1：设备文件名，默认为video0
 * 注意！测试的几个USB摄像头都只支持YUYV(YUV422)格式
 * Author: zht
 * Date: 2015-01-23
 ******************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV 	"/dev/video0"
#define SIZE		30
#define	MAX_INDEX	10

 
struct v4l2_fmtdesc fmt = {0};
char dev_name[SIZE+1] = {0};


int main(int argc, char *argv[])
{
	int fd, ret, i;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
	}
	else if (argc == 2) {
		snprintf(dev_name, SIZE, argv[1]);
	}
	else {
		printf("Use $>format01 /dev/xxx\n");
		exit(1);
	}

	//打开设备文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("=====open %s=====\n", dev_name);

	//显示设备支持的所有视频格式
    	fmt.index = 0;
    	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	printf("Supported palettes:\n");

	for (i=0; i<MAX_INDEX; i++) {
		ret = ioctl(fd, VIDIOC_ENUM_FMT, &fmt);
		if (ret == -1) {
			fmt.index = i+1;
			continue;
		}
		printf("[%i]: %c%c%c%c (%s)\n", fmt.index,
		  fmt.pixelformat >> 0, fmt.pixelformat >> 8,
		  fmt.pixelformat >> 16, fmt.pixelformat >> 24, 
		  fmt.description);

		memset(&fmt, 0, sizeof(struct v4l2_fmtdesc));
		fmt.index = i+1;
		fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	}

	close(fd);
	return 0;
}


