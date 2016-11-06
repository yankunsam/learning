#include <stdio.h>
#include <oop.h>
int main(){
    int result = 0;
    char a[50]= "123\n\t1\n\t\t4\n\t\t\t5\n\t\t\t\t6\n\t7000000000000000000000000000\n\t9";

    result = lengthLongestPath(a);
    printf("result = %d\n",result);
    return 0;
}
