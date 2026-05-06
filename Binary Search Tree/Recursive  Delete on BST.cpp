#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root = NULL;
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL;
    struct Node *p;
    if(root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
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
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
int Height(struct Node *p)
{
    int x, y;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return (x > y) ? x + 1 : y + 1;
}
struct Node *InPre(struct Node *p)
{
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}
struct Node *DeleteNode(struct Node *p, int key)
{
    struct Node *q;
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = DeleteNode(p->lchild, key);
    else if(key > p->data)
        p->rchild = DeleteNode(p->rchild, key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = DeleteNode(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = DeleteNode(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    printf("Inorder before deletion: ");
    Inorder(root);
    printf("\n");
    root = DeleteNode(root, 20);
    printf("Inorder after deletion: ");
    Inorder(root);
    printf("\n");
    return 0;
}