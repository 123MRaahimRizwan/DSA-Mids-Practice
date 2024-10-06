#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue()
    {
        size = 5;
        front = 0;
        rear = -1;
        arr = new int[size];
    }

    ~Queue()
    {
        delete[] arr;
    }
};

bool isFull(Queue *queue)
{
    if (queue->rear == queue->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(Queue *queue)
{
    if (queue->front > queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        cout << "Queue is full" << endl;
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
    cout << "Enqueued: " << value << endl;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        int dequeuedValue = queue->arr[queue->front];
        queue->front++;
        return dequeuedValue;
    }
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue->arr[queue->front];
}

int main()
{
    Queue *queue = new Queue;

    cout << "========= Enqueuing the Queue =========" << endl;
    enqueue(queue, 12);
    enqueue(queue, 34);

    cout << "========= Dequeuing the Queue =========" << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;

    delete queue;
    return 0;
}