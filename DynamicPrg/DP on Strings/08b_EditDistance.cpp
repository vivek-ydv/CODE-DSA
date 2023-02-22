#include <bits/stdc++.h>
using namespace std;

// Tabulation approach
int editDistance(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i; // when j == 0
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j; // when i == 0
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] =  dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1],
                                   min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int main()
{

    string s1 = "horse";
    string s2 = "ros";

    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
}
