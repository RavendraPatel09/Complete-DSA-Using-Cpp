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
int count(struct Node *root)
{
    if (root == NULL)
        return 0;
    return count(root->lchild) + count(root->rchild) + 1;
}
int main()
{
    Treecreate();
    printf("\nNumber of nodes: %d", count(root));
    return 0;
}
//run this code and input the following values when prompted:
//Enter root value: 1
//Enter left child of 1 (-1 for no child): 2
//Enter right child of 1 (-1 for no child): 3
//Enter left child of 2 (-1 for no child): 4
//Enter right child of 2 (-1 for no child): 5
//Enter left child of 3 (-1 for no child): -1
//Enter right child of 3 (-1 for no child): -1
//Enter left child of 4 (-1 for no child): -1
//Enter right child of 4 (-1 for no child): -1
//Enter left child of 5 (-1 for no child): -1
//Enter right child of 5 (-1 for no child): -1  