#include <iostream>
using namespace std;

class DEQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    DEQueue(int k)
    {
        size = k;
        front = 0;
        rear = -1;
        arr = new int[size];
    }

    ~DEQueue()
    {
        delete[] arr;
    }
};

bool isFull(DEQueue *dequeue)
{
    if (dequeue->rear == dequeue->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(DEQueue *dequeue)
{
    if (dequeue->front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool insertFront(DEQueue *dequeue, int value)
{
    if (dequeue->front == 0)
    {
        cout << "DEQueue is full at front!" << endl;
        return false;
    }
    if (isEmpty(dequeue))
    {
        cout << "DEQueue is empty!" << endl;
        return false;
    }
    else
    {
        dequeue->front--;
        dequeue->arr[dequeue->front] = value;
    }
    cout << "Enqueued from front: " << value << endl;
    return true;
}

bool insertLast(DEQueue *dequeue, int value)
{
    if (isFull(dequeue))
    {
        cout << "DEQueue is full!" << endl;
        return false;
    }
    if (isEmpty(dequeue))
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else
    {
        dequeue->rear++;
        dequeue->arr[dequeue->rear] = value;
    }
    cout << "Enqueued from last: " << value << endl;
    return true;
}

bool deleteFront(DEQueue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "DEQueue is empty" << endl;
        return false;
    }
    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else
    {
        dequeue->front++;
    }
    return true;
}

bool deleteLast(DEQueue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "DEQueue is empty" << endl;
        return false;
    }
    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else
    {
        dequeue->rear--;
    }
    return true;
}

int getFront(DEQueue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "DEQueue is empty" << endl;
        return -1;
    }
    return dequeue->front;
}

int getLast(DEQueue *dequeue)
{
    if (isEmpty(dequeue))
    {
        cout << "DEQueue is empty" << endl;
        return -1;
    }
    return dequeue->rear;
}

int main()
{
    DEQueue *dequeue = new DEQueue(10);
    insertLast(dequeue, 1);
    insertLast(dequeue, 2);
    insertFront(dequeue, 3);
    insertFront(dequeue, 4);

    deleteFront(dequeue);
    deleteLast(dequeue);
    return 0;
}