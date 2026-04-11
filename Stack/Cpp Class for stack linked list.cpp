#include <iostream>
struct Node {
    int data;
    Node* next;
};
class Stack {
    Node* top = nullptr;
public:
    ~Stack() {
        while (top) pop();
    }
    bool empty() {
        return top == nullptr;
    }    void push(int val) {
        top = new Node{val, top};
    }
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    int peek() {
        return top ? top->data : -1;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    
    std::cout << s.peek() << '\n';
    s.pop();
    std::cout << s.peek() << '\n';
    
    return 0;
}