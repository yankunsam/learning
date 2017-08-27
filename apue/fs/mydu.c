#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define NEXTPATHSIZE	1024

static int path_noloop(const char *path)
{
//	/a/b/c/d/f/.   ../../../a/b/c/d/..a..
	char *pos;

	pos = strrchr(path,'/');
	/*if error*/

	if(strcmp(pos+1,".") == 0 || strcmp(pos+1,"..") == 0)
		return 0;

	return 1;

}

static int64_t mydu(const char *path)
{
	int i;
	struct stat statres;
	int64_t sum = 0;
	char nextpath[NEXTPATHSIZE];
	glob_t globres;
	
	if(stat(path,&statres) < 0)
	{
		perror("stat()");
		exit(1);
	}

	if(!S_ISDIR(statres.st_mode)) 
		return statres.st_blocks;

	//path is a dir

	strncpy(nextpath,path,NEXTPATHSIZE);
	strncat(nextpath,"/*",NEXTPATHSIZE);
	glob(nextpath,0,NULL,&globres);
	/*if error*/

	strncpy(nextpath,path,NEXTPATHSIZE);
    strncat(nextpath,"/.*",NEXTPATHSIZE);
	glob(nextpath,GLOB_APPEND,NULL,&globres);
	/*if error*/

	
	for(i = 0 ; i < globres.gl_pathc; i++)
	{	
		if(path_noloop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);
	}
	sum += statres.st_blocks;

	return sum;
}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage....\n");
		exit(1);
	}


	printf("%lld\n",mydu(argv[1])/2);

	exit(0);
}


