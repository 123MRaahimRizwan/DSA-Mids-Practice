#include <iostream>
using namespace std;

void bubbleSort(int array[], int n)
{
    bool isSwapped = false;
    for (int i = 0; i < n; i++)
    {
        isSwapped = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isSwapped = false;
            }
        }
        if (isSwapped)
        {
            break;
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    int A[] = {10, 2, 30, 45, 59};
    cout << "Array before sorting" << endl;
    printArray(A, n);

    bubbleSort(A, n);
    cout << "Array after sorting" << endl;
    printArray(A, n);
    return 0;
}