#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
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
    do
    {
        printf("%d ", p->data);
        p = p->next;
    }
    while(p != h);
    printf("\n");
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
int main()
{
    int A[] = {10,20,30,40,50};
    create(A, 5);
    printf("Original List:\n");
    display(first);
    reverse();
    printf("Reversed List:\n");
    display(first);
    return 0;
}