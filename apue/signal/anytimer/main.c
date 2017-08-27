#include <stdio.h>

void f1(void *p)
{
	printf("f1():%s\n",p);
}
void f2(void *p)
{
	printf("f2():%s\n",p);
}

int main()
{// Begin!End!..bbb..aaa...ccc.................

	int job1;

	puts("Begin!");

	job1 = at_addjob(4,f1,"aaa");
	if(job1 < 0)
	{
		fprintf(stderr,"at_addjob():%s\n",strerror(-job1));
		exit(1);
	}
	2,f2,"bbb";
	7,f1,"ccc";
	
	
	10,f2,"xxx"


	puts("End!");

	while(1)
	{
		write(1,".",1);
		sleep(1);
	}

	exit(0);
}



