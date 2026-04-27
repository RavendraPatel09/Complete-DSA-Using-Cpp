#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
class LinkedList
{
private:
    Node* first;
public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();
    void display();
    void insert(int index, int x);
    int remove(int index);   // renamed
    int length();
};
LinkedList::LinkedList(int A[], int n)
{
    Node* t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList()
{
    Node* p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::display()
{
    Node* p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void LinkedList::insert(int index, int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        Node* p = first;
        for (int i = 0; i < index - 1 && p; i++)
            p = p->next;
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}
int LinkedList::remove(int index)
{
    Node* p = first;
    int x = -1;
    if (index == 0)
    {
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        Node* q = NULL;
        for (int i = 0; i < index && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}
int LinkedList::length()
{
    Node* p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
int main()
{
    int A[] = {3, 5, 7, 10, 15};
    LinkedList l(A, 5);
    cout << l.remove(2) << endl;
    cout << "Length is " << l.length() << endl;
    l.insert(2, 12);
    l.display();
    return 0;
}