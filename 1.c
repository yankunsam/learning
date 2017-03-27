#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=10;
        i = (0 ? 11:12);
	printf("i=%d\n",i);
	return 0;
}
