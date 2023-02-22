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
    vector<int> nums = {3, 4, 5, 1, 2};

    // The idea is to find the pivot element as the suceeding element of the pivot is smallest element.
    int pivotindex = findpivot(nums);

    cout << nums[pivotindex + 1]; // Suceeding element of pivot

    return 0;
}
