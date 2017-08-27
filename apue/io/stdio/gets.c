#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	char str[5];
	
	gets(str);
//	fgets(str,5,stdin);
	puts(str);

	exit(0);
}



