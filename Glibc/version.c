/*************************************************************************
	> File Name: version.c
	> Author: sam
	> Mail:samyankun@gmail.com 
	> Created Time: 2016年10月13日 星期四 11时47分25秒
 ************************************************************************/

#include<stdio.h>
int main(){
    if(__GLIBC_PREREQ(2,10))
        printf("ok\n");
    return 0;
}
