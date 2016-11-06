#include <stdio.h>
int main(void){
    char a[20] = "hello\r\n";
    char *b;
    b = a;
    while(1)
    {
        if(*b == '\r')
            printf("hello world\n");
        printf("%d\n",*b);
        printf("%s\n",b);
        b++;
    }
    return 0;
}
