#include <bits/stdc++.h>
using namespace std;

// Memoisation approach 
int fun(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    // base case
    if (idx == prices.size() || cap == 0)
    {
        return 0;
    }

    if (dp[idx][buy][cap] != -1)
    {
        return dp[idx][buy][cap];
    }

    int profit = 0;
    if (buy)
    {
        // both possiblites buy or not buy
        profit = max((fun(idx + 1, 1, cap, prices, dp)),
                     (-prices[idx] + fun(idx + 1, 0, cap, prices, dp)));
    }
    else
    {
        // both possibilities sell or donot sell
        profit = max((fun(idx + 1, 0, cap, prices, dp)),
                     (prices[idx] + fun(idx + 1, 1, cap - 1, prices, dp)));
    }

    return dp[idx][buy][cap] = profit;
}
int maxProfit(vector<int> &prices)
{
    // Creating a 3d - dp of size [n][2][3]
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));

    return fun(0, 1, 2, prices, dp);
}

int main()
{
    vector<int> Arr = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "The maximum profit by selling the stock is " << maxProfit(Arr);

    return 0;
}