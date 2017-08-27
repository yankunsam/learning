#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>


#define RBUFSIZE		1024


int main(int argc,char **argv)
{
	int sd;
	FILE *fp;
	int err;
	int len;
	struct sockaddr_in raddr;
	long long stamp;
	char rbuf[RBUFSIZE];
	struct addrinfo  ai,*res;

	if(argc < 2)
	{
		fprintf(stderr,"Usage...\n");
		exit(1);
	}

	ai.ai_flags = 0;
	ai.ai_family = AF_INET;
	ai.ai_socktype = SOCK_STREAM;
	ai.ai_protocol = 0;
	err = getaddrinfo(argv[1],"http",&ai,&res);
	if(err)
	{
		fprintf(stderr,"getaddrinfo():%s\n",gai_strerror(err));
		exit(1);
	}


	sd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}

	if(connect(sd,res->ai_addr,res->ai_addrlen) < 0)
	{
		perror("connect()");
		exit(1);
	}


	fp = fdopen(sd,"r+");
	if(fp == NULL)
	{
		perror("fdopen()");
		exit(1);
	}


	fprintf(fp,"GET /test.jpg\r\n\r\n");
	fflush(fp);

	while(1)
	{
		len = fread(rbuf,1,RBUFSIZE,fp);
		if(len <= 0)
			break;
		fwrite(rbuf,1,len,stdout);
	}

	fclose(fp); 
	exit(0);
}



