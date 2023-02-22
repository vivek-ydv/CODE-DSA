#include <bits/stdc++.h>
using namespace std;
bool backtrack(int idx, int target, vector<int> &bucket, vector<int> &matchstick)
{
    // Base case
    if (idx == matchstick.size())
    {

        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i] != target)
                return false;
        }
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        // prune the recursion calls
        if (bucket[i] + matchstick[idx] > target || (i > 0 && bucket[i] == bucket[i - 1]))
            continue;

        bucket[i] += matchstick[idx];
        if (backtrack(idx + 1, target, bucket, matchstick)) // once found, just return
            return true;
        bucket[i] -= matchstick[idx]; // backtrack
    }
    return false;
}

bool makesquare(vector<int> &matchsticks)
{
    // we can solve it using backtracking by seeing all possible combination
    // similer to problem : partition-to-k-equal-sum-subsets
    int k = 4; // as square have 4 sides

    int sum = 0;
    for (auto it : matchsticks)
        sum += it;
    if (sum % k != 0)
        return false;
    int target = sum / k;

    vector<int> bucket(k, 0);
    return backtrack(0, target, bucket, matchsticks);
}
int main()
{

    return 0;
}