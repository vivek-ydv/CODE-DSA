#include <bits/stdc++.h>
using namespace std;

int missing(int *arr, int length)
{
    int i = 0;
    while (i < length)
    {
        int correctindex = arr[i];
        if (arr[i] != arr[correctindex] && arr[i] < length) // If found the largest number ignore it(edge case)
        {
            // Swap the current index value with corrected index value
            int temp = arr[i];
            arr[i] = arr[correctindex];
            arr[correctindex] = temp;
        }
        else
            i++;
    }

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Search For Missing Number
    for (int j = 0; j < length; j++)
    {
        if (j != arr[j])
            return j;
    }
    // case 2:
    return length; // i.e. n is the missing number
}

int main()
{
    // Find the missing number in range (0-N)
    int arr[] = {4, 0, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << missing(arr, size);
    return 0;
}