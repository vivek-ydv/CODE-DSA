#include <bits/stdc++.h>
using namespace std;
////////////* Imp : As here we are applying the binary search but we donot have the target element */////////////

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
            // this may be the answar that is why (end != mid - 1)
            end = mid;
        }
        if (arr[mid] < arr[mid + 1])
        {
            // You are in the ascending part of the array
            start = mid + 1; // Bcoz we know that mid + 1 element > mid element
        }
    }
    // In the end, start ==  end and pointing to the largest number becoz of above 2 checks,
    // Start and End are always trying to find the max element in the 2 checks,
    // At every point for the start and end have the best possible answar till that time,
    // Hence, when they are pointing to the just one element, that is the max one because that is what checks say.
    return start; // or return end ; as they both are equal
}
int main()
{

    vector<int> arr = {1, 2, 3, 5, 6, 4, 3, 2};
    cout << peakIndex(arr);
    return 0;
}