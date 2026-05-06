#include<stdio.h>
#include<stdlib.h>  
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;  
struct node *Rinsert(struct node *t, int key)
{
    struct node *p;
    if(t==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        return p;
    }
    if(key<t->data)
        t->lchild=Rinsert(t->lchild, key);
    else if(key>t->data)
        t->rchild=Rinsert(t->rchild, key);
    return t;
}
void inorder(struct node *p)
{    if(p)
    {
        inorder(p->lchild);     
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
struct node * Rsearch(struct node *t, int key)
{
if(t==NULL)
    return NULL;
if(key==t->data)
    return t;
if(key<t->data)
    return Rsearch(t->lchild, key);
else
    return Rsearch(t->rchild, key);
}
int main()
{
    struct node *temp;
    root=Rinsert(root, 10);
    root=Rinsert(root, 5);
    root=Rinsert(root, 20);
    root=Rinsert(root, 8);
    root=Rinsert(root, 30);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\n");
    temp=Rsearch(root, 8);
    if(temp!=NULL)
        printf("Element %d found in the binary search tree.\n",temp->data);
    else
        printf("Element not found in the binary search tree.\n");
    return 0;
}
