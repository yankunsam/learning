/*************************************************************************
	> File Name: stack.h
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月14日 星期四 16时40分50秒
 ************************************************************************/
#include <stack.h>
#include <stdlib.h>
static stack_len * start ;
stack_len *stack_create(stack_len num)
{
    stack_len *p =(stack_len *) malloc(sizeof(stack_len) * num);
    if(p == NULL)
    {
        perror("malloc:");
        return NULL;
    }
    start = p;
    return p;
}
int stack_push(stack_len ** stack,stack_len * data)
{
   if(**stack != 0)
    {
        perror("you have no memory\n");
        return -1;
    }
    stack_len * tem;
    tem = * stack;
    *tem = *data;
    *stack = *stack + 1;
    return 0;
}
int stack_pop(stack_len ** stack)
{
    if(*stack == start)
    {
        perror("empty,no data can pop\n");
        return -1;
    }
   *stack = *stack - 1;
    printf("%d \n",**stack);
    return 0;
}
