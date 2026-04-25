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
void Rdisplay(struct node *p)
{
    if(p!=NULL)
    {
    Rdisplay(p->next);// print values in reverse order
        printf("%d ",p->data);
        // Rdisplay(p->next);// print values in normal order
    }
}
int count(struct node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int Rcount(struct node *p)
{    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}
int sum(struct node *p)
{    int s=0;
    while(p)    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int main()
{
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("Count is %d\n",count(first));
    printf("Count is %d\n",Rcount(first));
    printf("Sum is %d\n",sum(first));
    return 0;
}