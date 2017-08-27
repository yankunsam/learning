#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void usage()
{
    printf("getsid pid_number\n");
}
int main(int argc,char* argv[])
{
    pid_t sid;
    int pid_c;
    pid_c = atoi(argv[1]);
    if(argc < 2){
        usage();
        exit(1);
    }
    sid = getsid(pid_c);
    if(sid < 0){
        perror("getsid():");
        exit(2);
    }
    else{
        printf("process:%d <-> session id:%d\n",pid_c,sid);
    }
    exit(0);
}
