#include <leetcode.h>
#include <stdio.h>
#define MAX_NUM 1024
int lengthLongestPath(char* input) {
    char * cur,*next,*tab_p;
    int i = 1;
    int length = 0;
    int tab_num = 0;
    int tab_num_tmp = 0;
    int record_num[1024 * 1024];
    int longest = 0;
    int root_length = 0;
    int file_flag = 0;

    cur = input;
    for(;(*cur) != 0;cur++ ){
        while(*cur != 0)
        {
            if(*cur == '.')
            {
                printf("cur:%s",cur);
                break;
            }
                
            cur = cur + 1;
            
            
        }
        if(*cur == 0)
            return 0;
        
        cur = input;
        while(*cur != '\n' )
        {
            root_length = root_length + 1;
            cur = cur + 1;
            if(*cur == 0 )
                return root_length;
            

        }
        record_num[0] = root_length ;
        printf("root_length = %d\n",root_length);
        
        while(*cur == '\n'){
            /*find the number of "\r"*/
            tab_p = cur + 1;
            tab_num_tmp = 0;
            file_flag = 0;
            i = 1;
            while(*tab_p == '\t'){
                tab_num_tmp = tab_num_tmp + 1 ;
                tab_p = tab_p + 1;
            }
            printf("tab_num_tmp = %d\n",tab_num_tmp);
            if(tab_num_tmp > tab_num)
                tab_num = tab_num_tmp;

            next = tab_p + 1;
            

            /*find the length of file*/
            while((*next != '\n') && (*next != 0)){
                if(*next == '.')
                    file_flag = 1;
                i = i + 1;
                next = next + 1;
                

            }
            printf("i = %d\n",i);
            
            
            
            

                /*\r\r ----> length*/
                record_num[tab_num_tmp] =  i + record_num[tab_num_tmp -1];

                printf("record_num[%d] is %d\n",tab_num_tmp,record_num[tab_num_tmp]);

                length =   record_num[tab_num_tmp ] + tab_num_tmp;
                printf("length is %d\n",length);
                printf("file_flag = %d\n",file_flag);

                if(length > longest  && file_flag == 1)
                    longest = length;
                printf("longest is %d\n",longest);
            
            if(*next != 0)
                cur = next;
            else
                goto finish;
               // return  longest;




        }
    }
finish:
    return longest;

    
}
