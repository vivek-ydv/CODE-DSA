#include <bits/stdc++.h>
using namespace std;
// RECURSION + MEMOISATION
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return dp[i][j] = grid[i][j];
    }
    // Out of bound return a very large value so that we can't take it in our path
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int left = grid[i][j] + f(i, j - 1, grid, dp);
    int up = grid[i][j] + f(i - 1, j, grid, dp);

    return dp[i][j] = min(left, up);
}
int minPathSum(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, grid, dp);
}
int main()
{

    vector<vector<int>> matrix{{5, 9, 6},
                               {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << minPathSum(matrix);
    return 0;
}