#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
struct Node *root = NULL;
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void enqueue(struct Queue *q, struct Node *x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    printf("\nLevel Order Traversal: ");
    enqueue(&q, root);
    while (!isEmpty(q))
    {
        root = dequeue(&q);
        printf("%d ", root->data);
        if (root->lchild)
            enqueue(&q, root->lchild);
        if (root->rchild)
            enqueue(&q, root->rchild);
    }
}
int main()
{
    Treecreate();
    LevelOrder(root);
    return 0;
}