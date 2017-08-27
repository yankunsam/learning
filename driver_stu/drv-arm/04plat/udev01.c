/**********************
 * simple udevd
 * 显示内核设备模型部分通过netlink向用户态广播的信息
 * Author: zht
 * Date: 2014-06-20
 **********************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <linux/netlink.h>
#include <sys/time.h>

#define UEVENT_MSG_LEN 1024
#define SCM_CREDENTIALS	2

struct ucred {
	__u32	pid;
	__u32	uid;
	__u32	gid;
};

struct uevent {
	const char *action;
	const char *path;
	const char *subsystem;
	const char *firmware;
	int major;
	int minor;
};



/*************************
 * msg中是从内核接收到的信息
 * 解读msg，存入uevent结构体
 *************************/
static void 
parse_event(const char *msg, struct uevent *uevent)
{
	uevent->action = "";
	uevent->path = "";
	uevent->subsystem = "";
	uevent->firmware = "";
	uevent->major = -1;
	uevent->minor = -1;

	/* 每次循环从msg中解读出一个选项，忽略SEQNUM */
	while(*msg) {
		if(!strncmp(msg, "ACTION=", 7)) {
			msg += 7;
			uevent->action = msg;
		} else if(!strncmp(msg, "DEVPATH=", 8)) {
			msg += 8;
			uevent->path = msg;
		} else if(!strncmp(msg, "SUBSYSTEM=", 10)) {
			msg += 10;
			uevent->subsystem = msg;
		} else if(!strncmp(msg, "FIRMWARE=", 9)) {
			msg += 9;
			uevent->firmware = msg;
		} else if(!strncmp(msg, "MAJOR=", 6)) {
			msg += 6;
			uevent->major = atoi(msg);
		} else if(!strncmp(msg, "MINOR=", 6)) {
			msg += 6;
			uevent->minor = atoi(msg);
		}

		/* 不同的选项间用\0分隔，前进到下一个选项 */
		while(*msg++)
			;
	}

	printf("event { '%s', '%s', '%s', '%s', %d, %d }\n",
		uevent->action, uevent->path, uevent->subsystem,
		uevent->firmware, uevent->major, uevent->minor);
}


/***********************
 * 用iovec记录一个缓冲区及其大小
 ***********************/
void handle_device_fd(int fd)
{
	printf("enter %s\n", __func__);
	for(;;) 
	{
		char msg[UEVENT_MSG_LEN+2];
		char cred_msg[CMSG_SPACE(sizeof(struct ucred))];
		struct iovec iov = {msg, sizeof(msg)};
		struct sockaddr_nl snl;
		struct msghdr hdr = {&snl, sizeof(snl), &iov, 1, cred_msg, sizeof(cred_msg), 0};

		ssize_t n = recvmsg(fd, &hdr, 0);
		if (n <= 0) {
			break;
		}

		/* ignore non-kernel netlink multicast message */
		if ((snl.nl_groups != 1) || (snl.nl_pid != 0))
			continue;

		struct cmsghdr *cmsg = CMSG_FIRSTHDR(&hdr);

		/* no sender credentials received, ignore message */
		if (cmsg == NULL || cmsg->cmsg_type != SCM_CREDENTIALS)
			continue;

		struct ucred * cred = (struct ucred *)CMSG_DATA(cmsg);
		if (cred->uid != 0) {
			/* message from non-root user, ignore */
			continue;
		}

		if(n >= UEVENT_MSG_LEN) /* overflow -- discard */
			continue;

		msg[n] = '\0';
		msg[n+1] = '\0';

		struct uevent uevent;
		parse_event(msg, &uevent);
	}
}


int main(void)
{
	struct sockaddr_nl addr;
	int sz = 64*1024;
	int on = 1;
	int sfd;

	sfd = socket(AF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
	if(sfd < 0)
		return -1;

	//设置socket API级别的操作
	//接收缓冲区64KB，支持cred
	setsockopt(sfd, SOL_SOCKET, SO_RCVBUFFORCE, &sz, sizeof(sz));
	setsockopt(sfd, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on));

	/* init source netlink address */
	memset(&addr, 0, sizeof(addr));
	addr.nl_family = AF_NETLINK;
	addr.nl_pid = getpid();
	addr.nl_groups = 0xffffffff;

	if (bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(sfd);
		return -1;
	}

	//循环接收uevent数据
	handle_device_fd(sfd);
}


