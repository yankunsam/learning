/*********************************
 * 如果摄像头支持RGB格式图像
 * 则将读到的图像写入/dev/fb0(要保证图像不能超出LCD的大小)
 * 对应的摄像头驱动应该支持V4L2的ioctl命令
 * author: zht
 * date: 2012-05-24
 *********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <asm/types.h> 
#include <linux/videodev2.h> /* V4L及V4L2的专用头文件 */
#include <linux/fb.h>

/************************
 * capframe: 	抓取到的frame的计数，用于bmp文件的命名
 * filename: 	/tmp下bmp文件的名字
 * bmpFile: 	打开的文件指针
 * bmp_head: 	32bpp像素的bmp文件格式头(54字节)
 * bmp_head_t: 	16bpp像素的bmp格式文件头(66字节)
 ************************/
static unsigned int capframe = 0;
static unsigned char filename[30];
FILE *bmpFile;
unsigned char bmp_head[54];
unsigned char bmp_head_t[] = {
        0x42,0x4d,0x42,0x58,0x02,0x00,0x00,0x00,0x00,0x00,
        0x42,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0xf0,0x00,
        0x00,0x00,0x40,0x01,0x00,0x00,0x01,0x00,0x10,0x00,
        0x03,0x00,0x00,0x00,0x00,0x58,0x02,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0xe0,0x07,
        0x00,0x00,0x1f,0x00,0x00,0x00
};



/*************************
 * cam_name: 	摄像头的设备文件，为程序的第一个参数
 * cam_fp: 	摄像头设备文件的文件描述符
 * vf_buff: 	存储从摄像头读出的数据的缓冲区
 * 
 * fb_fp: 	/dev/fb0文件的文件描述符
 * fb_addr: 	对/dev/fb0进行mmap后的返回地址
 * width:  	从/dev/fb0中获得的屏幕宽度
 * height: 	从/dev/fb0中获得的屏幕高度
 * fb_bpp: 	从/dev/fb0中获得的屏幕bpp
 *************************/
static char cam_name[50];
static int cam_fp = -1;
static unsigned char *vf_buff;

static int fb_fp = -1;
static char *fb_addr = NULL;
static int width = 0;
static int height = 0;
static int fb_bpp = 0;


/*******************
 * 将缓冲区vf_buff中的数据写入临时文件/tmp/xxx.bmp
 * bmp文件需要一个固定格式的头部
 *******************/
static void 
writeImageToFile(unsigned int size)
{
	capframe++;
	sprintf(filename, "/tmp/0%d.bmp", capframe);

   	bmpFile=fopen(filename, "w+");

	if (fb_bpp == 16)
		fwrite(bmp_head_t, 1, 66, bmpFile);
	else
		fwrite(bmp_head, 1, 54, bmpFile);
   	fwrite(vf_buff, 1, size, bmpFile);

   	fclose(bmpFile);
}


/**************************
 * 打开摄像头的设备文件，返回文件描述符 
 **************************/
static int 
cam_init(void)
{
	int dev_fp = -1;

	dev_fp = open(cam_name, O_RDWR);
	if (dev_fp < 0) {
		printf("error open %s\n",cam_name);
		return -1;
	}

	return dev_fp;
}


/***************************
 * 打开/dev/fb0，并进行mmap
 * 返回文件描述符
 ***************************/
static int 
fb_init(void)
{
	int dev_fp = -1;
	int fb_size;
	struct fb_var_screeninfo vinfo;

	dev_fp = open("/dev/fb0", O_RDWR);
	if (dev_fp < 0) {
		perror("/dev/fb0");
		return -1;
	}

	if (ioctl(dev_fp, FBIOGET_VSCREENINFO, &vinfo)) {
	        printf("Error reading variable information.\n");
		exit(1);
	}

	width = vinfo.xres;
	height = vinfo.yres;
	fb_bpp = vinfo.bits_per_pixel;

	if (fb_bpp == 24) 
		fb_bpp = 32;

	/* 对整个framebuffer进行mmap */
	fb_size = (width * height * fb_bpp) / 8;
	if ((fb_addr = (char *)mmap(0, fb_size, 
			PROT_READ | PROT_WRITE, 
			MAP_SHARED, dev_fp, 0)) < 0) {
		perror("mmap()");
		return -1;
	}
	printf("w:%d; h:%d; bpp:%d; mmap 0x%08x\n",
		width, height, fb_bpp, fb_addr);

	return dev_fp;
}


