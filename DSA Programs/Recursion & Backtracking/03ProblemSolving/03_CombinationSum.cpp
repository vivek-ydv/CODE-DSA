#include <bits/stdc++.h>
using namespace std;
// Concept is similer to to subset problem Concept
// Just now we have a target and we have to find all the combination in according to the target value
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
        p.push_back(up[i]);
        helper(p, up, target - up[i], i); // not i+1 because we can use the same element again and again
        p.pop_back();                     // Backtracking : revert the change
    }
}
void combinationSum(vector<int> &candidates, int target)
{
    vector<int> p;
    helper(p, candidates, target, 0);

    return;
}
int main()
{
    vector<int> candidates = {1, 2, 5};
    int t = 5;
    combinationSum(candidates, t);
    return 0;
}