/*****************************
 * 对video设备执行mmap
 * 用法：
 * $>mmap01
 * $>mmap01 /dev/video0
 * Author: zht
 * Date: 2015-01-23
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV 	"/dev/video0"
#define SIZE		30
#define MMAP_BUFFERS	4

struct v4l2_capability cap;
enum v4l2_buf_type type;
struct v4l2_requestbuffers req;
struct v4l2_buffer buf;
char dev_name[SIZE+1] = {0};

struct buf_info {
	int size;
	char *ptr;
};
struct buf_info buffers[MMAP_BUFFERS];


int main(int argc, char *argv[])
{
	int fd, ret, i;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
	}
	else if (argc == 2) {
		snprintf(dev_name, SIZE, argv[1]);
	}
	else {
		printf("Use $>mmap01 /dev/xxx\n");
		exit(1);
	}

	//打开视频文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("===open %s===\n", dev_name);

	//测试设备是否支持流式访问
	ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
	if (ret < 0) {
		printf("Cannot support VIDIOC_QUERYCAP\n");
		goto out;
	}
	if (!(cap.capabilities & V4L2_CAP_STREAMING)) {
		printf("Not stream device, cannot mmap\n");
		goto out;
	}

	//执行命令VIDIOC_REQBUFS
	req.count = MMAP_BUFFERS;
	req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory = V4L2_MEMORY_MMAP;

	ret = ioctl(fd, VIDIOC_REQBUFS, &req);
	if (ret == -1) {
		printf("Error requesting buffers %d for memory map. VIDIOC_REQBUFS", req.count);
		goto out;
	}

	printf("mmap information: \n");
	printf("support mmap %d frames\n", req.count);
	if (req.count < MMAP_BUFFERS) {
		printf("Insufficient buffer memory.");
		goto out;
	}

	//为每个frame执行mmap
	//执行命令VIDIOC_QUERYBUF以及VIDIOC_QBUF
	for (i = 0; i < req.count; i++) {
		memset(&buf, 0, sizeof(struct v4l2_buffer));
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		ret = ioctl(fd, VIDIOC_QUERYBUF, &buf);
		if (ret == -1) {
			printf("Error querying buffer %d (VIDIOC_QUERYBUF)", i);
			goto out;
		}

		buffers[i].size = buf.length;
		buffers[i].ptr = mmap(NULL, buf.length, \
				PROT_READ | PROT_WRITE, \
				MAP_SHARED, \
				fd, buf.m.offset);
		if (buffers[i].ptr == MAP_FAILED) {
			printf("Error mapping buffer %i", i);
			goto out;
		}

		ret = ioctl(fd, VIDIOC_QBUF, &buf);
		if (ret == -1) {
			printf("buffer index %d error. (VIDIOC_QBUF)", buf.index);
			goto out;
		}

		printf("mmap %d: %dbytes, offset in %d\n", \
			buf.index, buf.length, buf.m.offset);
		printf("map to 0x%p\n", buffers[i].ptr);
	}

	//执行命令VIDIOC_STREAMON
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	ret = ioctl(fd, VIDIOC_STREAMON, &type);
	if (ret == -1) {
		printf("Stream on error (VIDIOC_STREAMON)\n");
		goto out;
	}
	printf("%s: Stream on\n", dev_name);

	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}