/*************************
 * 从摄像头的文件描述符中读出一幅图
 *************************/
static int 
read_data(int fp, char *buf, int width, int height, int bpp)
{
	int ret = 0;
	int size = (width * height * bpp) / 8;

	ret = read(fp, buf, size);
	if (ret != size) {
		printf("size 0x%x, read 0x%x\n", size, ret);
		return 0;
	}

	return ret;
}


/**************************
 * 计算每秒钟播放的frame数量(fps)
 * s为起始时间，e为结束时间(s到e间经过30个frame)
 **************************/
static void 
print_fps(struct timeval *s, struct timeval *e)
{
	unsigned long time;
	unsigned long sec;
	unsigned long usec;
	int fps = 0;
	
	/* 计算两个timeval间的间隔，并将结果转换为ms */
	sec = e->tv_sec - s->tv_sec;
	if (e->tv_usec > s->tv_usec) {
		usec = e->tv_usec - s->tv_usec;
	}
	else {
		usec = e->tv_usec + 1000000 - s->tv_usec;	
		sec--;
	}
	time = sec * 1000 + (usec+1) / 1000;
	
	if(time == 0)
	    return;
	
	/* 如果间隔时间1秒(即time为1000ms)，则fps为30 */
	fps = 30000 / time;
	printf("%d fps\n", fps);
}


