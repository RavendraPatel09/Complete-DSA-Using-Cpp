#include <iostream>
using namespace std;
int stack[5], n = 5, top = -1;
void push(int val) {
if(top >= n-1)
    cout<<"Stack Overflow"<<endl;
else {
    top++;
    stack[top] = val;
}
}
void pop() {
if(top <= -1)
    cout<<"Stack Underflow"<<endl;
else {
    cout<<"Popped: "<< stack[top] <<endl;
    top--;
}
}
void display() {
if(top >= 0) {
    cout<<"Stack elements: ";
    for(int i = top; i >= 0; i--)
        cout<< stack[i] <<" ";
    cout<<endl;
} else
    cout<<"Stack is empty";
}
int main() {
push(10);
push(20);
push(30);
display();
pop();
display();
return 0;
getchar();
}