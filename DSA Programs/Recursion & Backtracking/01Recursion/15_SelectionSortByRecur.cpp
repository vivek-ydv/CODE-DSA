#include <iostream>
using namespace std;

int *Selection(int *arr, int n, int maxindex, int i)
{
    if (n == 1)
    {
        return arr;
    }

    if (i < n)
    {
        if (arr[i] > arr[maxindex])
            return Selection(arr, n, i, i + 1);

        else
            return Selection(arr, n, maxindex, i + 1);
    }
    else
    {
        int last = n - 1;

        int temp = arr[last];
        arr[last] = arr[maxindex];
        arr[maxindex] = temp;

        return Selection(arr, n - 1, 0, 1);
    }
}

void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 14, 22, 6, -3, 0, 5, -19, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *res = Selection(arr, size, 0, 1); // max index : 0 & i : 1

    Display(res, size);
    return 0;
}