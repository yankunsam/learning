/******************************
 * 视频input源的检查和选择
 * 如果支持Tuner，还可以设定频率
 * 用法：
 * $>input01
 * $>input01 /dev/video0 0 xx
 * 参数1：设备文件名，默认/dev/video0
 * 参数2：要选择的input源，默认0
 * 参数3：如果支持频率调整(tuner)，则可以设置模拟TV的频率
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
#define DEF_INPUT	0
#define DEF_FREQ	0
#define SIZE		30

struct v4l2_input input = {0};
struct v4l2_tuner tuner = {0};
struct v4l2_frequency freq = {0};

char dev_name[SIZE+1] = {0};
int  dev_input;
int  dev_freq;


int main(int argc, char *argv[])
{
	int fd, ret;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
		dev_input = DEF_INPUT;
		dev_freq = DEF_FREQ;
	}
	else if (argc == 4) {
		snprintf(dev_name, SIZE, argv[1]);
		dev_input = atoi(argv[2]);
		dev_freq = atoi(argv[3]);
	}
	else {
		printf("Please use $>input01 /dev/xxx xx xx\n");
		exit(1);
	}

	//打开视频设备
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("===open %s===\n", dev_name);

	//(1)执行命令VIDIOC_ENUMINPUT
	input.index = dev_input;
	ret = ioctl(fd, VIDIOC_ENUMINPUT, &input);
	if (ret == -1) {
		printf("Query input %d error(VIDIOC_ENUMINPUT)\n", input.index);
		goto out;
	}

	//显示input信息
	printf("Query input %d: \n", input.index);
	printf("name = %s\n", input.name);
	printf("type = 0x%08X\n", input.type);
	printf("status = 0x%08x\n", input.status);
	printf("Type: \n");
	if (input.type & V4L2_INPUT_TYPE_TUNER)
		printf("- TUNER\n");

	if (input.type & V4L2_INPUT_TYPE_CAMERA) 
		printf("- CAMERA\n");

	//(2)执行命令VIDIOC_S_INPUT
	ret = ioctl(fd, VIDIOC_S_INPUT, &input);
	if (ret == -1) {
		printf("Select input %d error(VIDIOC_S_INPUT)", \
			input.index);
		goto out;
	}
	printf("Select input: %d\n", input.index);

	if (!(input.type & V4L2_INPUT_TYPE_TUNER)) {
		printf("Cannot support tuner\n");
		goto out;
	}

	printf("=======================\n");

	//(3)执行命令VIDIOC_G_TUNER	
	tuner.index = input.tuner;
	ret = ioctl(fd, VIDIOC_G_TUNER, &tuner);
	if (ret == -1) {
		printf("Cannot get tuner %d(VIDIOC_G_TUNER)\n", tuner.index);
		goto out;
	}
	printf("Get tuner: %s\n", tuner.name);

	//(4)执行命令VIDIOC_S_FREQUENCY
	freq.tuner = input.tuner;
	freq.type = V4L2_TUNER_ANALOG_TV;
	freq.frequency = (dev_freq / 1000) * 16;

	ret = ioctl(fd, VIDIOC_S_FREQUENCY, &freq);
	if (ret == -1) {
		printf("Set frequency %d error(VIDIOC_S_FREQUENCY)\n", freq.frequency);
		goto out;
	}
	printf("Set tuner %s frequency to %d\n", \
		tuner.name, freq.frequency);
	
	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}

