// Intution : Since palindrome will remain same if we reverse it.
//  So we can reverse the string and find the LCS between both string and reverse string to get the rquired longest palindromic subsequence.
// Simply we can say that : The longest palindromic subsequence of a string is the longest common subsequence of the given string and its reverse.

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Base case : After shifting indexes
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;

    return longestCommonSubsequence(s1, s2);
}
int main()
{
    string s = "bbabcbcab";

    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence(s);
    return 0;
}