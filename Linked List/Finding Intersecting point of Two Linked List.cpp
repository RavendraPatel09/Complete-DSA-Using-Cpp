#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* createNode(int data)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void intersection(struct Node *first, struct Node *second)
{
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    while(first != NULL)
    {
        stack1[++top1] = first;
        first = first->next;
    }
    while(second != NULL)
    {
        stack2[++top2] = second;
        second = second->next;
    }
    struct Node *temp = NULL;
    while(top1 >= 0 && top2 >= 0)
    {
        if(stack1[top1] == stack2[top2])
        {
            temp = stack1[top1];
            top1--;
            top2--;
        }
        else
        {
            break;
        }
    }
    if(temp != NULL)
        printf("Intersection Point = %d\n", temp->data);
    else
        printf("No Intersection\n");
}
int main()
{
    struct Node *first = createNode(10);
    first->next = createNode(20);
    first->next->next = createNode(30);
    first->next->next->next = createNode(40);
    struct Node *second = createNode(15);
    second->next = first->next->next;
    intersection(first, second);
    return 0;
}