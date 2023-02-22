#include <bits/stdc++.h>
using namespace std;
/******************WHEN RANGE IS GIVEN FROM (1 to N) USE CYCLIC SORT******************/

void cyclicsort(int *arr, int length)
{
    int i = 0;
    while (i < length)
    {
        int correctindex = arr[i] - 1; // If range is (1 - N)
        {
            if (arr[i] != arr[correctindex] && arr[i] > 0)
            {
                // Swap the current index value with corrected index value
                int temp = arr[i];
                arr[i] = arr[correctindex];
                arr[correctindex] = temp;
            }
            else
                i++;
        }
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
    int arr[] = {3, 5, 2, 7, 1, 6, 4}; // Array must be contunous
    int size = sizeof(arr) / sizeof(arr[0]);
    cyclicsort(arr, size);
    Display(arr, size);
    return 0;

    return 0;
}