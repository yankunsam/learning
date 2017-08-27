#include<stdio.h>
#include <unistd.h>
#include <errno.h>
int main(void){
	intptr_t i = 20;
	long n;
	n = (long )sbrk(ifs);
	printf("%u   %ld\n",n,n);
    printf("errno = %d\n",errno);
	return 0;

}
