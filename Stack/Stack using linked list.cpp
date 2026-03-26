#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = NULL;
void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    cout << val << " pushed\n";
}
void pop() {
    if (top == NULL) {
        cout << "Stack empty!\n";
        return;
    }
    cout << top->data << " popped\n";
    top = top->next;
}
void peek() {
    if (top == NULL)
        cout << "Stack empty!\n";
    else
        cout << "Top: " << top->data << "\n";
}
int main()
{
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    peek();
return 0;
}