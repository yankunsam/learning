#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int main()
{

	alarm(5);
	alarm(1);
	alarm(10);

	
	while(1);
	

	exit(0);

}




