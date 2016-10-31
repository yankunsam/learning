/*************************************************************************
> File Name: main.c
> Author: 
> Mail: 
> Created Time: 2016年07月03日 星期日 15时54分48秒
************************************************************************/

#include <oop.h>

#if 0
const void * set;
const void * object;
#endif

struct set {
    unsigned int count;
};
struct object {
    unsigned int count;
    struct set * in;
};


static const size_t _Set = sizeof(struct set);
static const size_t _Object = sizeof(struct object);

const void *Set = & _Set;
const void *Object = & _Object;

#define st_num 10
int main(int argc,char * argv[])
{
    #if 0
    void * s = new(Set);
    printf("*s = %d\n",*(int *)s);
    #endif

    #if 0
    void * a = add(s,new(Object));
    printf("*a = %d\n",*(int *)a);
    #endif 

    #if 0
    if(contains(s,a))
    puts("ok\n");


    else
    puts("no\n");
    #endif


    #if 0
    struct animal kitty = {CAT,"Kitty"};
    struct animal lassie = {DOG,"Lassie"};

    printf("%s says %s\n",kitty.name,animal_sound(&kitty));
    printf("%s says %s\n",lassie.name,animal_sound(&lassie));

    #endif
    #if 0
    int fd;
    fd = open("/home/sam/examples.desktop",O_RDONLY);
    printf("fd = %d\n",fd);
    fd = open("/home/sam/examples.desktop",O_RDONLY);
    printf("fd = %d\n",fd);
    while(1);
    #endif

    #if 0
    fun_inline();
    #endif
    #if 0
    int a = 10;
    return a < 0 ?:
    printf("a = %d\n",a);
    #endif 

    #if 0
    stack_len  *st;
    stack_len i = 6;

    st = stack_create((stack_len)st_num);
    stack_push(&st,&i);

    i = 10;

    stack_push(&st,&i);

    stack_pop(&st);
    stack_pop(&st);
    stack_pop(&st);
    #endif
    
    #if 1
    struct node_st node_1,node_2,node_3;
    int i,j,k;
    i = 10;
    node_1.data = (void *)&i;
    j = 20;
    node_2.data = (void *)&j;

    k = 30;
    node_3.data = (void *)&k;

    LLIST *list_head;
    list_head = llist_create((sizeof(int)));


    if( llist_insert(list_head,&node_1) < 0)
    {
        perror("llist_insert:");
        llist_destroy(list_head);
        return -1;
    }
    if( llist_insert(list_head,&node_2) < 0)
    {
        perror("llist_insert:");
        llist_destroy(list_head);
        return -1;
    }
    if( llist_insert(list_head,&node_3) < 0)
    {
        perror("llist_insert:");
        llist_destroy(list_head);
        return -1;
    }

   //printf("%d\n", *((int*)((list_head->head.next->next->next)->data)));

   // llist_destroy(list_head);

   #endif
    #if 0
    Tree * tree_root;
    int i = 10;
    int j = 100;
    int a = 20;
    int b = 30;
    tree_root = tree_create((void *)&i);
    tree_insert(tree_root,(void *)&j);
    tree_insert(tree_root,(void *)&a);
    tree_insert(tree_root,(void *)&b);
    
    tree_find(tree_root,(void *)&a);
    #endif
#if 0    
    #define likely(x) __builtin_expect(!!(x),1)
    #define unlikely(x) __builtin_expect(!!(x),0)

    if(likely(1))
        printf("  likey(1)\n");
    if(!unlikely(0))
        printf("unlikely(0)\n");
#endif
    llist_swap_two(list_head);
    printf("%d\n", *((int*)((list_head->head.next)->data)));
    return 0;
}

