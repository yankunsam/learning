#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
int main(int argc,char *argv)
{
    const char *p ="not.baidu.com";
    struct addrinfo add_host;
    struct addrinfo *add;
    int ret;
    ret = getaddrinfo(p,NULL,NULL,&add);
    if(ret != 0){
       fprintf(stderr,"getaddrinfo:%s\n",gai_strerror(ret));
       exit(0);
    }
    printf("the end\n");
    exit(0);
}
