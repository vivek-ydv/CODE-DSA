#include <bits/stdc++.h>
using namespace std;

// Space optimised Approach : If do a dry run of tabulation process then we will observe that,
// we only need the next row, in order to calculate dp[i][j]. Therefore we can space optimize it.
// Initially we can take a dummy row (say next). We initialize this row to the triangle matrix last row( as done in tabulation).
// Now the current row(say cur) only needs the next row’s value in order to calculate dp[i][j].
// SC: O(N) & TC: O(N*N)
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> next(n, 0), cur(n, 0);
    for (int j = 0; j < n; j++)
    {
        next[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + next[j];
            int diagonal = triangle[i][j] + next[j + 1];

            cur[j] = min(down, diagonal);
        }
        next = cur;
    }
    return next[0];
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