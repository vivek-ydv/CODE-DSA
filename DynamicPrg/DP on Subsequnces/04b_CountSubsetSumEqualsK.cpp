#include <bits/stdc++.h>

using namespace std;

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // All base cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= k) // check so that we didnot get out of bound runtime error
        dp[0][num[0]] = 1;

    // Perform loop according to recursive call and copy paste recursive fun logic
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][k];
}

int main()
{

    vector<int> arr = {0, 0, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);
}