#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc,char *argv)
{
    const char *p ="baidu.com";
    struct addrinfo add_host;
    struct addrinfo *add;
    int ret;
    struct addrinfo hints;
    char *s;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    ret = getaddrinfo(p,"http",&hints,&add);
    if(ret != 0){
       fprintf(stderr,"getaddrinfo:%s\n",gai_strerror(ret));
       exit(0);
    }
    s = inet_ntoa(((struct sockaddr_in *)(add->ai_addr))->sin_addr);
    printf("%s\n",s);
    printf("the end\n");
    exit(0);
}
