#include <bits/stdc++.h>
using namespace std;
// Memoisation + Recursive Approach
int fun(int i1, int i2, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;

    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    if (str1[i1] == str2[i2])
    {
        return 1 + fun(i1 - 1, i2 - 1, str1, str2, dp);
    }
    else
    {
        return dp[i1][i2] = max(fun(i1 - 1, i2, str1, str2, dp), fun(i1, i2 - 1, str1, str2, dp));
    }
}

int longestCommonSubsequence(string text1, string text2)
{

    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(n - 1, m - 1, text1, text2, dp);
}
int main()
{
    string s1 = "acd";
    string s2 = "ced";

    cout << "The Length of Longest Common Subsequence is " << longestCommonSubsequence(s1, s2);
    return 0;
}