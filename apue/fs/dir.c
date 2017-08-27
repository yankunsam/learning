#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define PATH 	"/etc"

int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *cur;
	
	dp = opendir(PATH);
	if(dp == NULL)
	{
		perror("opendir()");
		exit(1);
	}
	
	while((cur = readdir(dp)) != NULL)
	{
		puts(cur->d_name);
	}
	

	closedir(dp);

	exit(0);
}




