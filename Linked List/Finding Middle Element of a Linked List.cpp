#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;
void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }

}
void middle(struct node *p)
{
    struct node *q=p;
    while(q!=NULL && q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }
    printf("\nMiddle element is %d ",p->data);
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("Linked list is : ");
        struct node *p=first;
        middle(p);
    return 0;
}