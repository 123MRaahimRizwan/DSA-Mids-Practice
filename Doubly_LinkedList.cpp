#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node() {};
    Node(int data) : data(data), next(NULL), prev(NULL) {};
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
        cout << "Linked List is empty" << endl;
        return true;
    }
    return false;
}

Node *InsertionAtBeginning(Node *head, int value)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *newNode = new Node(value);
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    return newNode;
}

Node *InsertionAtEnd(Node *head, int value)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *newNode = new Node(value);
    Node *p = head;
    while (p != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;
    newNode->prev = p;
    delete p;
    return head;
}

Node *InsertionAtIndex(Node *head, int value, int index)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *newNode = new Node(value);
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = newNode;
    q->prev = newNode;
    newNode->prev = p;
    newNode->next = q;
    return head;
}

Node *InsertionAfterANode(Node *head, Node *prevNode, int value)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *newNode = new Node(value);

    Node *nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    return head;
}

Node *DeletionAtBeginning(Node *head)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *nodeToDelete = head;
    Node *newHead = head->next;
    if (newHead != NULL)
    {
        newHead->prev = NULL;
    }
    delete nodeToDelete;
    return newHead;
}

Node *DeletionAtEnd(Node *head)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    delete q;
    p->next = NULL;
    return head;
}

Node *DeletionAtIndex(Node *head, int index)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    delete q;
    return head;
}

Node *DeletionOfNodeAtAGivenValue(Node *head, int value)
{
    Node *p = head;
    Node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        q->next->prev = p;
        delete q;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->next = NULL;
    sixth->prev = fifth;

    cout << "=========== Linked List before insertion ===========" << endl;
    LinkedListTraversal(head);
    cout << endl;
    cout << "=========== Linked List after insertion ===========" << endl;
    head = InsertionAtBeginning(head, 50);
    head = InsertionAtIndex(head, 50, 2);
    head = InsertionAtEnd(head, 50);
    head = InsertionAfterANode(head, third, 50);

    cout << "=========== Linked List before Deletion ===========" << endl;
    LinkedListTraversal(head);
    cout << "=========== Linked List after Deletion ===========" << endl;
    head = DeletionAtBeginning(head);
    head = DeletionAtEnd(head);
    head = DeletionAtIndex(head, 2);
    head = DeletionOfNodeAtAGivenValue(head, 30);
    LinkedListTraversal(head);
    return 0;
}