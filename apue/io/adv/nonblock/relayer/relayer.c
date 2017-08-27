#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

#include "relayer.h"

#define BUFSIZE		1024

enum
{
	STATE_R=1,
	STATE_W,
	STATE_Ex,
	STATE_T
};

struct rel_fsm_st
{
	int state;
	int sfd,dfd;
	char buf[BUFSIZE];
	int len;
	int pos;
	int64_t count;
	char *errstr;
};

struct rel_job_st
{
	int fd1,fd2;
	int job_state;
	int fd1_save,fd2_save;
	struct rel_fsm_st fsm12,fsm21;
	pthread_mutex_t mut;
	pthread_cond_t cond;
//	struct timeval start,end;
};

static struct rel_job_st *rel_job[REL_JOBMAX];
static pthread_mutex_t mut_rel_job = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_once = PTHREAD_ONCE_INIT;


static void fsm_driver(struct rel_fsm_st *fsm)
{
	int ret;	
	switch(fsm->state)
	{
		case STATE_R:
			fsm->len = read(fsm->sfd,fsm->buf,BUFSIZE);
			if(fsm->len == 0)
				fsm->state = STATE_T;
			else if(fsm->len < 0)
				{
					if(errno == EAGAIN)
						fsm->state = STATE_R;
					else
					{
						fsm->errstr = "read()";
						fsm->state = STATE_Ex;
					}
				}
				else 
				{
					fsm->pos = 0;
					fsm->state = STATE_W;
				}
			break;
		
		case STATE_W:
			ret = write(fsm->dfd,fsm->buf+fsm->pos,fsm->len);
			if(ret < 0)
			{
				if(errno == EAGAIN)
					fsm->state = STATE_W;
				else
				{
					fsm->errstr = "write()";
					fsm->state = STATE_Ex;
				}
			}
			else   // ret >= 0
			{
				fsm->len -= ret;				
				fsm->pos += ret;
				fsm->count += ret;
				if(fsm->len == 0)
					fsm->state = STATE_R;
				else
					fsm->state = STATE_W;
			}

			break;
		
		case STATE_Ex:
			perror(fsm->errstr);
			fsm->state = STATE_T;
			break;
		
		case STATE_T:
			/* do sth */
			break;
		
		default:
			abort();
			break;
	}
}

static void *thr_relayer(void *p)
{
	int i;

	while(1)
	{
		pthread_mutex_lock(&mut_rel_job);	
		for(i = 0 ; i < REL_JOBMAX; i++)
		{
			if(rel_job[i] != NULL && rel_job[i]->job_state == STATE_RUNNING)
			{
				fsm_driver(&rel_job[i]->fsm12);
				fsm_driver(&rel_job[i]->fsm21);
				if(rel_job[i]->fsm12.state == STATE_T && \
					rel_job[i]->fsm21.state == STATE_T)
					rel_job[i]->job_state = STATE_OVER;
			}
		}
		pthread_mutex_unlock(&mut_rel_job);
	}

	pthread_exit(NULL);
}
/*
module_unload()
{


}
*/

static void module_load()
{
	pthread_t tid;
	int err;

	err = pthread_create(&tid,NULL,thr_relayer,NULL);
	if(err)
	{
		fprintf(stderr,"pthread_create():%s\n",strerror(err));
		exit(1);
	}
}

static int get_free_pos_unlocked()
{
	int i;
	for(i = 0 ; i < REL_JOBMAX; i++)
		if(rel_job[i] == NULL)
			return i;

	return -1;
}

int rel_addjob(int fd1,int fd2)
{
	struct rel_job_st *me; 
	int pos;
	
	pthread_once(&init_once,module_load);

	if(fd1 < 0 || fd2 < 0)
		return -EINVAL;

	me = malloc(sizeof(*me));
	if(me == NULL)
		return -ENOMEM;

	me->fd1 = fd1;
	me->fd2 = fd2;
	me->job_state = STATE_RUNNING;
	pthread_mutex_init(&me->mut,NULL);
	pthread_cond_init(&me->cond,NULL);

	me->fd1_save = fcntl(me->fd1,F_GETFL);
    fcntl(me->fd1,F_SETFL,me->fd1_save|O_NONBLOCK);
    me->fd2_save = fcntl(me->fd2,F_GETFL);
    fcntl(me->fd2,F_SETFL,me->fd2_save|O_NONBLOCK);

	me->fsm12.sfd = me->fd1;
	me->fsm12.dfd = me->fd2;
	me->fsm12.count = 0;
	me->fsm12.state = STATE_R;
	
	me->fsm21.sfd = me->fd2;
	me->fsm21.dfd = me->fd1;
	me->fsm21.count = 0;
	me->fsm21.state = STATE_R;

	pthread_mutex_lock(&mut_rel_job);
	pos = get_free_pos_unlocked();
	if(pos < 0)
	{
		pthread_mutex_unlock(&mut_rel_job);
		pthread_mutex_destroy(&me->mut);
		pthread_cond_destroy(&me->cond);
		free(me);
		return -ENOSPC;
	}
	rel_job[pos] = me;
	pthread_mutex_unlock(&mut_rel_job);	

	return pos;

}


static fetch_stat_unlocked(int id,struct rel_stat_st *statp)
{
	
	statp->fd1 = rel_job[id]->fd1;
	statp->fd2 = rel_job[id]->fd2;
	statp->state = rel_job[id]->job_state;
	statp->count12 = rel_job[id]->fsm12.count;
	statp->count21 = rel_job[id]->fsm21.count;

}

int rel_statjob(int id,struct rel_stat_st *statp)
{

	pthread_mutex_lock(&mut_rel_job);
	if(id < 0 || id >= REL_JOBMAX || rel_job[id] == NULL)
	{
		pthread_mutex_unlock(&mut_rel_job);
		return -EINVAL;
	}
	
	if(statp != NULL)
		fetch_stat_unlocked(id,statp);

	pthread_mutex_unlock(&mut_rel_job);

	return 0;
}


