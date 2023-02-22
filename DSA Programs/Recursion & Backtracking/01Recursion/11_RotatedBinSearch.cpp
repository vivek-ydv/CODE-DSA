#include <bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> arr, int target, int start, int end)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        return -1;
    }

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[start] <= arr[mid]) // Left part is sorted
    {
        if (target >= arr[start] && target < arr[mid]) // Element is present on the left side
        {
            return rotatedSearch(arr, target, start, mid - 1);
        }
        else // Element is present on the right side
        {
            return rotatedSearch(arr, target, mid + 1, end);
        }
    }

    else // Right part is sorted
    {
        if (target > arr[mid] && target < arr[end]) // Element is present on the right side
        {
            return rotatedSearch(arr, target, mid + 1, end);
        }
        else // Element is present on the left side
        {
            return rotatedSearch(arr, target, start, mid - 1);
        }
    }
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 5;
    cout << rotatedSearch(arr, target, 0, arr.size() - 1);

    return 0;
}