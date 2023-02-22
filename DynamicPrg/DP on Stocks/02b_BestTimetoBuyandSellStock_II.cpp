#include <bits/stdc++.h>
using namespace std;

// Tabulation approach
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // base case
    dp[n][0] = dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max((dp[idx + 1][1]),
                             (-prices[idx] + dp[idx + 1][0]));
            }
            else
            {
                // both possibilities sell or donot sell
                profit = max((dp[idx + 1][0]),
                             (prices[idx] + dp[idx + 1][1]));
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    cout << "The maximum profit by selling the stock is " << maxProfit(Arr);
}
