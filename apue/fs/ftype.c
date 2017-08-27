#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int ftype(const char *fname)
{
	struct stat statres;

	if(lstat(fname,&statres) < 0)
	{
		perror("stat()");
		exit(1);
	}

	if(S_ISREG(statres.st_mode))
		return '-';
	if(S_ISDIR(statres.st_mode))
		return 'd';
	if(S_ISCHR(statres.st_mode))
		return 'c';
	else
		return '?';
	
}


int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage...\n");
		exit(1);
	}
	
	printf("%c\n",ftype(argv[1]));

	exit(0);
}
