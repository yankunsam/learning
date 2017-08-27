#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE *fp;
	
	fp = fopen("tmp","w");
	if(fp == NULL)
	{
	//	perror("fopen()");
		fprintf(stderr,"fopen():%s\n",strerror(errno));
		exit(1);
	}
	puts("ok!");	

	fclose(fp);

	exit(0);
}



