#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFS_NUM 2

int main(int argc,char * argv[])
{
	struct iovec bufs[BUFS_NUM];
	const char *buf1 ="a";
	const char *buf2 ="b";

	bufs[0].iov_base = (void *)buf1;
	bufs[0].iov_len = strlen(buf1);
	bufs[1].iov_base = (void *)buf2;
	bufs[1].iov_len = strlen(buf2);

	if( writev(STDOUT_FILENO, bufs, BUFS_NUM) < 0){
		perror("writev()");
		exit(EXIT_FAILURE);
	}
	exit(0);

}
