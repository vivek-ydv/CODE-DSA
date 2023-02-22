#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/target-sum/
// This solution is correct but it is taking more time (TLE Error),
// hence we have to optimise it for that first we have to learn about the dynamic programming
int res = 0;
void helper(vector<int> &up, int target, int sum, int i)
{
    if (target == sum && i == up.size())
    {
        res++;
        return;
    }
    if ((sum > target || sum < target) && i == up.size())
    {
        return;
    }
    helper(up, target, sum + up[i], i + 1);
    helper(up, target, sum - up[i], i + 1);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    helper(nums, target, 0, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int tar = 3;
    findTargetSumWays(nums, tar);
    cout << res;
    return 0;
}