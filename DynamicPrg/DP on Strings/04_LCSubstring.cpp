#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    int res = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                res = max(res, dp[ind1][ind2]);
            }
            else
            {
                // The characters don’t match, therefore the consecutiveness of characters is broken.
                // So we set the cell value (dp[i][j]) as 0.
                dp[ind1][ind2] = 0;
            }
        }
    }
    return res;
}
int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "The Length of Longest Common Subsequence is " << longestCommonSubstring(s1, s2);
    return 0;
}