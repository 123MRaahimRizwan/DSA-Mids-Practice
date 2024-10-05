#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {};
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
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    p->next = newNode;
    newNode->next = p->next;
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
    prevNode->next = newNode;
    newNode->next = prevNode->next;
    return head;
}

Node *DeletionAtBeginning(Node *head)
{
    if (isEmpty(head))
    {
        cout << "Linked List is empty" << endl;
        exit(1);
    }
    Node *p = head;
    head = head->next;
    delete p;
    return head;
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
    delete q;
    return head;
}

Node *DeletionOfNodeAtValue(Node *head, int value)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return head; // No need to exit; just return.
    }

    // Handle the case where the head needs to be deleted.
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *p = head;
    Node *q = head->next;

    while (q != NULL && q->data != value)
    {
        p = q;
        q = q->next;
    }

    // If the value was found
    if (q != NULL)
    {
        p->next = q->next; // Bypass the node to delete
        delete q;          // Free the memory
    }
    else
    {
        cout << "Could not find the given value in the linked list." << endl;
    }

    return head; // Return the potentially new head
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
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

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
    head = DeletionOfNodeAtValue(head, 30);
    LinkedListTraversal(head);
    return 0;
}