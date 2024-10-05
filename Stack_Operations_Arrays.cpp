#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *array;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        array = new int[size];
        cout << "Stack created successfully" << endl;
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(int value)
    {
        if (isFull())
        {
            return;
        }
        top++;
        array[top] = value;
        cout << value << " pushed." << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int value = array[top];
        top--;
        cout << value << " popped." << endl;
        return value;
    }

    int stackTop()
    {
        if (isEmpty())
        {
            return -1;
        }
        return array[top];
    }

    int stackBottom()
    {
        if (isEmpty())
        {
            return -1;
        }
        return array[0];
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return array[top];
    }

    void display()
    {
        cout << "========= Stack Elements =========" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s1(10);

    cout << "Before pushing" << endl;
    cout << "Full: " << s1.isFull() << endl;
    cout << "Empty: " << s1.isEmpty() << endl;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout << "After pushing" << endl;
    cout << "Full: " << s1.isFull() << endl;
    cout << "Empty: " << s1.isEmpty() << endl;

    cout << "Popped " << s1.pop() << " from the stack" << endl;

    cout << "Peeked " << s1.peek() << " from the stack" << endl;

    s1.display();

    return 0;
}