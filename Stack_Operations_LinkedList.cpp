#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(NULL) {};
};

void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

bool isEmpty(Node *ptr)
{
    if (ptr == NULL)
    {
        return true;
    }
    return false;
}

Node *push(Node *top, int value)
{
    Node *ptr = new Node(value);
    ptr->next = top;
    return ptr;
}

int pop(Node *&top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    Node *ptr = top;
    int x = top->data;
    top = top->next;
    delete ptr;
    return x;
}

int peek(Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}

int stackBottom(Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    Node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

void clearStack(Node *&top)
{
    while (!isEmpty(top))
    {
        pop(top);
    }
}

int main()
{
    Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);

    cout << "============== Stack before popping ==============" << endl;
    LinkedListTraversal(top);

    cout << "============== Popped element ==============" << endl;
    cout << pop(top) << endl;

    cout << "============== Stack after popping ==============" << endl;
    LinkedListTraversal(top);

    cout << "============== Peek Method ==============" << endl;
    cout << peek(top) << endl;

    cout << "============== Stack Bottom Method ==============" << endl;
    cout << stackBottom(top) << endl;

    clearStack(top);
    return 0;
}
