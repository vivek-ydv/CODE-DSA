#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> p, vector<int> up, int target, int start)
{
    if (target == 0)
    {
        for (int j = 0; j < p.size(); j++)
        {
            cout << p[j] << " ";
        }
        cout << endl;
        return;
    }
    if (target < 0)
    {
        return;
    }
    for (int i = start; i < up.size(); i++)
    {
        if (i > start && up[i] == up[i - 1]) // i > start : means that it is not the first time when we are taking that element.
            continue;                        // skip duplicates
        if (up[i] > target)
            break; // Means if at a particular position it is greater then not possible for next ones also as array is sorted already.
        p.push_back(up[i]);
        helper(p, up, target - up[i], i + 1); // i+1 because we can not use the same element again.
        p.pop_back();                         // Backtracking : revert the change
    }
}
void combinationSum2(vector<int> &candidates, int target)
{
    vector<int> p;
    sort(candidates.begin(), candidates.end());
    helper(p, candidates, target, 0);
    return;
}
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    // vector<int> candidates = {2, 5, 2, 1, 2};
    int t = 8;
    combinationSum2(candidates, t);
    return 0;
}