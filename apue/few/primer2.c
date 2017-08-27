#include <stdio.h>
#include <stdlib.h>

#define LEFT		30000000
#define RIGHT		30000200

int main()
{
		int i,j,mark;
		pid_t pid;

		for(i = LEFT; i <= RIGHT; i++)
		{
				pid = fork();
				if(pid < 0)
				{
						perror("fork()");
						exit(1);
				}
				if(pid == 0)	// child
				{
						mark = 1;
						for(j = 2; j < i/2 ; j++)
						{
								if(i % j == 0)
								{
										mark = 0;
										break;		
								}
						}

						if(mark)
								printf("%d is a primer.\n",i);
			//			sleep(1000);
						exit(0);
				}
		}

		int st;
		for(i = LEFT; i <= RIGHT; i++)
	//		wait(&st);
			wait(NULL);

//		sleep(1000);
		exit(0);
}


