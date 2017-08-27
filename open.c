#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    open("sam",O_RDONLY);
    printf("errno is %d\n",errno);
}
