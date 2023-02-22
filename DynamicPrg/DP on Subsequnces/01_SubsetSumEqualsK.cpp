#include <bits/stdc++.h>

using namespace std;

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (target == 0)
        return true;
    if (ind == 0)
    {
        if (arr[0] == target)
            return true;
        else
            return false;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Not pick the current element
    bool notPick = subsetSumUtil(ind - 1, target, arr, dp);

    // Intially we are taking pick as false because we will be first checking the condition;
    // that it is smaller than our current target or not
    bool pick = false;
    if (arr[ind] <= target)
        pick = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notPick || pick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with given target found";
    else
        cout << "Subset with given target not found";
}