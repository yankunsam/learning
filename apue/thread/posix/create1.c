#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void * func(void *p)
{
	while(1)
		pause();
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int i,err;	
	pthread_attr_t attr;

	
	pthread_attr_init(&attr);
	
	pthread_attr_setstacksize(&attr,1024*1024);

	for(i = 0 ; ; i ++)
	{
		err = pthread_create(&tid,&attr,func,NULL);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			break;
		}
		printf("i = %d\n",i);

	}

	
	pthread_attr_destroy(&attr);

	exit(0);
}





