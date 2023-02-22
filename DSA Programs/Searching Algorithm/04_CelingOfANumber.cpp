#include <bits/stdc++.h>
using namespace std;

// Find the smallest element in array greater or equal to target
int binSearch(int *arr, int length, int target)
{
    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        // If target is greater than the gretest number in the array
        if (target > arr[length -1])
        {
            return -1;
        }
        
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return arr[mid];

        if (arr[mid] < target)
            start = mid + 1;

        else
            end = mid - 1;
    }
    return arr[start];
}

int main()
{
    int arr[] = {2, 3, 5, 9, 14, 16, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << binSearch(arr, size, 15);

    return 0;
}