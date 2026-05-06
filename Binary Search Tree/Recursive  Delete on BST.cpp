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
struct node * search(int key)
{
struct node *t=root;
while(t!=NULL){
    if(key==t->data)
        return t;
    else if(key<t->data)
        t=t->lchild;
    else
        t=t->rchild;

}
return NULL;
}
int Height(struct Node*p)
{
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
struct Node *InPre(struct node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
struct node *InSucc(struct node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}
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
   if(key < p->data)
        p->lchild=Rinsert(p->lchild, key);
    else if(key > p->data)
        p->rchild=Rinsert(p->rchild, key);
    return p;
}
struct node *Delete(struct node *t, int key)
{
    struct node *q;
    if(t==NULL)
        return NULL;
    if(t->lchild==NULL && t->rchild==NULL)
    {
        if(t==root)
            root=NULL;
        free(t);
        return NULL;
    }
    {
        if(t==root)
            root=NULL;
        free(t);
        return NULL;
    }
    if(key<t->data)
        t->lchild=Delete(t->lchild, key);
    else if(key>t->data)
        t->rchild=Delete(t->rchild, key);
    else
    {
        if(Height(t->lchild)>Height(t->rchild))
        {
            q=InPre(t->lchild);
            t->data=q->data;
            t->lchild=Delete(t->lchild,q->data);
        }
        else
        {
            q=InSucc(t->rchild);
            t->data=q->data;
            t->rchild=Delete(t->rchild,q->data);
        }
    }
    return t;
}   
int main()
{
    struct node *temp;
    root = Rinsert(root, 10);
 Rinsert(root, 5);
   Rinsert(root, 20);
 Rinsert(root, 8);
    Rinsert(root, 30);
    Delete(root, 20);
    
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\n");
    temp=search(8); 
    if(temp!=NULL)
        printf("Element %d found in the binary search tree.\n",temp->data);
    else
        printf("Element not found in the binary search tree.\n");    
    return 0;
}