#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

void backtrack(int idx, int k, vector<int> &bucket, vector<int> &cookies)
{
    // Base case
    if (idx == cookies.size())
    {
        int maxi = *max_element(bucket.begin(), bucket.end());
        ans = min(ans, maxi);
        return;
    }
    for (int i = 0; i < k; i++)
    {
        // prune the recursion calls
        if (bucket[i] + cookies[idx] > ans || (i > 0 && bucket[i] == bucket[i - 1]))
            continue;

        bucket[i] += cookies[idx];
        backtrack(idx + 1, k, bucket, cookies);
        bucket[i] -= cookies[idx]; // backtrack
    }
}

int distributeCookies(vector<int> &cookies, int k)
{

    vector<int> bucket(k, 0);
    backtrack(0, k, bucket, cookies);
    return ans;
}
int main()
{

    return 0;
}