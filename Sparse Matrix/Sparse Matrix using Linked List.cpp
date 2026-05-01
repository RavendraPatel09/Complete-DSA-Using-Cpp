#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int row, col, value;
    struct Node *next;
};
struct Node *createNode(int r, int c, int v)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->row = r;
    t->col = c;
    t->value = v;
    t->next = NULL;
    return t;
}
void insert(struct Node **head, int r, int c, int v)
{
    struct Node *t = createNode(r, c, v);
    if (*head == NULL)
    {
        *head = t;
    }
    else
    {
        struct Node *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = t;
    }
}
void display(struct Node *head)
{
    printf("Row Col Value\n");
    while (head != NULL)
    {
        printf("%d   %d    %d\n",
               head->row,
               head->col,
               head->value);
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    insert(&head, 0, 1, 5);
    insert(&head, 1, 2, 8);
    insert(&head, 2, 0, 3);
    display(head);
    return 0;
}