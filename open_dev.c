#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    fd = open("/dev/tty",O_RDWR,0777);
    printf("fd = %d\n",fd);
    exit(0);

}
