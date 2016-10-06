/*************************************************************************
	> File Name: cat.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月05日 星期二 16时50分09秒
 ************************************************************************/

#include<animal.h>
static const char *sound(void)
{
    return "meow!\n";
}

const struct animal_vtable_ CAT[] ={ {sound} };
