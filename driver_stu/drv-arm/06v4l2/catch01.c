/*****************************
 * 裸图片的捕获(YUV422)
 * 用法：
 * $>capture01
 * $>capture01 /dev/video0
 * 直接存储YUV422格式的文件
 * Author: zht
 * Date: 2015-01-23
 *****************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEF_DEV "/dev/video0"
#define DEF_DIR	"./pics"

#define WIDTH		640
#define HEIGHT		480
#define NAME_SIZE	30
#define FILE_SIZE	100
#define MMAP_BUFFERS	4
#define FRAME_CNT	10

struct v4l2_capability cap;
enum v4l2_buf_type type;
struct v4l2_requestbuffers req;
struct v4l2_buffer buf;
char dev_name[NAME_SIZE+1] = {0};
char file_name[FILE_SIZE+1] = {0};
char *yuv422_buf;  //存储yuv422格式的图片
int buf_size;

struct buf_info {
	int size;
	char *ptr;
};
struct buf_info buffers[MMAP_BUFFERS];

//将缓冲区的内容存入文件
int save_to_file(char *pic, int size, int num)
{
	int fd, ret, retw;
	snprintf(file_name, FILE_SIZE, "%s/pic%d.yuv", \
		DEF_DIR, num);
	printf("store to file %s\n", file_name);
	
	//创建新文件
	fd = open(file_name, O_CREAT | O_WRONLY, 0666);
	if (fd == -1)
		return -1;

	//将数据写入文件
	retw = 0;
	while (retw < size) {
		ret = write(fd, pic+retw, size-retw);
		if (ret == -1) {
			if (errno == EINTR)
				continue;
			printf("write %s error\n", file_name);
			return -1;
		}
		retw += ret;
	}
			
	return 0;
}


int main(int argc, char *argv[])
{
	int fd, ret, i;

	if (argc == 1) {
		snprintf(dev_name, NAME_SIZE, DEF_DEV);
	}
	else if (argc == 2) {
		snprintf(dev_name, NAME_SIZE, argv[1]);
	}
	else {
		printf("Use $>catch01 /dev/xxx\n");
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

	printf("Mmap %d frames:\n", req.count);
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
	printf("===========================\n");

	//分配图片缓冲区
	buf_size = WIDTH * HEIGHT * 2;
	yuv422_buf = (char *)malloc(buf_size);
	if (!yuv422_buf) {
		printf("Sufficient memory\n");
		goto out;
	}
	printf("Alloc buf:\n");
	printf("yuv422_buf: 0x%p; %dbytes\n", \
		yuv422_buf, buf_size);
	printf("=============================\n");
	
	//从video设备获得frame
	for (i = 0; i < FRAME_CNT; i++) {
		memset(yuv422_buf, 0, buf_size);
		memset(&buf, 0, sizeof(struct v4l2_buffer));
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i % MMAP_BUFFERS;

		ret = ioctl(fd, VIDIOC_QBUF, &buf);
		if (ret == -1) {
			printf("VIDIOC_QBUF error\n");
			//continue;
		}

		ret = ioctl(fd, VIDIOC_DQBUF, &buf);
		if (ret == -1) {
			printf("VIDIOC_DQBUF error\n");
			continue;
		}
		printf("DQBUF %d: index %d; offset %d\n", \
			i, buf.index, buf.m.offset);
		memcpy(yuv422_buf, buffers[buf.index].ptr, buf_size);
		ret = save_to_file(yuv422_buf, buf_size, i);
		if (ret) {
			printf("Cannot save to file\n");
		}
	}

	free(yuv422_buf);
	close(fd);
	return 0;
out:	
	free(yuv422_buf);
	close(fd);
	exit(1);
}


