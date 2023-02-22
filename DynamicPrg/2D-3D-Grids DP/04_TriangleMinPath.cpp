#include <bits/stdc++.h>
using namespace std;
// Fixed starting point and Variable Ending Point
// Recursive + memoisation approach
int fun(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    // base case
    if (i == triangle.size() - 1)
    {
        return dp[i][j] = triangle[triangle.size() - 1][j];
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + fun(i + 1, j, triangle, dp);
    int diag = triangle[i][j] + fun(i + 1, j + 1, triangle, dp);

    return dp[i][j] = min(down, diag);
}

int minimumTotal(vector<vector<int>> &triangle)
{

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fun(0, 0, triangle, dp);
}
int main()
{
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};
    cout << minimumTotal(triangle);
    return 0;
}