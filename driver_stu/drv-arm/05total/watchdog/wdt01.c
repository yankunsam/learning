/*******************
 * 用户态的watchdog测试
 * $>wdt01 help (显示下列内容)
 * $>wdt01 /dev/wdt0 on  (启动看门狗)
 * $>wdt01 /dev/wdt0 off (停止看门狗)
 * $>wdt01 /dev/wdt0 feed (喂狗)
 * $>wdt01 /dev/wdt0 time 20 (新间隔秒数)
 * $>wdt01 /dev/wdt0 reset (不喂狗则咬死)
 * $>wdt01 /dev/wdt0 irq (不喂狗则产生中断)
 * Author: zht
 * Date: 2014-04-08
 *******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define MODE_IRQ	1
#define MODE_RESET	2

#define WDT_TYPE	'W'
#define WDT_ON		_IO(WDT_TYPE, 1)
#define WDT_OFF		_IO(WDT_TYPE, 2)
#define WDT_FEED	_IO(WDT_TYPE, 3)
#define WDT_CHGTIME 	_IOW(WDT_TYPE, 4, int)
#define WDT_CHGMODE	_IOW(WDT_TYPE, 5, int)

int main(int argc, void **argv)
{
	int fd, ret, interval;

	if (strncmp(argv[1], "help", 4) == 0) {
		printf("$>wdt01 /dev/wdt0 on\n");
		printf("$>wdt01 /dev/wdt0 off\n");
		printf("$>wdt01 /dev/wdt0 feed\n");
		printf("$>wdt01 /dev/wdt0 time 20\n");
		printf("$>wdt01 /dev/wdt0 reset\n");
		printf("$>wdt01 /dev/wdt0 irq\n");
		exit(0);
	}
 	else {
		//打开设备文件
		fd = open(argv[1], O_RDWR);
		if (fd == -1) {
			printf("open %s error\n", argv[1]);
			exit(1);
		}
		printf("open %s\n", argv[1]);
	}

	//根据参数执行对应行为
	if (strncmp("on", argv[2], 2) == 0) {
		ioctl(fd, WDT_ON);
		printf("WDT opened\n");
	}
	else if (strncmp("off", argv[2], 3) == 0) {
		ioctl(fd, WDT_OFF);
		printf("WDT stopped\n");
	}
	else if (strncmp("feed", argv[2], 4) == 0) {
		ioctl(fd, WDT_FEED);
		printf("WDT is sufficed\n");
	}
	else if (strncmp("time", argv[2], 4) == 0) {
		interval = atoi(argv[3]);
		ioctl(fd, WDT_CHGTIME, interval);
		printf("You should feed dog in %d seconds\n", interval);
	}
	else if (strncmp("reset", argv[2], 5) == 0) {
		ioctl(fd, WDT_CHGMODE, MODE_RESET);
		printf("Don't forget to feed me(bite you)\n");
	}
	else if (strncmp("irq", argv[2], 3) == 0) {
		ioctl(fd, WDT_CHGMODE, MODE_IRQ);
		printf("Don't forget to feed me(warn you)\n");
	}
	else {
		printf("Please use $>wdt01 help\n");
		exit(1);
	}

	close(fd);
	exit(0);
}

