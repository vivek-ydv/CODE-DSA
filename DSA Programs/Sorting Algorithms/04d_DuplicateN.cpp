#include <bits/stdc++.h>
using namespace std;

int duplicate(int *arr, int length)
{
    int i = 0;
    while (i < length)
    {
        int correctindex = arr[i] - 1;
        if (arr[i] != arr[correctindex])
        {
            // Swap the current index value with corrected index value
            int temp = arr[i];
            arr[i] = arr[correctindex];
            arr[correctindex] = temp;
        }
        else
            i++;
    }

    // Search For duplicate Number
    for (int j = 0; j < length; j++)
    {
        if (j != arr[j] - 1)
            return arr[j];
    }
    return -1;
}

int main()
{
    // Find the duplicate number in range (1-N)
    int arr[] = {3, 1, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << duplicate(arr, size);

    return 0;
}