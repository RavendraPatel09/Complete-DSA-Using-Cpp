#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(int size)
    {
        this->size=size;
        front=rear=0;
        Q=new Node*[size];
    }
    void enqueue(Node *x)
    {
        if((rear+1)%size==front)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            rear=(rear+1)%size;
            Q[rear]=x;
        }
    }
    Node *dequeue()
    {
        Node *x=NULL;
        if(front==rear)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            front=(front+1)%size;
            x=Q[front];
        }
        return x;
    }
    int isEmpty()
    {
        return front==rear;
    }
};
class Tree
{
private:
    Node *root;
public:
    Tree()
    {
        root=NULL;
    }
    void createTree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    Node *getRoot()
    {
        return root;
    }
};
void Tree::createTree()
{
    Node *p,*t;
    int x;
    Queue q(100);
    cout<<"Enter root value: ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter left child of "<<p->data<<" (-1 for no child): ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<" (-1 for no child): ";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=NULL;
            t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::preOrder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void Tree::inOrder(Node *p)
{
    if(p)
    {
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}
void Tree::postOrder(Node *p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}
int main()
{
    Tree t;
    t.createTree();
    cout<<"\nPreorder Traversal: ";
    t.preOrder(t.getRoot());
    cout<<"\nInorder Traversal: ";
    t.inOrder(t.getRoot());
    cout<<"\nPostorder Traversal: ";
    t.postOrder(t.getRoot());
    return 0;
}