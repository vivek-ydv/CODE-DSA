#include <bits/stdc++.h>
using namespace std;
// Approach : 1 (Finding taget sum k times)
bool fun(int start, int &target, int cursum, int k, vector<bool> &vis, vector<int> &nums)
{
    if (k == 1)
        return true;

    if (target == cursum) // we had found a subset now search for other remaining subset(k-1)
        return fun(0, target, 0, k - 1, vis, nums);

    for (int i = start; i < nums.size(); i++)
    {
        if (vis[i] || cursum + nums[i] > target)
            continue;

        vis[i] = true;
        if (fun(i + 1, target, cursum + nums[i], k, vis, nums))
        {
            return true;
        }
        vis[i] = false;

        /*Pruning the calls :- since our given array contains duplicate and our function will reach here only if we are not able to find the solution by picking this element,hence again calling the function by picking same element will not help to get the solution hence we can prune our solution by not considering all these duplicate elements(make sure array must be sorted.*/
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
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
    vector<bool> vis(nums.size(), false);

    sort(nums.begin(), nums.end());
    return fun(0, target, 0, k, vis, nums);
}

int main()
{

    return 0;
}