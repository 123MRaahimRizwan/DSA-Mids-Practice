#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() {};
    Node(int data) : data(data), next(NULL) {}
};

void Circular_Linked_List_Traversal(Node *head)
{
    Node *p = head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

Node *Insertion_At_Beginning(Node *head, int value)
{
    Node *newNode = new Node(value);
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = head;
    newNode = head;
    return head;
}
Node *Insertion_At_End(Node *head, int value)
{
    Node *newNode = new Node(value);
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = head;
    return head;
}
Node *Insertion_At_Index(Node *head, int value, int index)
{
    // In this logic you have to make a q pointer. Without this the code wouldn't work
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
    newNode->next = q;
    return head;
}
Node *Insertion_After_A_Node(Node *head, Node *prevNode, int value)
{
    Node *newNode = new Node(value);
    Node *p = prevNode->next;
    prevNode->next = newNode;
    newNode->next = p;
    return head;
}

Node *Deletion_Of_First_Node(Node *head)
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    Node *newHead = head->next;
    delete head;
    return newHead;
}
Node *Deletion_Of_Last_Node(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    delete q;
    return head;
}
Node *Deletion_Of_Node_At_A_Given_Value(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}
Node *Deletion_Of_Node_At_A_Given_Index(Node *head, int index)
{
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

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    // cout << "============== Insertion ==============" << endl;

    // cout << "Linked List before insertion" << endl;

    // Circular_Linked_List_Traversal(head);

    // cout << "Linked List after insertion" << endl;
    // head = Insertion_At_Beginning(head, 50);
    // head = Insertion_At_Index(head, 60, 2);
    // head = Insertion_At_End(head, 60);

    // head = Insertion_After_A_Node(head, third, 60);

    // Circular_Linked_List_Traversal(head);

    cout << "============== Deletion ==============" << endl;

    cout << "Linked List before deletion" << endl;

    Circular_Linked_List_Traversal(head);

    cout << "Linked List after deletion" << endl;
    // head = Deletion_Of_First_Node(head);
    // head = Deletion_Of_Node_At_A_Given_Index(head, 2);
    // head = Deletion_Of_Last_Node(head);
    head = Deletion_Of_Node_At_A_Given_Value(head, 20);

    Circular_Linked_List_Traversal(head);
    return 0;
}