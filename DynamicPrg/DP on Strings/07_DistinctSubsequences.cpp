#include <bits/stdc++.h>
using namespace std;

// Memoisation solution : TLE
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
    {
        // when match happens we have both choices either match it or ignore it.
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    }
    else
    {
        // we have only one option to ignore current idx charcter.
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return f(n - 1, m - 1, s, t, dp);
}
int main()
{
    string s = "babgbag";
    string t = "bag";

    cout << numDistinct(s, t);
    return 0;
}