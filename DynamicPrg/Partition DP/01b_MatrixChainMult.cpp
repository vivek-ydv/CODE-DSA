#include <bits/stdc++.h>
using namespace std;

// Tabulation_code
int fun(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = fun(i, k, arr, dp) + fun(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, steps);
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{

    int i = 1;
    int j = N - 1;
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Base case
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0; // when (i == j)
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;
            // partioning loop
            for (int k = i; k <= j - 1; k++)
            {
                int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};

    int n = arr.size();

    cout << "The minimum number of operations is " << matrixMultiplication(arr, n);

    return 0;
}