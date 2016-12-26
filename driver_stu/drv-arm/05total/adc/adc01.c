/*********************
 * 获取adc中给定通道的值
 * $>adc01 /dev/adc get 0 (读通道0的值)
 * author: zht
 * date: 2014-08-22
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>

struct adc_info {
	int ch;
	int value;
	int time;
};

#define TYPE_ADC	'A'
#define ADC_GET_VALUE	_IOW(TYPE_ADC, 1, struct adc_info)


int main(int argc, char **argv)
{
	int fd, ret;
	struct adc_info tmp;

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", argv[1]);
		exit(1);
	}
	printf("open %s\n", argv[1]);

	//读取给定通道的AD值
	if (strncmp("get", argv[2], 3) == 0) {
		tmp.ch = atoi(argv[3]);
		if (tmp.ch >= 4) {
			printf("Only support AD channel 0~3\n");
			exit(1);
		}
		ret = ioctl(fd, ADC_GET_VALUE, &tmp);
		if (ret) {
			printf("Cannot access ch-%d\n", tmp.ch);
		} else {
			printf("Ch-%d: %d, in %ds\n", tmp.ch, tmp.value, tmp.time);
		}
	}
	else {
		printf("Please use: $>adc01 get (0~3)\n");
		exit(1);
	}

	close(fd);
	exit(0);
}

