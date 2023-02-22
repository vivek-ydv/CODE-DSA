#include <bits/stdc++.h>
using namespace std;

// Mostly used for smaller values of n
// Works Good if array is partially sorted , this is reason why it takes part in hybrid sorting algorithms.
void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionsort(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    int arr[] = {1, 4, 2, 6, -3, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, size);
    Display(arr, size);
    return 0;
}