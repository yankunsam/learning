#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/mman.h>

#include "proto.h"

#define BUFSIZE				1024
#define IPSTRSIZE			1024
	
#define MAXSERVER			20	
#define MINSPARESERVER		5
#define MAXSPARESERVER		10

#define SIG_NOTIFY			SIGUSR2


enum
{
	STATE_BUSY=1,
	STATE_IDLE
};

struct server_st
{
	pid_t pid;
	int state;
// 	int reuse;	
};

static struct server_st *serverpool;
static int count_idle = 0;
static int coune_busy = 0;
static int sd;


static void usr2_handler(int s)
{
	return ;
}

static void server_job(int pos)
{
	struct sockaddr_in raddr;
	socklen_t raddr_len;
	int newsd;
	char buf[BUFSIZE];
	int len;
	pid_t ppid;	

	ppid = getppid();

	raddr_len = sizeof(raddr);
	while(1)
	{
		serverpool[pos].state = STATE_IDLE;
		kill(ppid,SIG_NOTIFY);

		newsd = accept(sd,(void *)&raddr,&raddr_len);
		if(newsd < 0)
		{
			if(errno == EINTR || errno == EAGAIN)
				continue;
			perror("accept()");
			exit(1);
		}

		serverpool[pos].state = STATE_BUSY;
		kill(ppid,SIG_NOTIFY);

		//     inet_ntop(AF_INET,&raddr.sin_addr,ipstr,IPSTRSIZE);
		//       printf("-----MESSAGE FROM:[%s:%d]-----\n",ipstr,ntohs(raddr.sin_port));
		len = sprintf(buf,FMT_STAMP,(long long)time(NULL));
		if(send(newsd,buf,len,0) < 0)
		{
			perror("send()");
			exit(1);
		}
		sleep(5);
		close(newsd);
	}

	close(sd);

}

static int  add_1_server()
{
	int i;
	pid_t pid;

	if(coune_busy + count_idle >= MAXSERVER)
		return -1;

	for(i = 0 ; i < MAXSERVER; i++)
		if(serverpool[i].pid == -1)
			break;

	serverpool[i].state = STATE_IDLE;
	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		return -1;
	}

	if(pid == 0)		// child
	{
		server_job(i);
		exit(0);
	}
	else				// parent
	{
		serverpool[i].pid = pid;
		count_idle ++;
	}

	return 0;

}


static int del_1_server()
{
	int i;

	if(count_idle <= MINSPARESERVER)
		return -1;

	for(i = 0 ; i < MAXSERVER; i++)
	{
		if(serverpool[i].pid != -1 && serverpool[i].state == STATE_IDLE )
		{
			kill(serverpool[i].pid,SIGTERM);
			serverpool[i].pid = -1;
			count_idle --;
			break;
		}
	}
	
	return 0;
}

static int scan_serverpool()
{
	int i;
	int idle = 0,busy = 0;

	for(i = 0 ; i < MAXSERVER; i++)
	{
		if(serverpool[i].pid == -1)
			continue;
		if(kill(serverpool[i].pid,0))
		{
			serverpool[i].pid = -1;
			continue;
		}	
	
		if(serverpool[i].state == STATE_IDLE)
			idle ++;	
		else if(serverpool[i].state == STATE_BUSY)
				busy++;		
			 else
			 {
				fprintf(stderr,"Unknown state.\n");
				abort();
			 }

	}

	count_idle = idle;
	coune_busy = busy;

	return 0;
}


int main()
{
	int i;
	struct sockaddr_in laddr;
	struct sigaction sa,osa1,osa2;
	sigset_t set,oset;

	sa.sa_handler = usr2_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if(sigaction(SIG_NOTIFY,&sa,&osa1) < 0)
	{
		perror("sigaction()");
		exit(1);
	}

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_NOCLDWAIT;
	if(sigaction(SIGCHLD,&sa,&osa2) < 0)
	{
		perror("sigaction()");
		exit(1);
	}


	sigemptyset(&set);
	sigaddset(&set,SIG_NOTIFY);
	sigprocmask(SIG_BLOCK,&set,&oset);



	sd = socket(AF_INET,SOCK_STREAM,0/*IPPROTO_TCP*/);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}
	
	int val = 1;
	if(setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&val,sizeof(val)) < 0)
	{
		perror("setsockopt()");
		exit(1);
	}


	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(SERVERPORT));
	inet_pton(AF_INET,"0.0.0.0",&laddr.sin_addr);
	if(bind(sd,(void *)&laddr,sizeof(laddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	if(listen(sd,200) < 0)
	{
		perror("listen()");
		exit(1);
	}

	serverpool = mmap(NULL,sizeof(struct server_st)*MAXSERVER,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	if(serverpool == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}

	for(i = 0 ; i < MAXSERVER; i++)
		serverpool[i].pid = -1;

	for(i = 0 ; i < MINSPARESERVER; i++)
		add_1_server();


	while(1)
	{
		sigsuspend(&oset);		

		scan_serverpool();	

		if(count_idle > MAXSPARESERVER)
		{
			for(i = 0 ; i < (count_idle - MAXSPARESERVER);i++)
				del_1_server();
		}
		else if(count_idle < MINSPARESERVER)
			{
				for(i = 0 ; i < (MINSPARESERVER-count_idle); i++)
					add_1_server();
			}

		
		for(i = 0 ; i < MAXSERVER; i++)
		{
			if(serverpool[i].pid == -1) 	//未启用	
				putchar(' ');
			else if(serverpool[i].state == STATE_IDLE)
					putchar('.');
				 else	// busy
					putchar('x');
		}

		putchar('\n');

	}

	sigprocmask(SIG_SETMASK,&oset,NULL);

	exit(0);

}



