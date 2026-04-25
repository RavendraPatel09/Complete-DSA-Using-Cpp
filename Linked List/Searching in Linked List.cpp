#include<stdio.h>
#include<stdlib.h>
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
int main()
{
    struct node *temp;
    int A[] = {3, 5, 7, 10, 32, 55, 100};
    create(A, 7);
    temp = Lsearch(first, 10);
    if(temp)
        printf("Key %d found in the linked list\n", temp->data);    
    else
        printf("Key not found in the linked list\n");
    return 0;
}