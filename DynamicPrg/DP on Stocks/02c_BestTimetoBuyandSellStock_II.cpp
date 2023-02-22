#include <bits/stdc++.h>
using namespace std;

// Space optimistaion : O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<int> cur(2, 0), next(2, 0);

    // base case already cover as we had initialised next with 0

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max((next[1]),
                             (-prices[idx] + next[0]));
            }
            else
            {
                // both possibilities sell or donot sell
                profit = max((next[0]),
                             (prices[idx] + next[1]));
            }
            cur[buy] = profit;
        }
        next = cur;
    }
    return next[1];
}

int main()
{
    vector<int> Arr = {7, 1, 5, 3, 6, 4};
    cout << "The maximum profit by selling the stock is " << maxProfit(Arr);
}
