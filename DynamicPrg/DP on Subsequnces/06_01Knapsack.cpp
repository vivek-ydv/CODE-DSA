#include <bits/stdc++.h>
using namespace std;

// recursion + memoisation
int knapsackUtil(vector<int> &wt, vector<int> &val, int idx, int W, vector<vector<int>> &dp)
{
    // Base case
    if (idx == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];

    // pick or not pick approach
    int notTake = 0 + knapsackUtil(wt, val, idx - 1, W, dp);
    int take = INT_MIN;
    if (wt[idx] <= W)
    {
        take = val[idx] + knapsackUtil(wt, val, idx - 1, W - wt[idx], dp);
    }

    return max(take, notTake);
}

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main()
{

    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;

    int n = wt.size();

    cout << "The Maximum value of items, thief can steal is " << knapsack(wt, val, n, W);
}