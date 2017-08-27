#include <stdio.h>

#include <proto.h>

/*
 *  -M  指定多播地址
 *  -P  指定接收端口
 *  -p  指定播放器
 *  -C	指定调试的频道号
 *  -F	前台调试运行
 *  -H  显示帮助
 * */

int main()
{
	struct mlib_chn_st *list;
	int listsize;

	/* conf的处理 */
		getopt();

	/* socket */
		socket();
		setsockopt();
		bind();


	/* 获取频道列表（从medialib中） */
	mlib_getchnlist(&list,&listsize);	 	
	/*if error,syslog */


	/* 创建thr_list */
	thr_list_create();	


	/* 创建thr_channel : N:N*/
	for(i = 0 ; i < listsize; i++)
		thr_channel_create();



	while(1)
		pause();


	exit(0);
}








