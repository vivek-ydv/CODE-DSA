#include <bits/stdc++.h>
using namespace std;
// Best Explanation : https://leetcode.com/problems/burst-balloons/discuss/892552/For-those-who-are-not-able-to-understand-any-solution-WITH-DIAGRAM

int fun(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    // For all elements in the range i to j, we choose all of them one by one
    // to make them the last balloon to be burst.
    for (int k = i; k <= j; k++)
    {
        int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                    fun(i, k - 1, nums, dp) + fun(k + 1, j, nums, dp); // Recursively solve the left and right subproblems and add their contribution
        maxi = max(maxi, coins);
    }

    return dp[i][j] = maxi;
}
int maxCoins(vector<int> &nums)
{

    int n = nums.size();
    // Insert two dummy balloons of value 1 to handle the balloons on the corner.
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return fun(1, n, nums, dp);
}
int main()
{
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums);
    return 0;
}