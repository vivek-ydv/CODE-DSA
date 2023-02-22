#include <bits/stdc++.h>
using namespace std;
// Memoisation approach : printing length of LIS

int fun(int idx, int prev_idx, vector<int> &arr, vector<vector<int>> &dp)
{
    // base case
    if (idx == arr.size())
        return 0;

    if (dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }

    // Not pick the current element
    int len = fun(idx + 1, prev_idx, arr, dp);

    // Trying to pick the current element
    if (prev_idx == -1 || arr[idx] > arr[prev_idx])
    {
        len = max(len, 1 + fun(idx + 1, idx, arr, dp));
    }
    return dp[idx][prev_idx + 1] = len;
}

int longestIncreasingSubsequence(vector<int> arr)
{
    int n = arr.size();
    // As prev_idx will have -1 value initially so we have to do a coordinate shift
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fun(0, -1, arr, dp);
}

int main()
{

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(arr);

    return 0;
}