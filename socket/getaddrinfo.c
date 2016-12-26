#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
int main(int argc,char *argv)
{
    const char *p ="hell.baidu.com";
    struct addrinfo add_host;
    struct addrinfo *add;
    int ret;
    struct addrinfo hints;
    char *s;
    errno = 0;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    ret = getaddrinfo(p,"httpfsd",&hints,&add);
    if(ret != 0){
        errno = -1;
       fprintf(stderr,"getaddrinfo:%s\n",gai_strerror(-8));
       printf("errno is %d ret is %d\n",errno,ret);
       exit(0);
    }
    s = inet_ntoa(((struct sockaddr_in *)(add->ai_addr))->sin_addr);
    printf("%s\n",s);
    printf("the end\n");
    exit(0);
}
