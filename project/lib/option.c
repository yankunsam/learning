/*************************************************************************
	> File Name: option.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月04日 星期一 13时21分20秒
 ************************************************************************/

#include<option.h>
int fun_va(int num,...)
{
    va_list valist;
    int i;

    va_start(valist,num);

    for(i = 0;i < num;i++)
    {

        printf("%d\n",va_arg(valist,int));
    }
        va_end(valist);
    return num;
    

}

