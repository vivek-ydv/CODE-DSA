#include <bits/stdc++.h>
using namespace std;

// Tabulation approach
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // declare one size greater as we will be doing the shifting of idx
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base case
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1; // i.e. when (j==0 then 1)
    }
    for (int j = 1; j <= m; j++)
    {
        // as when j==0 i.e. dp[0][0] must be 1
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                // when match happens we have both choices either match it or ignore it.
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s = "babgbag";
    string t = "bag";

    cout << numDistinct(s, t);
    return 0;
}