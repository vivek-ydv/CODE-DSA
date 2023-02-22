#include <bits/stdc++.h>
using namespace std;

// Approach 2 : using k, buckets and fill them by all way unitll we donot get all buckets filled with target value
bool backtrack(int idx, int target, vector<int> &bucket, vector<int> &nums)
{
    // Base case
    if (idx == nums.size())
    {

        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] != target)
                return false;
        }
        return true;
    }
    for (int i = 0; i < bucket.size(); i++)
    {
        // prune the recursion calls
        if (bucket[i] + nums[idx] > target || (i > 0 && bucket[i] == bucket[i - 1]))
            continue;

        bucket[i] += nums[idx];
        if (backtrack(idx + 1, target, bucket, nums)) // once found, just return
            return true;
        bucket[i] -= nums[idx]; // backtrack
    }
    return false;
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int sum = 0;
    for (auto it : nums)
        sum += it;
    if (sum % k != 0)
        return false;
    int target = sum / k;
    sort(nums.rbegin(), nums.rend()); /***** reverse sort the array *****/

    vector<int> bucket(k, 0);
    return backtrack(0, target, bucket, nums);
}
int main()
{

    return 0;
}