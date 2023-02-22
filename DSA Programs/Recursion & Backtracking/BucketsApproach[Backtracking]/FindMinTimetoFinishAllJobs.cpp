#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
void backtrack(int idx, int k, vector<int> &bucket, vector<int> &jobs)
{
    // Base case
    if (idx == jobs.size())
    {
        int maxi = *max_element(bucket.begin(), bucket.end());
        ans = min(ans, maxi);
        return;
    }
    for (int i = 0; i < k; i++)
    {
        // prune the recursion calls
        if (bucket[i] + jobs[idx] > ans || (i > 0 && bucket[i] == bucket[i - 1]))
            continue;

        bucket[i] += jobs[idx];
        backtrack(idx + 1, k, bucket, jobs);
        bucket[i] -= jobs[idx]; // backtrack
    }
}
int minimumTimeRequired(vector<int> &jobs, int k)
{
    vector<int> bucket(k, 0);
    sort(jobs.rbegin(), jobs.rend()); /**** reverse sort the array ****/
    backtrack(0, k, bucket, jobs);
    return ans;
}
int main()
{

    return 0;
}
