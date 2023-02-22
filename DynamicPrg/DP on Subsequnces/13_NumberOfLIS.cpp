#include <bits/stdc++.h>
using namespace std;
// More detailed explanation : https://takeuforward.org/data-structure/number-of-longest-increasing-subsequences-dp-47/
int findNumberOfLIS(vector<int> &arr)
{

    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] : refers to the length of LIS of the array with the element arr[i] as the last element.
    vector<int> ct(n, 1); // cnt[i]: refers to the count of LIS of the array that are possible with length of dp[i] with element arr[i] as the last element.
    int max_len = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp[prev] + 1 > dp[i])
            {
                // Inherit the count : since we know that arr[i] > arr[prev], so we can append it and count remains same as count of prev.
                dp[i] = dp[prev] + 1;
                ct[i] = ct[prev]; // As only length is increased by appending so, Count of LIS after appending = Count Of LIS before appending.
            }
            else if (arr[i] > arr[prev] && dp[prev] + 1 == dp[i])
            {
                // In such a case we need to consider both the existing and the new LIS,as the lenght of both LIS is same.
                // Therefore, we will update ct[i] = ct[i] + ct[prev], i.e to count both the LIS.
                ct[i] = ct[i] + ct[prev];
            }
        }
        max_len = max(max_len, dp[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == max_len)
        {
            res += ct[i];
        }
    }
    return res;
}

int main()
{

    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};

    cout << "The count of LIS is "
         << findNumberOfLIS(arr);

    return 0;
}