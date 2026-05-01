#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int power;
    struct Node *next;
};
struct Node *createNode(int c, int p)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->coeff = c;
    t->power = p;
    t->next = NULL;
    return t;
}
void insert(struct Node **head, int c, int p)
{
    struct Node *t = createNode(c, p);
    if (*head == NULL)
    {
        *head = t;
    }
    else
    {
        struct Node *q = *head;
        while (q->next != NULL)
            q = q->next;
        q->next = t;
    }
}
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->power);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
}
int main()
{
    struct Node *poly = NULL;
    insert(&poly, 5, 3);
    insert(&poly, 4, 2);
    insert(&poly, 2, 0);
    printf("Polynomial: ");
    display(poly);
    return 0;
}