/*********************
 * 利用ioctl实现灯的闪烁
 * $>led02 /dev/ledx start 200 (间隔200tick)
 * $>led02 /dev/ledx stop (停止闪烁)
 * $>led02 /dev/ledx interval 500 (新间隔)
 * author: zht
 * date: 2014-03-31
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define LED_TYPE	'L'
#define LED_START	_IOW(LED_TYPE,1,int)
#define LED_STOP	_IO(LED_TYPE,2)
#define LED_INTERVAL	_IOW(LED_TYPE,3,int)

int main(int argc, char **argv)
{
	int fd, interval;

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", argv[1]);
		exit(1);
	}
	printf("open %s\n", argv[1]);

	//start
	if (strncmp("start", argv[2], 5) == 0) {
		interval = atoi(argv[3]);
		if (interval > 1000) {
			printf("Time is too long\n");
			exit(1);
		}
		ioctl(fd, LED_START, interval);
	}
	else if (strncmp("stop", argv[2], 4) == 0) {
		ioctl(fd, LED_STOP);
	}
	else if (strncmp("interval", argv[2], 8) == 0) {
		interval = atoi(argv[3]);
		if (interval > 2000) {
			printf("Time is too long\n");
			exit(1);
		}
		ioctl(fd, LED_INTERVAL, interval);
	}
	else {
		printf("Please use: $>led02 start|stop|interval ticks\n");
		exit(1);
	}

	close(fd);
	exit(0);
}

