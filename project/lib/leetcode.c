#include <leetcode.h>
int lengthLongestPath(char *input){
    char * cur,next,tab_p;
    cur = input;
    int i = 0;
    int lenth = 0;
    int tab_num;

    while(1){
        if(*cur == '\' && *(cur + 1) == 'n'' ){
            tab_p = cur + 2;
            while(tab_p == '\' && tab_p == 't'){
                tab_num = tab_num + 1;
                tab_p = tab_p + 1;
            }
            next = tab_p + 2;


            while(*next != '\' && *(next + 1) != 'n'){
                i = i + 1;
                next = next + 1;

            }
            lenth = i + length;
            cur = next;
        }

    }

}
