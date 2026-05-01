#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    return t;
}
int main()
{
    struct Node *root;
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    printf("Root Node: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);
    return 0;
}