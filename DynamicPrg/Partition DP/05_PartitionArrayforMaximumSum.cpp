#include <bits/stdc++.h>
using namespace std;
// Using Front Partition : Memoisation
int fun(int idx, int k, vector<int> &arr, vector<int> &dp)
{
    if (idx == arr.size())
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int max_sum = INT_MIN;
    int max_ele = 0;
    for (int i = idx; i < idx + k && i < arr.size(); i++)
    {
        max_ele = max(max_ele, arr[i]);
        int sum = max_ele * (i - idx + 1) + fun(i + 1, k, arr, dp);
        max_sum = max(max_sum, sum);
    }
    return dp[idx] = max_sum;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    vector<int> dp(arr.size(), -1);
    return fun(0, k, arr, dp);
}
int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr, k);
    return 0;
}