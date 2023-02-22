#include <bits/stdc++.h>
using namespace std;
// Tabulation approach
int longestIncreasingSubsequence(vector<int> arr)
{
    int n = arr.size();
    // As prev_idx will have -1 value initially so we have to do a coordinate shift
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Base case : As we had initialised the dp array with '0' so base case is already coverd
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int len = 0 + dp[ind + 1][prev_index + 1];
            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {

                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }

            dp[ind][prev_index + 1] = len;
        }
    }
    return dp[0][0];
}

int main()
{

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(arr);

    return 0;
}