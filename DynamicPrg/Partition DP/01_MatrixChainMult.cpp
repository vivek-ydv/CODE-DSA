#include <bits/stdc++.h>
using namespace std;

// Memoisation_code
int fun(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (i == j){
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
    return fun(i, j, arr, dp);
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50};

    int n = arr.size();

    cout << "The minimum number of operations is " << matrixMultiplication(arr, n);

    return 0;
}