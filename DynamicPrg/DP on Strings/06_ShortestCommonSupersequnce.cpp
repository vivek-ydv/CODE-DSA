#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string s1, string s2)
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

    // Let's get our desired super sequence
    int len = dp[n][m];
    int i = n;
    int j = m;

    string res = "";

    // Do dry run by making table for the better understanding of problem
    // https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res += s1[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) // Going up in table
        {
            res += s1[i - 1];
            i--;
        }
        else
        {
            // Moving horizentally left in table
            res += s2[j - 1];
            j--;
        }
    }
    // Adding Remaing Characters - Only one of the below two while loops will run
    while (i > 0)
    {
        res += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        res += s2[j - 1];
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

string shortestCommonSupersequence(string str1, string str2)
{
    return longestCommonSubsequence(str1, str2);
}
int main()
{

    string s1 = "brute";
    string s2 = "groot";

    cout << shortestCommonSupersequence(s1, s2);
    return 0;
}