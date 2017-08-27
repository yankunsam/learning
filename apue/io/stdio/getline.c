#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{



}



int main(int argc,char *argv[])
{
	char *linebuf = NULL;
	size_t linesize = 0;
	FILE *fp;
	
	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s <srcfile> <destfile>\n",argv[0]);
		exit(1);
	}

	fp = fopen(argv[1],"r");
	if(fp = NULL)
	{
		perror("fopen()");
		exit(1);
	}

	while(1)
	{
		if(mygetline(&linebuf,&linesize,fp) < 0)
			break;
		printf("linesize = %d\n",linesize);
		printf("%d\n",strlen(linebuf));
	}

	fclose(fp);
	// free(linebuf);

	exit(0);
}




