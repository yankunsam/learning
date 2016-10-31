/*************************************************************************
	> File Name: set.h
	> Author: 
	> Mail: 
	> Created Time: 2016年07月03日 星期日 16时04分18秒
 ************************************************************************/

#ifndef _SET_H
#define _SET_H
#include <oop.h>
//extern const void * Set;
void *new (const void *type,...);
void delete(void * _item);

void * add(void * set,const void * element);
void * find(const void * set,const void * element);
void * drop(void * set,const void *element);
int contains(const void * set,const void * element);

#endif
