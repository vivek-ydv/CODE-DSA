#include <bits/stdc++.h>
using namespace std;

// Find the greatest element in array less or equal to target
int binSearch(int *arr, int length, int target)
{
    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        // If target is smaller than the smallest number in the array
        if (target < arr[0])
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
    return arr[end];
}

int main()
{
    int arr[] = {2, 3, 5, 9, 14, 16, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << binSearch(arr, size, 4);

    return 0;
}