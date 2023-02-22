#include <bits/stdc++.h>
using namespace std;
/*********************APPROACH 2 :By Finding All Possible Cases*****************/

int searchRotated(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[start] <= arr[mid]) // Left part is sorted
        {
            if (target >= arr[start] && target < arr[mid]) // Target is present on left side
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        else // Right part is sorted
        {
            if (target > arr[mid] && target <= arr[end]) // Target is present on right side
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // vector<int> arr = {2, 3, 2, 2, 2};
    // int target = 3; // Here it will fail

    cout << searchRotated(arr, target);
    return 0;
}