/*************************************************************************
	> File Name: llist.h
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月06日 星期三 16时36分40秒
 ************************************************************************/

#ifndef _LLIST_H
#define _LLIST_H
#include <stdlib.h>

struct node_st
{
    void *data;
    struct node_st *next;
};

typedef struct
{
    struct node_st head;//remeber,head can not be a pointer.Unless,it will segfault
    size_t size;
}LLIST;

LLIST * llist_create(size_t);
int llist_insert(LLIST *,struct node_st * );
void llist_destroy(LLIST *);
#endif
