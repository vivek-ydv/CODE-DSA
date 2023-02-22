#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};  // 0 rotation
    vector<int> nums1 = {6, 1, 2, 3, 4, 5}; // 1 rotation
    vector<int> nums2 = {5, 6, 1, 2, 3, 4}; // 2 rotation
    vector<int> nums3 = {3, 4, 5, 6, 1, 2}; // 4 rotation

    // The idea is to find the pivot element and return the (pivotindex  + 1) to get the
    // number of rotation it is also clear from the observation in above example.

    int pivotindex = findpivot(nums3);
    cout <<(pivotindex + 1);
    return 0;
}
