#include <bits/stdc++.h>
using namespace std;

/**************************VERY IMP CONCEPT**************************/
/************************Minimise The Maximum************************/

int splitArray(vector<int> &nums, int m)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        start = max(start, nums[i]); // At terimnation of loop it will have the max value
        end += nums[i];
    }
    while (start < end)
    {
        int sum = 0;
        int pieces = 1; // Initially we have at least one piece
        int mid = start + (end - start) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] > mid)
            {
                // Now first subarray is full, hence you can not add into this make new one & this new subarray will start from the current index of array due to which sum was exceeding.
                // Now new sum will begin for the next subarray and since the first value of the new subarray is the current element,hence sum will start from this element.
                sum = nums[i];
                pieces++; // update the number of subarrays
            }
            else
            {
                // Normally add cuurent element to the sum
                sum += nums[i];
            }
        }

        if (pieces <= m)
        {
            // If pieces all less than 'm', means that individual subarray(pieces) sum is larger hence we have to reduces the mid(individual sum of subarray) to some lower value.
            // If pieces are equal to then, then it's clear that right side of this value(mid) will be able to divide it into 'm' parts but
            // here we are "minimising the largest sum", hence we will further look for more potential answar on the left side of mid
            end = mid;
        }
        else
        {
            // If pieces are greater than 'm' means that individual sum of pieces is smaller hence we have to increase the mid(individual sum of subarray) to larger value.
            start = mid + 1;
        }
    }
    return end; // return start, as they are pointing to same value of mid.
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    int m = 2;
    cout << splitArray(arr, m);
    return 0;
}