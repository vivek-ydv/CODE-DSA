#include <bits/stdc++.h>
using namespace std;

// tabulation approach
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // All bases cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)          // value at '0' index must be less than target as dimesion of dp array are dp[n][target+1],
        dp[0][arr[0]] = true; // if(arr[0] > k) then these line will throw error of out of bound i.e. the above conditon

    // Perform loop according to recursive call and copy paste recursive fun logic
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }
    return dp[n - 1][k];
}

int main()
{

    vector<int> arr = {1, 3, 2, 5, 6};
    int k = 7;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with given target found";
    else
        cout << "Subset with given target not found";
}