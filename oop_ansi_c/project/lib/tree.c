/*************************************************************************
	> File Name: tree.c
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月21日 星期四 11时00分27秒
 ************************************************************************/
#include<tree.h>
#include <oop.h>
# if 0
struct  TreeNode
{
    void * element;
    struct TreeNode * left;
    struct TreeNode * right;
};
#endif
//typedef struct TreeNode  Tree;
Tree * tree_create(void * data)
{
    Tree * tree_root;
    tree_root = malloc(sizeof(Tree));
    if(tree_root == NULL)
    {
        perror("malloc failed:");
        return NULL;
    }
    tree_root->element = data;
    tree_root->left = NULL;
    tree_root->right = NULL;
    return tree_root;
}
int tree_insert(Tree *tree_root,void * element)
{
    Tree * tree_node;

    Tree *tmp;
    Tree *cur;
    void * data;
    tmp = tree_root;
    data = tmp->element;
    cur = tmp;


    tree_node = malloc(sizeof(Tree));
    if(tree_node == NULL)
    {
        perror("malloc failed:");
        return 1;
    }

    tree_node->element = element;
    tree_node->left = NULL;
    tree_node->right = NULL;
    
    while(tmp != NULL)
    {
        if( *((int *)element) > *((int *)data) )
        {
          tmp =cur->right;
          if(tmp == NULL)
            {
                cur->right = tree_node;
                return 0;
                
            }
          cur = tmp;
          data = tmp->element;
        }
        else
        {
            tmp = cur->left;
            if(tmp == NULL)
            {
                cur->left = tree_node;
                return 0;
            }
            cur = tmp;
            data = tmp-> element;
        }
        
    }

    return 1;

}
int tree_find(Tree * tree_root,void * element)
{
    Tree *tmp;
    Tree *cur;
    void * data;
    tmp = tree_root;
    data = tmp->element;
    cur = tmp;
    while((*(int *)element) != (*(int *)data))
    {
        if(tmp == NULL)
        {
            printf("there is no: %d\n",*(int *)element);
            return 1;
        }
        if( *((int *)element) > *((int *)data) )
        {
          tmp =cur->right;
          cur = tmp;
          data = tmp->element;
        }
        else
        {
            tmp = cur->left;
            cur = tmp;
            data = tmp-> element;
        }
        
    }
    if(tmp->left != NULL)
    {
        printf("left:%d\n",*(int *)(tmp->left->element));
    }
    else if(tmp->right != NULL)
    {
        printf("right:%d\n",*(int *)(tmp->right->element));
    }
    else
        printf("Data: %d\nNo leaves\n",*(int *)(tmp->element));

    return 0;

}
