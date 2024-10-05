#include <iostream>
using namespace std;

int traversal(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int insertionAtIndex(int array[], int element, int index, int size, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = element;
    }
    return 1;
}

int main()
{
    int array[100] = {1, 2, 3, 4, 5};
    int size = 5, element = 45, index = 3, capacity = 100;
    traversal(array, size);
    insertionAtIndex(array, element, index, size, capacity);
    size += 1;
    traversal(array, size);
    return 0;
}