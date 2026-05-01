#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
int length(struct Node *p);
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first;
    first->prev = first;
    last = first;
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = first;
        t->prev = last;
        last->next = t;
        first->prev = t;
        last = t;
    }
}
void display(struct Node *h)
{
    struct Node *p = h;
    if(h == NULL)
        return;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }
    while(p != h);
    printf("\n");
}
int length(struct Node *p)
{
    int len = 0;
    if(p == NULL)
        return 0;
    do
    {
        len++;
        p = p->next;
    }
    while(p != first);
    return len;
}
void reverse()
{
    struct Node *p = first;
    struct Node *temp;
    do
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
    }
    while(p != first);
    first = first->next;
}
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > length(first))
        return;
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(first == NULL)
        {
            first = t;
            first->next = first;
            first->prev = first;
        }
        else
        {
            t->next = first;
            t->prev = first->prev;
            first->prev->next = t;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}
int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 5);
    printf("Original List:\n");
    display(first);
    insert(first, 0, 5);
    printf("After Insertion:\n");
    display(first);
    reverse();
    printf("After Reverse:\n");
    display(first);
    return 0;
}