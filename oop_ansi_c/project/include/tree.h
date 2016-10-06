/*************************************************************************
	> File Name: tree.h
	> Author: sam
	> Mail: samyankun@gmail.com
	> Created Time: 2016年07月21日 星期四 11时00分27秒
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H

struct  TreeNode
{
    void * element;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode  Tree;

Tree * tree_create(void * data);

int tree_insert(Tree *,void * element);//error == 1

int tree_find(Tree *,void * element);
void tree_free(Tree *);
#endif

