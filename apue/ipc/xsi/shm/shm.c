#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

#define MEMSIZE		1024

int main()
{
	char *str;
	pid_t pid;
	int shmid;

	shmid = shmget(IPC_PRIVATE,MEMSIZE,0600);
	if(shmid < 0)
	{
		perror("shmget()");
		exit(1);
	}

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	
	if(pid == 0)		// child write
	{
		str = shmat(shmid,NULL,0);
		if(str == (void *) -1)	
		{
			perror("shmat()");
			exit(1);
		}
		strcpy(str,"Hello!");
		if(shmdt(str) < 0)
		{
			perror("shmdt()");
			exit(1);
		}
		exit(0);
	}
	else				// parent read
	{
		wait(NULL);
		str = shmat(shmid,NULL,0);
        if(str == (void *) -1)
        {
            perror("shmat()");
            exit(1);
        }
		puts(str);
		if(shmdt(str) < 0)
        {
            perror("shmdt()");
            exit(1);
        }		
		shmctl(shmid,IPC_RMID,NULL);
		exit(0);
	}

}





