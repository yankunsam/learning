/*****************************
 * 改变video设备的控制选项值
 * 包括亮度、对比度、饱和度、色度等
 * 用法：
 * $>ctrl01 -d /dev/video0 -b 80 -c 50 -s 40
 * 参数1：-d 设备名，默认为/dev/video0
 * 参数2：要修改的控制选项及其值。可支持的有：
 * 	-b brightness
 * 	-c contrast
 * 	-s saturation
 *	-h hue
 *	-g gamma
 *	-e exposure
 * USB摄像头目前支持-b, -c, -s, -g
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

#define DEF_DEV 	"/dev/video0"
#define SIZE		30
#define CID_CNT		6

//要测试的控制选项
unsigned int queried_ctrls[CID_CNT] = {
    V4L2_CID_BRIGHTNESS,
    V4L2_CID_CONTRAST,
    V4L2_CID_SATURATION,
    V4L2_CID_HUE,
    V4L2_CID_GAMMA,
    V4L2_CID_EXPOSURE,
};

static char *ctrl_names[CID_CNT] = {
	"Brightness",
	"Contrast",
	"Saturation",
	"Hue",
	"Gamma",
	"Exposure",
};


struct v4l2_queryctrl querys[CID_CNT];
struct v4l2_control ctrls[CID_CNT];
int count = 0;
int ctrl_flags;
char dev_name[SIZE+1] = {0};


int main(int argc, char *argv[])
{
	int c, fd, ret, i;

	while ((c=getopt(argc, argv, "b:c:d:s:h:g:e:"))!=EOF) 
	{
		switch (c) {
		case 'b':
			ctrls[0].id = V4L2_CID_BRIGHTNESS;
			ctrls[0].value = atoi(optarg);
			break;
		case 'c':
			ctrls[1].id = V4L2_CID_CONTRAST;
			ctrls[1].value = atoi(optarg);
			break;
		case 's':
			ctrls[2].id = V4L2_CID_SATURATION;
			ctrls[2].value = atoi(optarg);
			break;
		case 'h':
			ctrls[3].id = V4L2_CID_HUE;
			ctrls[3].value = atoi(optarg);
			break;
		case 'g':
			ctrls[4].id = V4L2_CID_GAMMA;
			ctrls[4].value = atoi(optarg);
			break;
		case 'e':
			ctrls[5].id = V4L2_CID_CONTRAST;
			ctrls[5].value = atoi(optarg);
			break;
		case 'd':
			snprintf(dev_name, SIZE, argv[optind-1]);
			break;
		case '?':
			exit(1);
		}
	}

	if (strlen(dev_name) == 0)
		snprintf(dev_name, SIZE, DEF_DEV);

	//打开视频文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("===open %s===\n", dev_name);

	//执行命令VIDIOC_QUERYCTRL
	//查询设备支持哪些控制选项
	for (i = 0; i < CID_CNT; i++) {
		memset(&querys[i], 0, sizeof(querys[i]));
		querys[i].id = queried_ctrls[i];
		if (ioctl(fd, VIDIOC_QUERYCTRL, &querys[i]))
			continue;
		ctrl_flags |= 1 << i;
	}

	//执行命令VIDIOC_S_CTRL
	//设置新的控制选项值
	for (i = 0; i < CID_CNT; i++) {
		if (ctrls[i].id == 0)
			continue;
		if (!(ctrl_flags & (1<<i))) {
			printf("Cannot support control %s\n", \
			ctrl_names[i]);
			continue;
		}

		switch (querys[i].type) {
		case V4L2_CTRL_TYPE_INTEGER:
			if (ctrls[i].value < querys[i].minimum)
				ctrls[i].value = querys[i].minimum;
			if (ctrls[i].value > querys[i].maximum)
				ctrls[i].value = querys[i].maximum;
			ret = ioctl(fd, VIDIOC_S_CTRL, &ctrls[i]);
			if (ret == -1)
				printf("Set %s error\n", ctrl_names[i]);
			else
				printf("Set %s to value %d\n", ctrl_names[i], ctrls[i].value);
			break;
		case V4L2_CTRL_TYPE_BOOLEAN:
			ctrls[i].value = ctrls[i].value ? 1 : 0;
			ret = ioctl(fd, VIDIOC_S_CTRL, &ctrls[i]);
			if (ret == -1)
				printf("Set %s error\n", ctrl_names[i]);
			else
				printf("Set %s to value %d\n", ctrl_names[i], ctrls[i].value);
			break;
		default:
			printf("%s: type 0x%x not support\n", \
				querys[i].name, querys[i].type);
			break;
		}
	}

	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}

