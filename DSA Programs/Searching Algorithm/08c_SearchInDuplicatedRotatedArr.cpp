#include <bits/stdc++.h>
using namespace std;

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
        // This is the logical Case i.e. if element at left, right & end are equal then skip that element by moving left & right and
        // Continue to next iteration.
        if (arr[start] == arr[mid] && arr[end] == arr[mid])
        {
            start++;
            end--;
            continue;
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

    vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
    int target = 2;

    cout << searchRotated(arr, target);
    return 0;
}