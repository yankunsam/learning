#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;

};
struct node * newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void printInorder(struct node *node)
{
    if(node == NULL)
        return;
    printInorder(node->left);
    printf("%d \n",node->data);
    printInorder(node->right);

}
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void correctBSTUtil(struct node *root,struct node **first,struct node **middle,
        struct node **last,struct node **prev)
{
    if(root){
        correctBSTUtil(root->left,first,middle,last,prev);
        if(*prev && root->data < (*prev)->data){
            if( !*first ){
                *first = *prev;
                *middle = root;
            }
            else
                *last = root;

        }
        *prev = root;
        printf("***%d ",(*prev)->data);
        printf("\n");
        correctBSTUtil(root->right,first,middle,last,prev);



    }
}
void correctBST(struct node *root)
{
    struct node *first,*middle,*last,*prev;
    first = middle = last = prev = NULL;
    correctBSTUtil(root,&first,&middle,&last,&prev);

    if(first && last)
        swap(&(first->data),&(last->data));
    else if(first && middle)
        swap(&(first->data),&(middle->data));
}
int main(int argc,char *argv[])
{
    struct node *root = newNode(6);
    root->left = newNode(10);
    root->right = newNode(2);

    root->left->left = newNode(1);
    root->left->right = newNode(3);

    root->right->left = newNode(7);
    root->right->right = newNode(12);

    //printf("Inorder Traversal of the original tree \n");
    //printInorder(root);

    correctBST(root);
    //printf("Inorder Traversal of the fixed tree \n");
   // printInorder(root);



    return 0;
}
