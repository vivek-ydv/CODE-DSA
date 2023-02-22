#include <bits/stdc++.h>
using namespace std;
/*********************APPROACH 1 :By Pivot Element*****************/

int findpivot(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
        {
            // If donot add { mid < end } condition then if pivot element is last element then it will go out of bound.
            // It will display the heap buffer overlflow error.
            return mid;
        }
        if (mid > start && arr[mid - 1] > arr[mid])
        {
            // If donot add { mid > start:0 } condition then if pivot element is first element then it will go to negative index and will throw some error.
            return mid - 1;
        }

        if (arr[start] >= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int binSearch(vector<int> arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            start = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}

int searchRotated(vector<int> arr, int target)
{
    int pivot = findpivot(arr);

    if (pivot == -1) // It means that the array is not rotated
    {
        // Just do simple binary search
        return binSearch(arr, target, 0, arr.size() - 1);
    }
    if (arr[pivot] == target)
    {
        return pivot;
    }

    if (arr[0] <= target)
    {
        return binSearch(arr, target, 0, pivot - 1);
    }
    else
    {
        return binSearch(arr, target, pivot + 1, arr.size() - 1);
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    //   vector<int> arr = {2,2,2,2,2,9,2,2,2};
    //   int target = 9;   // Here it will fail

    cout << searchRotated(arr, target);
    return 0;
}