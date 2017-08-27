#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
 *缓冲区：绝大多数情况下缓冲区的存在是件好事，作用是合并系统调用
 *
 *行缓冲：换行的时候刷新，满了的时候刷新，强制刷新（标准输入输出都是这样，涉及到了终端设备）

 *全缓冲：满了的时候刷新，强制刷新（默认使用全缓冲，只要不是终端设备）

 *无缓冲：需要立即输出,如stderr
 * */




int main()
{

	printf("[%s:%d]Before while()",__FUNCTION__,__LINE__);
	fflush(NULL);
	
	while(1);
	{

	}

	printf("[%s:%d]After while()\n",__FUNCTION__,__LINE__);


	exit(0);
}



