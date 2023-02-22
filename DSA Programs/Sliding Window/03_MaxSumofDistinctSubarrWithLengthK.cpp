#include <bits/stdc++.h>
using namespace std;

// Approach 1 :
long long maximumSubarraySum1(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    map<int, int> mp;
    long long res = 0;
    long long sum = 0;
    while (r < nums.size())
    {
        if (mp.find(nums[r]) != mp.end())
        {
            int idx = r - 1;
            while (nums[idx] != nums[r])
                idx--;

            l = idx + 1;
            r = l;
            mp.clear();
            sum = 0;
        }

        mp[nums[r]]++;
        sum += nums[r];

        while (mp.size() > k)
        {
            mp[nums[l]]--;
            sum -= nums[l];

            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        if (mp.size() == k)
        {
            res = max(res, sum);
        }
        r++;
    }
    return res;
}

// Approach 2 : Fixed size window
long long maximumSubarraySum2(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    map<int, int> mp;
    long long res = 0;
    long long sum = 0;

    // First take k elements : window of size k
    for (; r < k; r++)
    {
        mp[nums[r]]++;
        sum += nums[r];
    }
    if (mp.size() == k)
        res = sum;

    while (r < nums.size())
    {

        mp[nums[r]]++;
        sum += nums[r];

        mp[nums[l]]--;
        sum -= nums[l];
        if (mp[nums[l]] == 0)
            mp.erase(nums[l]);
        l++;

        if (mp.size() == k)
        {
            // we will consider the value of sum only when the map size == k,means that there are no duplicate present,
            // As if duplicates were present then map size will never equals to k, since we had taken a window of k size.
            res = max(res, sum);
        }
        r++;
    }
    return res;
}
int main()
{
    // Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    // > The length of the subarray is k, and
    // > All the elements of the subarray are distinct.

    vector<int> nums = {9, 18, 10, 13, 17, 9, 19, 2, 1, 18};
    int k = 5;
    cout << maximumSubarraySum2(nums, k);
    return 0;
}