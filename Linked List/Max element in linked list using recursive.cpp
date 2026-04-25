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
int max(struct node *p)
{
    int max=INT32_MIN;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int Rmax(struct node *p)
{
    int x=0;

    if(p==NULL)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}
int main()
{
    int A[]={3,5,7,10,32,55,100};
    create(A,7);
    printf("Maximum element  %d\n",Rmax(first));
    return 0;
}