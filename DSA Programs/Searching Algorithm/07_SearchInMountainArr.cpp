#include <bits/stdc++.h>
using namespace std;
int peakIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            // It means that you are in decreasing part of the arrray
            // this may be the answar that is why end! = mid - 1
            end = mid;
        }
        if (arr[mid] < arr[mid + 1])
        {
            // You are in the ascending part of the array
            start = mid + 1; // Bcoz we know that mid + 1 element > mid element
        }
    }
    return start;
}
int OrderAgnosticBS(vector<int> arr, int start, int end, int target)
{

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

// MAIN LOGIC FOR THIS PROBLEM , Other than this we are using our previous concept!!
// This is how YOU have to break a hard problem into subproblem and Solve hard problem easily!!!!
int searchinMountain(vector<int> arr, int target)
{
    int peak = peakIndex(arr);
    int targetindex;

    targetindex = OrderAgnosticBS(arr, 0, peak, target); // Search on the left side of peak index(ascending order)

    if (targetindex == -1) // Element not found on the left side of peak index So Search in second half
    {
        targetindex = OrderAgnosticBS(arr, peak + 1, arr.size() - 1, target); // Search on the right side of peak index (descending order)
    }

    return targetindex;
}

int main()
{

    // If More than one index exist return the minimum index
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 1};
    // vector<int> arr = {0, 1, 2, 4, 2, 1};
    int target = 3;

    cout << searchinMountain(arr, target);
    return 0;
    return 0;
}