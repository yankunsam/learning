/*************************************************************************
	> File Name: llist.c
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月06日 星期三 16时36分40秒
 ************************************************************************/
#include <llist.h>

#if 0
struct node_st
{
    void *data;
    struct node_st *next;
};

typedef struct
{
    struct node_st *head;
    int size;
}LLIST;

#endif
LLIST * llist_create(size_t len)
{
    LLIST * llist;
    llist = malloc(sizeof(LLIST));
    if(llist == NULL)
    {
        perror("llist malloc:");
        return NULL;
    }

    llist->head.next = NULL;
    llist->size = len;
    return llist;



}
int llist_insert(LLIST * llist_head,struct node_st * node)
{
    if(llist_head == NULL)
    {
        perror("the llist_head is NULL\n");
        return -1;
    }
    node->next = llist_head->head.next;
    llist_head->head.next = node;
    return 0;



}
void llist_destroy(LLIST * list_head)
{

    struct node_st *next;
    struct node_st *prev;
    prev = list_head->head.next;
    while(prev != &(list_head->head))
    {

        next = prev->next;

        memset(prev->data,0,list_head->size);
        memset(prev,0,sizeof(struct node_st));

        prev = next;

    }
    free(list_head);

}
LLIST *llist_swap_two(LLIST *list_head)
{
	struct node_st *cur,*next;
	static LLIST head_new;
        if(list_head->head.next == NULL || list_head->head.next->next == NULL)
		return NULL;
	cur = (list_head -> head.next);
	next = cur -> next;
        list_head->head.next = next;
	while(cur != NULL && next != NULL)
	{
		cur -> next = next -> next;
		next ->next = cur;
		if(cur -> next != NULL)
			cur = cur -> next;
		else
			return cur;
		if(cur -> next != NULL)
			next = cur -> next;
		else
			return cur ;
	}
#if 1
	head_new.size = list_head -> size;
	if(cur == NULL)

		head_new.head = *next;
	if(next == NULL)
		head_new.head = *cur;
	return &head_new;
#endif

}
