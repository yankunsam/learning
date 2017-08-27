#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd;
    char buf[1024];
    fd=open("sam",O_RDONLY);
    printf("errno is %d\n",errno);
    read(fd,buf,20);
    printf("%s",buf);
}
