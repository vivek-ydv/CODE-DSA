#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;

        // insert in the last
        arr[index] = val;

        // move it to its correct position
        while (index > 1)
        {
            int parenti = index / 2;
            if (arr[parenti] < arr[index])
            {
                swap(arr[index], arr[parenti]);
                index = parenti;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(52);
    h.insert(57);
    h.insert(50);
    h.insert(55);
    h.insert(54);
    h.insert(66);

    h.print();

    return 0;
}