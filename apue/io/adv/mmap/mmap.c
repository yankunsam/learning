#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define FNAME		"/etc/services"


int main()
{
	int count = 0;
	int fd,i;
	struct stat statres;
	char *str;

	fd = open(FNAME,O_RDONLY);
	if(fd < 0)
	{
		perror("open()");
		exit(1);
	}

	if(fstat(fd,&statres) < 0)
	{
		perror("fstat()");
		exit(1);
	}

	str = mmap(NULL,statres.st_size,PROT_READ,MAP_SHARED,fd,0);	
	if(str == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}

	close(fd);

	for(i = 0 ; i < statres.st_size ; i++)
		if(str[i] == 'a')
			count++;		

	printf("%d\n",count);

	munmap(str,statres.st_size);

	exit(0);
}





