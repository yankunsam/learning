/*************************
 * LED的用户态测试
 * $>led01 /dev/leds 0|1|2|3 on|off
 * Author: zht
 * Date: 2014-01-23
 *************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define LED_TYPE	'L'
#define LED_ON		_IOW(LED_TYPE, 1, int)
#define LED_OFF		_IOW(LED_TYPE, 2, int)


int main(int argc, char **argv)
{
	int fd;
	int led_num;
	char *endp;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		printf("Cannot open %s\n");
		exit(1);
	}

	led_num = strtol(argv[2], &endp, 10);
	if (led_num > 3) {
		printf("Only support led 0~3\n");
		exit(1);
	}

	if (strncmp(argv[3], "on", 2) == 0) {
		ioctl(fd, LED_ON, led_num);
	}
	else if (strncmp(argv[3], "off", 3) == 0) {
		ioctl(fd, LED_OFF, led_num);
	}
	else {
		printf("Please use $>%s num on|off\n", argv[1]);
		exit(1);
	}

	exit(0);
}

