#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) ||
               (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Full\n";
            return;
        }

        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = SIZE - 1;
        else
            front--;

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Full\n";
            return;
        }

        if (rear == -1)
            front = rear = 0;
        else if (rear == SIZE - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque Empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque d;

    d.insertRear(10);
    d.insertRear(20);
    d.insertFront(5);

    d.display();

    return 0;
}