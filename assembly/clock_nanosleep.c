#include <stdio.h>
#include <time.h>
#include <errno.h>

int main(){
    struct timespec time_val;
    time_val.tv_sec = 70;
    clock_nanosleep(CLOCK_REALTIME,0,&time_val,NULL);
    printf("errno is %d\n",errno);
    return 10;
}
