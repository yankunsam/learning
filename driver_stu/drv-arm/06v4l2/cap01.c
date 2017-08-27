/*****************************
 * 测试video设备的capability
 * 用法：
 * $>cap01
 * $>cap01 /dev/video0
 * Author: zht
 * Date: 2015-01-23
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV "/dev/video0"
#define SIZE	30

struct v4l2_capability cap;
char dev_name[SIZE+1] = {0};

int main(int argc, char *argv[])
{
	int fd, ret;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
	}
	else if (argc == 2) {
		snprintf(dev_name, SIZE, argv[1]);
	}
	else {
		printf("Use $>cap01 /dev/xxx\n");
		exit(1);
	}

	//打开视频文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("===open %s===\n", dev_name);

	//调用命令VIDIOC_QUERYCAP
	ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
	if (ret < 0) {
		fprintf(stderr, "Cannot support VIDIOC_QUERYCAP\n");
		exit(1);
	}

	//打印设备信息
	printf("cap.driver: %s\n", cap.driver);
	printf("cap.card: %s\n", cap.card);
	printf("cap.bus_info: %s\n", cap.bus_info);
	printf("cap.capabilities=0x%08X\n", cap.capabilities);
	
	if (cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)
        	printf("- VIDEO_CAPTURE\n");

	if (cap.capabilities & V4L2_CAP_VIDEO_OUTPUT)
		printf("- VIDEO_OUTPUT\n");

	if (cap.capabilities & V4L2_CAP_VIDEO_OVERLAY)
		printf("- VIDEO_OVERLAY\n");

	if (cap.capabilities & V4L2_CAP_VBI_CAPTURE)
		printf("- VBI_CAPTURE\n");

	if (cap.capabilities & V4L2_CAP_VBI_OUTPUT)
		printf("- VBI_OUTPUT\n");

	if (cap.capabilities & V4L2_CAP_RDS_CAPTURE)
		printf("- RDS_CAPTURE\n");

	if (cap.capabilities & V4L2_CAP_TUNER)
		printf("- TUNER\n");

	if (cap.capabilities & V4L2_CAP_AUDIO)
		printf("- AUDIO\n");

	if (cap.capabilities & V4L2_CAP_READWRITE)
		printf("- READWRITE\n");

	if (cap.capabilities & V4L2_CAP_ASYNCIO)
		printf("- ASYNCIO\n");

	if (cap.capabilities & V4L2_CAP_STREAMING)
		printf("- STREAMING\n");

	if (cap.capabilities & V4L2_CAP_TIMEPERFRAME)
		printf("- TIMEPERFRAME\n");

	close(fd);
	return 0;
}


