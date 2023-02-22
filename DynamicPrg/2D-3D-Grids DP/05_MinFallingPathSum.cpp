#include <bits/stdc++.h>
using namespace std;
// Variable starting point and Variable Ending Point
// We can do this in two ways either fix a start point or fix a end point
// Here we will be fixing the end point
int fun(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Out of bound case
    if (j < 0 || j >= matrix.size())
        return 1e8;
    // base case
    if (i == 0)
        return dp[i][j] = matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    // do all possible stuffs
    int up = matrix[i][j] + fun(i - 1, j, matrix, dp);
    int leftdiag = matrix[i][j] + fun(i - 1, j - 1, matrix, dp);
    int rightdiag = matrix[i][j] + fun(i - 1, j + 1, matrix, dp);

    return dp[i][j] = min(up, min(leftdiag, rightdiag));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int res = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // fix each element of last row and call fun for each
    for (int j = 0; j < n; j++)
    {
        int mini = fun(n - 1, j, matrix, dp);
        res = min(mini, res);
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix{
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9},
    };
    cout << minFallingPathSum(matrix);
    return 0;
}