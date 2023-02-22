#include <bits/stdc++.h>
using namespace std;
// 3D DP PROBLM MORE EXPLN: https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/

int fun(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // Out of bound case
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
        return -1e9;
    // Base case
    if (i == n - 1)
    {
        if (j1 == j2) // when both are at the same cell then we have to consider cherry pick only once
            return dp[i][j1][j2] = grid[i][j1];
        else
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // Do all possible stuffs and get max off all those stuffs
    // For each movement of ine there are three possibilities of movement of other one
    // here dj1 and dj2 are direection variable with value {-1,0,+1}
    int maxi = INT_MIN;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val;
            if (j1 == j2) // when both are at the same cell then we have to consider only once
            {
                val = grid[i][j1] + fun(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            }
            else
            {
                val = grid[i][j1] + grid[i][j2] + fun(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            }
            maxi = max(maxi, val);
        }
    }
    // store the answar for the current call of (i,j1,j2)
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return fun(0, 0, m - 1, n, m, grid, dp);
}
int main()
{
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };
    cout << cherryPickup(matrix);
    return 0;
}