#include <bits/stdc++.h>
using namespace std;
int fun(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    // base cases
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int idx = 0; idx <= i; idx++)
        {
            if (pattern[idx] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // All possible cases :
    if (pattern[i] == text[j] || pattern[i] == '?')
    {
        return dp[i][j] = fun(i - 1, j - 1, pattern, text, dp);
    }
    else if (pattern[i] == '*')
    {
        return dp[i][j] = fun(i - 1, j, pattern, text, dp) | fun(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}

bool isMatch(string s, string p)
{

    int n = p.size();
    int m = s.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(n - 1, m - 1, p, s, dp);
}
int main()
{
    string s = "abdef";
    string p = "ab?f";
    cout << isMatch(s, p);
    return 0;
}