int main(int argc, char *argv[])
{
	unsigned int frames = 0;
	struct timeval tv1;
	struct timeval start_tv, end_tv;
	struct timezone tz;
	int src_img;
	unsigned long size;
	int index = 0;
	struct v4l2_capability cap;
	struct v4l2_input i;
	struct v4l2_framebuffer fb;
	int on = 1;
	int tmp, m, n;
	fd_set fds1;
	int fd;
	char cmd[256];
	struct fb_var_screeninfo vinfo;

	if(argc != 2) {
		printf("Usage:cam2fb [device node]\n");
		return 0;
	}
	sprintf(cam_name, "%s", argv[1]);

	/* 打开摄像头文件和/dev/fb0 */
	cam_fp = cam_init();
	fb_fp = fb_init();

	/* 从摄像头文件中读取v4l2_capability */
	if ((tmp = ioctl(cam_fp, VIDIOC_QUERYCAP, &cap)) < 0) {
		printf("VIDIOC_QUERYCAP error, ret=0x%x\n",tmp);
		goto err;
	}
	printf("Driver:%s, Card:%s, cap=0x%x\n", 
			cap.driver, cap.card, cap.capabilities);

	/* 从摄像头文件中读取v4l2_input */
	memset(&i, 0, sizeof(i));
	i.index = index;
	if (ioctl(cam_fp, VIDIOC_ENUMINPUT, &i) < 0)
		goto err;
	printf("input name: %s\n", i.name);

	/* 设定摄像头的input和output */
	index = 0;
	if (ioctl(cam_fp, VIDIOC_S_INPUT, &index) < 0)
		goto err;
	if (ioctl(cam_fp, VIDIOC_S_OUTPUT, &index) < 0)
		goto err;

	/* 从摄像头文件中读取v4l2_framebuffer */
	if (ioctl(cam_fp, VIDIOC_G_FBUF, &fb) < 0)
		goto err;

	printf("v4l2_fb: capabilities=0x%x, flags=0x%x\n, \
		width=%d, height=%d, pixelformat=%d\n, \
		bytesperline=%d, colorspace=%d, base=0x%x\n",
		fb.capability, fb.flags,
		fb.fmt.width, fb.fmt.height, fb.fmt.pixelformat,
		fb.fmt.bytesperline, fb.fmt.colorspace, fb.base);

	/* 根据/dev/fb0的设定设置摄像头的v4l2_framebuffer */
	fb.capability = cap.capabilities;
	fb.fmt.width = width;
	fb.fmt.height = height;
	fb.fmt.pixelformat = (fb_bpp == 32) ? V4L2_PIX_FMT_BGR32 : V4L2_PIX_FMT_RGB565;

	if (ioctl(cam_fp, VIDIOC_S_FBUF, &fb)<0)
		goto err;

	/* 使能摄像头的video overlay */
	on = 1;
	if (ioctl(cam_fp, VIDIOC_OVERLAY, &on)<0)
		goto err;

	/* 根据framebuffer的大小分配空间(存储一frame图像) */
	size = (width * height * fb_bpp) / 8;
	vf_buff = (char *)malloc(size);
	if(vf_buff == NULL)
		goto err;

	/* 将图像的高宽信息等写入bmp文件头 */
	if (fb_bpp == 16) { /* 16bpp */
		*((unsigned int *)(bmp_head_t+18)) = width;
		*((unsigned int *)(bmp_head_t+22)) = height;
		*((unsigned short *)(bmp_head_t+28)) = 16;
	}
	else { /* 32bpp */
		bmp_head[0] = 'B';
		bmp_head[1] = 'M';
		*((unsigned int *)(bmp_head+2)) = (width*fb_bpp/8)*height+54;
		*((unsigned int *)(bmp_head+10)) = 54;
		*((unsigned int *)(bmp_head+14)) = 40;
		*((unsigned int *)(bmp_head+18)) = width;
		*((unsigned int *)(bmp_head+22)) = height;
		*((unsigned short *)(bmp_head+26)) = 1;
		*((unsigned short *)(bmp_head+28)) = fb_bpp;
		*((unsigned short *)(bmp_head+34)) = (width*fb_bpp/8)*height;
	}

	gettimeofday(&start_tv, &tz);

	while(1)
	{
		/* 从摄像头中读入一frame */
		if (!read_data(cam_fp, vf_buff, width, height, fb_bpp))
			printf("read error\n");

		int i = 0;

		/* 将从摄像头中读到的图像写入/dev/fb0 */
		memcpy(fb_addr, vf_buff, width*height*fb_bpp/8);
		frames++;
		if ((frames % 30) == 0) {
			gettimeofday(&end_tv, &tz);
			print_fps(&start_tv, &end_tv);
			gettimeofday(&start_tv, &tz);
		}

		/* 从标准输入读命令(开发板上的串口0)
		 * select函数不等待，没有输入则马上返回
		 * "quit": 退出cam2fb程序
		 * "capt": 捕获图像，存储为/tmp/xxx.bmp */
		fd = 0;
		tv1.tv_sec = 0;
		tv1.tv_usec = 0;
		FD_ZERO(&fds1);
		FD_SET(fd, &fds1);
		select(fd+1, &fds1, NULL, NULL, &tv1);

		if (FD_ISSET(fd, &fds1)) {
			memset(cmd, 0, sizeof(cmd));
			read(fd, cmd, 256);
			if (strncmp(cmd, "quit", 4)==0) {
				printf("-->quit\n");
				on=0;
				if (ioctl(cam_fp, VIDIOC_OVERLAY, &on)<0)
					goto err;
				close(fb_fp);
				close(cam_fp);
				return 0;
			} 
			else if (strncmp(cmd, "capt", 4)==0) {
				printf("-->capture\n");
				printf("write to img --> ");
				writeImageToFile(size);
				printf("OK\n");
			}
		}
	}
err:
	if (cam_fp)
		close(cam_fp);
end:
	exit(0);
}

