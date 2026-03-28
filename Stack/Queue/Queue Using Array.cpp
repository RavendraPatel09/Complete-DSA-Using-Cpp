#include<iostream>
#include<stdio.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int)) ;
}
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is Full\n");
    else
    {
    q->rear++;
    q->Q[q->rear]=x;
    }
}
int queue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}