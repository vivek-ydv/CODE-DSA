#include <bits/stdc++.h>
using namespace std;
int fun(int idx, int target, int sum, vector<int> &nums, vector<unordered_map<int, int>> &dp)
{
    // Always call by refrence otherwise face TLE :(
    if (idx == 0)
    {
        if (nums[0] == 0 && target == sum)
        {
            // as our test case also considers '0'
            return 2;
        }
        else if (sum - nums[0] == target || sum + nums[0] == target)
        {
            return 1;
        }
        else
            return 0;
    }
    auto it = dp[idx].find(sum);
    if (it != dp[idx].end())
        return it->second;

    int plus = 0, min = 0;
    plus = fun(idx - 1, target, sum + nums[idx], nums, dp);
    min = fun(idx - 1, target, sum - nums[idx], nums, dp);

    return dp[idx][sum] = plus + min;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    // As our sum value may go negative hence to handle that case
    vector<unordered_map<int, int>> dp(nums.size());
    return fun(n - 1, target, 0, nums, dp);
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;

    cout << "The number of ways found is " << findTargetSumWays(arr, target);
    return 0;
}