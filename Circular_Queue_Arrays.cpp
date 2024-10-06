#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    CircularQueue(int k)
    {
        size = k;
        front = 0;
        rear = 0;
        arr = new int[size];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

bool isEmpty(CircularQueue *circular_queue)
{
    if (circular_queue->front == circular_queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(CircularQueue *circular_queue)
{
    if ((circular_queue->rear + 1) % circular_queue->size == circular_queue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(CircularQueue *circular_queue, int value)
{
    if (isFull(circular_queue))
    {
        cout << "Circular queue is full!" << endl;
        return;
    }
    else
    {
        circular_queue->arr[circular_queue->rear] = value;
        circular_queue->rear = (circular_queue->rear + 1) % circular_queue->size;
    }
    cout << "Enqueued: " << value << endl;
}

int dequeue(CircularQueue *circular_queue)
{
    if (isEmpty(circular_queue))
    {
        cout << "Circular queue is empty!" << endl;
        return -1;
    }
    int dequeuedValue = circular_queue->arr[circular_queue->front];
    circular_queue->front = (circular_queue->front + 1) % circular_queue->size;
    return dequeuedValue;
}

int peek(CircularQueue *circular_queue)
{
    if (isEmpty(circular_queue))
    {
        cout << "Circular Queue is empty!" << endl;
        return -1;
    }
    else
    {
        return circular_queue->front;
    }
}

int main()
{
    CircularQueue *queue = new CircularQueue(5);

    cout << "========= Enqueuing the Queue =========" << endl;
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    cout << "========= Dequeuing the Queue =========" << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;
    cout << "Dequeued: " << dequeue(queue) << endl;

    cout << "========= Peeking the Queue =========" << endl;
    cout << "Peeked: " << peek(queue) << endl;

    delete queue;
    return 0;
}