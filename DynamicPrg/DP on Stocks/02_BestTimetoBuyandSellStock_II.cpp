#include <bits/stdc++.h>
using namespace std;

// We can buy and sell the stock any number of times.
// In order to sell the stock, we need to first buy it on the same or any previous day.
// We first buy a stock and then sell it. After selling we can buy and sell again.
// But we can’t sell before buying and can’t buy before selling any previously bought stock.

// Memoisation approach
int fun(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    // base case
    if (idx == prices.size())
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = 0;
    if (buy)
    {
        // both possiblites buy or not buy
        profit = max((fun(idx + 1, 1, prices, dp)),
                     (-prices[idx] + fun(idx + 1, 0, prices, dp)));
    }
    else
    {
        // both possibilities sell or donot sell
        profit = max((fun(idx + 1, 0, prices, dp)),
                     (prices[idx] + fun(idx + 1, 1, prices, dp)));
    }
    return dp[idx][buy] = profit;
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return fun(0, 1, prices, dp); // buy == 1 i.e. initially allowed to buy
}

int main()
{
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    cout << "The maximum profit by selling the stock is " << maxProfit(Arr);
}