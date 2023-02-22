#include <bits/stdc++.h>
using namespace std;

// When we donot know the array is sorted is in ascendng order or the descending order
int OrderAgnosticBS(int *arr, int length, int target)
{
    int start = 0;
    int end = length - 1;
    // Find the array is ascending or descending
    bool isAsc = arr[start] < arr[end];

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (isAsc) // Sorted in asscending order
        {
            if (arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        else // Sorted in descending order
        {
            if (arr[mid] > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    //  int arr[] = {2, 4, 5, 8, 9, 11, 15};
    int arr[] = {14, 12, 8, 6, 5, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int check = OrderAgnosticBS(arr, size, 5);
    cout << check;
    return 0;
}