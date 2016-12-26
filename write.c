#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char *buf = "davef";
int main(void)
{
    write(1,buf,strlen(buf));
    printf("%s\n",buf);
    exit(1);
}
