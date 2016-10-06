/*************************************************************************
	> File Name: dog.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月05日 星期二 16时52分04秒
 ************************************************************************/

#include<animal.h>

static const char * sound(void)
{
    return "arf!";

}
const struct animal_vtable_ DOG[] = { {sound} };

