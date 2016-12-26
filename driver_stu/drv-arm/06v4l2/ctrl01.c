/*****************************
 * 测试video设备支持的控制选项
 * 包括亮度、对比度、饱和度、色度等
 * 用法：
 * $>ctrl01
 * $>ctrl01 /dev/video0
 * Author: zht
 * Date: 2015-01-23
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV "/dev/video0"
#define SIZE	30

//要测试的控制选项
unsigned int queried_ctrls[] = {
    V4L2_CID_BRIGHTNESS,
    V4L2_CID_CONTRAST,
    V4L2_CID_SATURATION,
    V4L2_CID_HUE,
    V4L2_CID_RED_BALANCE,
    V4L2_CID_BLUE_BALANCE,
    V4L2_CID_GAMMA,
    V4L2_CID_EXPOSURE,
    V4L2_CID_AUTOGAIN,
    V4L2_CID_GAIN,
    0
};

struct v4l2_queryctrl queryctrl = {0};
struct v4l2_control control = {0};
char dev_name[SIZE+1] = {0};
int ctrl_flags;


int main(int argc, char *argv[])
{
	int fd, ret, count, i;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
	}
	else if (argc == 2) {
		snprintf(dev_name, SIZE, argv[1]);
	}
	else {
		printf("Use $>ctrl01 /dev/xxx\n");
		exit(1);
	}

	//打开视频文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("===open %s===\n", dev_name);

	//查询设备支持哪些控制选项
	for (i = 0, count = 0; queried_ctrls[i]; i++) {
		queryctrl.id = queried_ctrls[i];
		if (ioctl(fd, VIDIOC_QUERYCTRL, &queryctrl))
			continue;
		count++;
		ctrl_flags |= 1 << i;
	}
	if (0 == count) {
		printf("%s cannot support any control\n", dev_name);
		goto out;
	} 
	else {
		printf("support %d controls item:\n", count);
	}

	//查看支持的control信息
	for (i = 0; queried_ctrls[i]; i++) {
		if (!(ctrl_flags & (1 << i)))
			continue;
		memset(&queryctrl, 0, sizeof(queryctrl));
		queryctrl.id = queried_ctrls[i];
		if (ioctl(fd, VIDIOC_QUERYCTRL, &queryctrl))
			continue;
		printf("*************************\n");
		printf("found control 0x%08x, %s, " \
			"flag 0x%x\n", \
			queryctrl.id, queryctrl.name, \
			queryctrl.flags);

		memset(&control, 0, sizeof(control));
		control.id = queried_ctrls[i];
		ioctl(fd, VIDIOC_G_CTRL, &control);
		printf("%s--> range %d,%d; " \
			"default %d, current %d\n", \
			queryctrl.name, \
			queryctrl.minimum, queryctrl.maximum, \
			queryctrl.default_value, \
			control.value);
	}

	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}

