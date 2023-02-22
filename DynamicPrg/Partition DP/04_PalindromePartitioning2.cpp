#include <bits/stdc++.h>
using namespace std;
// Front Parition problem : Memoisation solution
bool isPalindrome(int s, int e, string str)
{
    while (s <= e)
    {
        if (str[s] != str[e])
            return false;
        s++, e--;
    }
    return true;
}

int fun(int idx, string s, vector<int> &dp)
{

    if (idx == s.size())
    {
        return 0;
    }

    if (dp[idx] != -1)
        return dp[idx];

    int min_cost = INT_MAX;
    for (int k = idx; k < s.size(); k++)
    {
        if (isPalindrome(idx, k, s))
        {
            int cost = 1 + fun(k + 1, s, dp);
            min_cost = min(min_cost, cost);
        }
    }
    return dp[idx] = min_cost;
}

int minCut(string s)
{

    vector<int> dp(s.size(), -1);
    return fun(0, s, dp) - 1; // since we are considering the parition at last but here it's not required
}
int main()
{

    string s = "aab";
    cout << minCut(s);
    return 0;
}