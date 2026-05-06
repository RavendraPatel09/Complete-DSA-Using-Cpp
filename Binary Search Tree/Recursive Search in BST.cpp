#include<stdio.h>
#include<stdlib.h>  
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;  
void insert(int key)
{
    struct node *t=root;
    struct node *r=NULL,*p;
    if(root==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;    
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
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
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
