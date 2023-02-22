#include <bits/stdc++.h>
using namespace std;
// Here we are considering that our array also contains '0'
// More details : https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/

int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        else if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

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

    vector<int> arr = {0, 0, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);
}