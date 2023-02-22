#include <bits/stdc++.h>
using namespace std;

int fun(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e8;
    for (int k = i; k <= j; k++)
    {
        // cost required if we made cut at 'k'
        int cost = cuts[j + 1] - cuts[i - 1] + fun(i, k - 1, cuts, dp) + fun(k + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int minCost(int n, vector<int> &cuts)
{
    int c_len = cuts.size();
    // Insert these values at start and end to calculate the length
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    // We are sorting this so that we can solve the probelem independenlty : thumb rule of partition DP
    sort(cuts.begin(), cuts.end());

    int i = 1;     // Start from 1,since we had inserted at start of original cuts array
    int j = c_len; // Since two elements are inserted hence j will be now pointing to the last element of initial cuts array

    vector<vector<int>> dp(c_len + 1, vector<int>(c_len + 1, -1));
    return fun(i, j, cuts, dp);
}
int main()
{
    vector<int> cuts = {3, 5, 1, 4};

    int c = cuts.size();

    int n = 7;

    cout << "The minimum cost incurred: " << minCost(n, cuts);
    return 0;
}