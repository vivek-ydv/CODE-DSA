#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxlen = 1;
    int maxlen_idx = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i; // initially hash array have value equal to its index
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i])
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if (dp[i] > maxlen)
        {
            maxlen = dp[i];
            maxlen_idx = i; // store the index
        }
    }

    vector<int> temp;
    temp.push_back(arr[maxlen_idx]);

    int idx = maxlen_idx;
    while (hash[idx] != idx)
    {
        idx = hash[idx];
        temp.push_back(arr[idx]);
    }

    reverse(temp.begin(), temp.end());
    cout << "LIS : ";
    for (auto it : temp)
        cout << it << " ";
    cout << endl;
    return maxlen;
}

int main()
{

    // vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> arr = {5, 4, 11, 1, 16, 8};

    int res = longestIncreasingSubsequence(arr);
    cout << "The length of the longest increasing subsequence is "
         << res;

    return 0;
}