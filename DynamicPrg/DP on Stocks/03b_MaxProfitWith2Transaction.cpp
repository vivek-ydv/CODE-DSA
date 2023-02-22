#include <bits/stdc++.h>
using namespace std;

// Tabulation approach
int maxProfit(vector<int> &prices)
{
    // Creating a 3d - dp of size [n+1][2][3]
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));
    // Base case : since we had alreday initialised the dp vector with '0' hence all base case are coverd already as they have initial value '0'

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max((dp[idx + 1][1][cap]),
                                 (-prices[idx] + dp[idx + 1][0][cap]));
                }
                else
                {
                    // both possibilities sell or donot sell
                    profit = max((dp[idx + 1][0][cap]),
                                 (prices[idx] + dp[idx + 1][1][cap - 1]));
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int main()
{
    vector<int> Arr = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "The maximum profit by selling the stock is " << maxProfit(Arr);

    return 0;
}