#include <bits/stdc++.h>
using namespace std;
// 0 <= arr[i] << 10^9 : Arr also contains '0'
// Tabulation
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2; // 2 cases -pick and not pick
    else
        dp[0][0] = 1; // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1; // 1 case -pick

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken);
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    /*
    S1 - S2 = D   – (i)
    S1 >= S2     – (ii)
    If we calculate the total sum of elements of the array (say totSum), we can say that,
    S1 = totSum – S2      – (iii)
    Now solving for equations (i) and (iii), we can say that
    
    S2 = (totSum – D)/2    – (iv)
    Now problem is reduced to count the subset with value s2.
    */

    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    return findWays(arr, (totSum - d) / 2);
}

int main()
{

    vector<int> arr = {5, 2, 6, 4};
    int n = arr.size();
    int d = 3;

    cout << "The number of subsets found are " << countPartitions(n, d, arr);
}