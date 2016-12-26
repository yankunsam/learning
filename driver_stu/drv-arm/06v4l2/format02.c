/******************************
 * 选定视频设备的格式以及图片的宽高
 * USB摄像头一般只支持YUV422(YUYV)格式
 * 对于普通的摄像头来说，最高可支持的分辨率是640*480;
 * 实验时352*288以及320*240也可以;
 * $>format02
 * $>format02 /dev/video0 YUYV 640 480
 * 参数1：设备文件名，默认为video0
 * 参数2：不同的图片格式，默认为YUYV
 * 	可以支持的格式为"JPEG","RGB24","UYVY","YUYV","YUV420"
 * 参数3：图片的宽度，默认640
 * 参数4：图片的高度，默认480
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
#define DEF_FORMAT	"YUYV"
#define DEF_WIDTH	640
#define DEF_HEIGHT	480
#define SIZE		30

//视频设备常用的格式，定义在videodev2.h中
//注释中是该格式的名字
unsigned int supported_formats[] = {
        V4L2_PIX_FMT_JPEG,	//"JPEG", JFIF JPEG
        V4L2_PIX_FMT_RGB24,	//"RGB3", RGB888, 24bit
        V4L2_PIX_FMT_UYVY,	//"UYVY", YUV4:2:2, 16bit
        V4L2_PIX_FMT_YUYV,	//"YUYV", YUV4:2:2, 16bit
        V4L2_PIX_FMT_YUV420,	//"YU12", YUV420 12bit
};
 
struct v4l2_format fmt = {0};
char dev_name[SIZE+1] = {0};
char fmt_name[SIZE+1] = {0};
int width, height;
int index_fmt, pixformat;


int main(int argc, char *argv[])
{
	int fd, ret;

	if (argc == 1) {
		snprintf(dev_name, SIZE, DEF_DEV);
		snprintf(fmt_name, SIZE, DEF_FORMAT);
		width = DEF_WIDTH;
		height = DEF_HEIGHT;
	}
	else if (argc == 5) {
		snprintf(dev_name, SIZE, argv[1]);
		snprintf(fmt_name, SIZE, argv[2]);
		width = atoi(argv[3]);
		height = atoi(argv[4]);
	}
	else {
		printf("Use $>std01 /dev/video0 YUYV 640 480\n");
		exit(1);
	}

	//确定是否支持给定的format
	if (strncmp(fmt_name, "JPEG", 4) == 0) {
		index_fmt = 0;
	}
	else if (strncmp(fmt_name, "RGB24", 5) == 0) {
		index_fmt = 1;
	}
	else if (strncmp(fmt_name, "UYVY", 4) == 0) {
		index_fmt = 2;
	}
	else if (strncmp(fmt_name, "YUYV", 4) == 0) {
		index_fmt = 3;
	}
	else if (strncmp(fmt_name, "YUV420", 6) == 0) {
		index_fmt = 4;
	}
	else {
		printf("Cannot support format %s\n", fmt_name);
		exit(1);
	}
	pixformat = supported_formats[index_fmt];

	//打开设备文件
	fd = open(dev_name, O_RDWR);
	if (fd == -1) {
		printf("Cannot open %s\n", dev_name);
		exit(1);
	}
	printf("=====open %s; format %s=====\n", \
			dev_name, fmt_name);

	//初始化v4l2_format结构体
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.pixelformat = pixformat;
	fmt.fmt.pix.field = V4L2_FIELD_ANY;

	//执行命令VIDIOC_G_FMT
	ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
	if (ret == -1) {
		printf("Cannot get this format\n");
		goto out;
	}
	printf("Get format %c%c%c%c (%dx%d)\n", \
			pixformat >> 0, pixformat >> 8, \
			pixformat >> 16, pixformat >> 24, \
			fmt.fmt.pix.width, fmt.fmt.pix.height);


	//初始化v4l2_format结构体
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width = width;
	fmt.fmt.pix.height = height;
	fmt.fmt.pix.pixelformat = pixformat;
	fmt.fmt.pix.field = V4L2_FIELD_ANY;

	//执行命令VIDIOC_TRY_FMT
	ret = ioctl(fd, VIDIOC_TRY_FMT, &fmt);
	if ((ret != -1) &&
			(fmt.fmt.pix.pixelformat == pixformat)) {
		printf("Try format %c%c%c%c (%dx%d)\n", \
				pixformat >> 0, pixformat >> 8, \
				pixformat >> 16, pixformat >> 24, \
				width, height);

		if (fmt.fmt.pix.width != width ||
				fmt.fmt.pix.height != height) {
			printf("Adjust resolution from %ix%i to %ix%i.\n", \
					width, height, \
					fmt.fmt.pix.width, fmt.fmt.pix.height);
			width = fmt.fmt.pix.width;
			height = fmt.fmt.pix.height;
		}
	}
	else {	
		printf("Try format %c%c%c%c (%dx%d) error\n", \
			pixformat >> 0, pixformat >> 8, \
			pixformat >> 16, pixformat >> 24, \
			width, height);
		goto out;
	}

	//执行命令VIDIOC_S_FMT
	ret = ioctl(fd, VIDIOC_S_FMT, &fmt);
		if (ret == -1) {
			printf("Set pixel format error VIDIOC_S_FMT\n");
			goto out;
		}
	printf("Using format %c%c%c%c (%dx%d)\n"
		"bytesperlines %dB; sizeimage %dB;\n"
		"colorspace %08x\n",
		pixformat >> 0, pixformat >> 8, \
		pixformat >> 16, pixformat >> 24, \
		width, height, \
		fmt.fmt.pix.bytesperline, \
		fmt.fmt.pix.sizeimage, \
		fmt.fmt.pix.colorspace);

	close(fd);
	return 0;
out:
	close(fd);
	exit(1);
}


