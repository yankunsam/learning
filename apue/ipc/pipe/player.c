#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE		1024

int main()
{
	int pfd[2];
	char buf[BUFSIZE];
	pid_t pid;

	/*socket ....*/


	if(pipe(pfd) < 0)
	{
		perror("pipe()");
		exit(1);
	}


	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}

	if(pid == 0)	// child player
	{
		close(pfd[1]);	//关闭管道的写端
		dup2(pfd[0],0);	//将管道的读端作为标准输入的来源
		execl("/usr/local/bin/mpg123","mpg123","-");
		perror("execl()");
		exit(1);

	}
	else			// parent send date to the child	
	{
		close(pfd[0]);	//关闭管道的读端	
		while(1)
		{
			//从网络上接收数据，往管道中写
		}	
		close(pfd[1]);
		wait(NULL);
		exit(0);
	}
}




