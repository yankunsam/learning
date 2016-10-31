/*************************************************************************
	> File Name: stack.h
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月14日 星期四 16时40分50秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
typedef int stack_len;

stack_len  *stack_create(stack_len num);

int stack_push(stack_len **,stack_len * );

int stack_pop(stack_len **);
#endif
