#include <iostream>
using namespace std;

int *bubble(int arr[], int n, int i)
{
    if (n == 1)
    {
        return arr;
    }
    if (i < n)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
        return bubble(arr, n, i + 1);
    }
    else
    {
        return bubble(arr, n - 1, 1);
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
    int arr[] = {5, 1, 4, 2, 6, -3, 0, 7, -19};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *res = bubble(arr, size, 1);
    Display(res, size);
    return 0;
}