#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void int_handler(int s)
{
	write(1,"!",1);	
}

int main()
{
	int i;

	signal(SIGINT,int_handler);
//	signal(SIGINT,SIG_IGN);

	for(i = 0 ; i < 10 ; i++)
	{
		write(1,"*",1);
		sleep(1);
	}


	exit(0);

}




