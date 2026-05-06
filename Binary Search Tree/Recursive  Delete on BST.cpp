#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;
void insert(int key)
{
    struct node *t = root;
    struct node *r = NULL, *p;
    if(root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL)
    {
        r = t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
struct node *Rinsert(struct node *t, int key)
{
    struct node *p;
    if(t == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if(key < t->data)
        t->lchild = Rinsert(t->lchild, key);
    else if(key > t->data)
        t->rchild = Rinsert(t->rchild, key);
    return t;
}