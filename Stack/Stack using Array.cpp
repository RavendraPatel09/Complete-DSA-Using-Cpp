#include <iostream>
using namespace std;

// Changed name from 'stack' to 'stk' to avoid the error
int stk[5], n = 5, top = -1;

void push(int val) {
if(top >=n-1)
cout << "Stack Overflow" << endl;
else {
    top++;
    stk[top] = val;
}
}

void pop() {if(top <= -1)
    cout << "Stack Underflow" << endl;
else {
    cout << "Popped: " << stk[top] << endl;
top--;
}
}

void display()
{
if(top >= 0) {
    cout << "Stack elements: ";
    for(int i = top; i >= 0; i--)
cout << stk[i] << " ";
    cout << endl;
} else {
    cout << "Stack is empty" << endl;}
}

int main() {
push(10);
push(20);
push(30);
display();
pop();
display();
return 0;
}