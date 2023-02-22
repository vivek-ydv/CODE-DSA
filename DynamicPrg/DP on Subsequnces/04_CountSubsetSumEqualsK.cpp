#include <bits/stdc++.h>
using namespace std;

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (target == 0)
        return 1;
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    // Intially we are taking taken as '0' because we will be first checking the condition;
    // that it is smaller than our current target or not
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    // simply add up to get the all ways
    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

int main()
{

    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);
}