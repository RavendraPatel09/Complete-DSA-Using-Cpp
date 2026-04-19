#include<stdio.h>
#include<stdlib.h>
struct Element 
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct Element *ele; 
};
void create(struct sparse *s)
{
    int i;
    printf("enter dimension: ");
    scanf("%d%d",&s->m,&s->n);
    printf("enter number of non-zero elements: ");
    scanf("%d",&s->num);
    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("enter non-zero elements (i j x):\n");
    for(i=0;i<s->num;i++)
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
}
void display(struct sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(k < s.num && i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ",s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct sparse s;
    create(&s);
    display(s);
    return 0;
}