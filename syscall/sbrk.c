#include<stdio.h>
#include <unistd.h>
int main(void){
	intptr_t i = 20;
	long n;
	n = (long )sbrk(i);
	printf("%u   %ld\n",n,n);
	return 0;

}
