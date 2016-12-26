#include <stdio.h>
#include <stdlib.h>
int main()
{
    int * buf[100000];
    size_t  mem = 100 * 1024 * 1024;
    int i = 0;
    int j = 0;
    while(1){
        buf[i] = malloc(mem);
        printf("after malloc:i = %d\n",i);
        if(buf[i] == NULL){
            printf("i = %d\n",i);
            break;
        }
        *(buf[i]) = 1;
        i++;
    }
    printf("malloc succeed\n");
    for(j = 0; j < i; j++ ){
        free(buf[j]);
    }

    return 0;
}
