/*******************
 * 用户态的buzzer测试
 * $>buzz01 /dev/buzz start (启动pwm)
 * $>buzz01 /dev/buzz stop 	(停止pwm)
 * $>buzz01 /dev/buzz freq 2000 (新的频率)
 * $>buzz01 /dev/buzz duty 3 	(新的占空比)
 * $>buzz01 /dev/buzz high	(增加频率，步长为500)
 * $>buzz01 /dev/buzz low  	(减小频率，步长为500)
 * $>buzz01 /dev/buzz up  	(增加占空比，步长为10%)
 * $>buzz01 /dev/buzz down  (减小占空比，步长为10%)
 * Author: zht
 * Date: 2014-03-26
 *******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define PWM_TYPE	'P'
#define PWM_START	_IO(PWM_TYPE, 1)
#define PWM_STOP	_IO(PWM_TYPE, 2)
#define PWM_SET_FREQ	_IOW(PWM_TYPE, 3, int)
#define PWM_SET_DUTY	_IOW(PWM_TYPE, 4, int)
#define PWM_HIGH	_IO(PWM_TYPE, 5)
#define PWM_LOW		_IO(PWM_TYPE, 6)
#define PWM_UP		_IO(PWM_TYPE, 7)
#define PWM_DOWN	_IO(PWM_TYPE, 8)


int main(int argc, void **argv)
{
	int fd, ret, value;
		
	//打开设备文件
	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		printf("open %s error\n", argv[1]);
		exit(1);
	}
	printf("open %s\n", argv[1]);

	//根据参数执行对应行为
	if (strncmp("start", argv[2], 5) == 0) {
		ioctl(fd, PWM_START);
		printf("Start buzz ...\n");
	}
	else if (strncmp("stop", argv[2], 4) == 0) {
		ioctl(fd, PWM_STOP);
		printf("Stop buzz ...\n");
	}
	else if (strncmp("freq", argv[2], 4) == 0) {
		value = atoi(argv[3]);
		ioctl(fd, PWM_SET_FREQ, value);
		printf("Set buzz frequency to %d\n", value);
	}
	else if (strncmp("duty", argv[2], 4) == 0) {
		value = atoi(argv[3]);
		ioctl(fd, PWM_SET_DUTY, value);
		printf("Set buzz duty to %d\n", value);
	}
	else if (strncmp("high", argv[2], 4) == 0) {
		ioctl(fd, PWM_HIGH);
		printf("Tune higher ...\n");
	}
	else if (strncmp("low", argv[2], 3) == 0) {
		ioctl(fd, PWM_LOW);
		printf("Tune lower ...\n");
	}
	else if (strncmp("up", argv[2], 2) == 0) {
		ioctl(fd, PWM_UP);
		printf("volumn up ...\n");
	}
	else if (strncmp("down", argv[2], 4) == 0) {
		ioctl(fd, PWM_DOWN);
		printf("Volumn down ...\n");
	}
	else {
		printf("Please use $>buzz01 /dev/buzz start|stop|freq|duty|high|low|up|down ...\n");
		exit(1);
	}

	close(fd);
	exit(0);
}	

