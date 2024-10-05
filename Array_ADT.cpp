#include <iostream>
using namespace std;

class ADT
{
public:
    int total_size;
    int used_size;
    int *ptr;

    ADT(int tSize, int uSize)
    {
        total_size = tSize;
        used_size = uSize;
        ptr = new int[used_size];
    }

    void setVal()
    {
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter value " << i + 1 << endl;
            cin >> n;
            ptr[i] = n;
        }
    }

    void show()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~ADT()
    {
        delete[] ptr;
    }
};

int main()
{
    ADT a1(10, 2);
    a1.setVal();
    a1.show();
    return 0;
}