#include <bits/stdc++.h>
using namespace std;
int res = INT_MAX;

void backtrack(int idx, int sTime, vector<int> &buckets, vector<int> &tasks)
{
    // Base case
    if (idx == tasks.size())
    {
        int temp = buckets.size();
        res = min(res, temp);
        return;
    }
    // Pruning tha recursive call
    if (buckets.size() > res)
        return;

    // we have two cases :
    // case 1 , adding curr task not exceed session time then add to curr buck

    for (int i = 0; i < buckets.size(); i++)
    {
        if (buckets[i] + tasks[idx] <= sTime)
        {
            buckets[i] += tasks[idx];
            backtrack(idx + 1, sTime, buckets, tasks);
            buckets[i] -= tasks[idx];
        }
    }
    // case 2, adding curr task exceed the session time then create then increase the size of bucket and put it into that
    buckets.push_back(tasks[idx]);
    backtrack(idx + 1, sTime, buckets, tasks);
    buckets.pop_back();
}

int minSessions(vector<int> &tasks, int sessionTime)
{
    vector<int> buckets;
    sort(tasks.rbegin(), tasks.rend());  /***reverse sort the array***/
    backtrack(0, sessionTime, buckets, tasks);
    return res;
}
int main()
{

    return 0;
}