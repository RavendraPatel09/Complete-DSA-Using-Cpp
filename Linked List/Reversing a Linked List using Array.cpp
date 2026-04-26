#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void Rdisplay(struct node *p)
{
    if(p != NULL)
    {
        Rdisplay(p->next);
        printf("%d ", p->data);
    }
}
int count(struct node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int Rcount(struct node *p)
{
    if(p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}
int sum(struct node *p)
{
    int s = 0;
    while(p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}
int max(struct node *p)
{
    int max = INT32_MIN;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int Rmax(struct node *p)
{
    int x;
    if(p == NULL)
        return INT32_MIN;
    x = Rmax(p->next);
    return (x > p->data) ? x : p->data;
}
struct node *Lsearch(struct node *p, int key)
{
    while(p)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}
struct node *Rsearch(struct node *p, int key)
{
    if(p == NULL)    
        return NULL;
    if(key == p->data)
        return p;
    return Rsearch(p->next, key);
}
struct node * Rsearch2(struct node *p, int key)
{
    struct node *t;
    if(p == NULL)    
        return NULL;
    if(key == p->data)
        return p;
    t = Rsearch2(p->next, key);
    return t;
}
void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void sortedInsert(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int Delete(struct node *p, int index)
{
    struct node *q = NULL;
    int x = -1, i;
    if(index < 1 || index > count(p))
        return x;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int isSorted(struct node *p)
{
    int x = INT32_MIN;
    while(p != NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void reverse1(struct node *p)
{
    int *A, i = 0;
    struct node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));
    while(q != NULL)
    {
        A[i++] = q->data;
        q = q->next;
    }
    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i--];
        q = q->next;
    }
} 
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    reverse1(first);
    display(first);
    return 0;
}