#include <bits/stdc++.h>
using namespace std;

// recusion + memoisation
int fun(int i, int j, vector<vector<int>> &dp)
{
    // Base case
    if (i == 0 && j == 0)
        return dp[i][j] = 1;
    // Out of bound
    if (i < 0 || j < 0)
        return 0;

    // check that we had already calculated this subproblem or not
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = fun(i - 1, j, dp);
    int left = fun(i, j - 1, dp);

    return dp[i][j] = left + up;
}

int uniquePaths(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun(m - 1, n - 1, dp);
}

int main()
{

    int m = 3;
    int n = 2;

    cout << uniquePaths(m, n);
    return 0;
}