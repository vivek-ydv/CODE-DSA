#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int length)
{
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void display(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 5, -6, 4, -7, -11, 15, -9};
    int length = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, length);
    display(arr, length);
    return 0;
}