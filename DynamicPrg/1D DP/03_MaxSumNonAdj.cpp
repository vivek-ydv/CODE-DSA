#include <bits/stdc++.h>

using namespace std;
// Memoisation approach
int fun(int idx, vector<int>& arr, vector<int>& dp)
{
    // Always pass vector array by reference otherwise you will face TLE.
    if (idx == 0)
        return arr[idx];
    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int pick = arr[idx] + fun(idx - 2, arr, dp);
    int notpick = 0 + fun(idx - 1, arr, dp);

    return dp[idx] = max(pick, notpick);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << fun(n - 1, arr, dp);
}