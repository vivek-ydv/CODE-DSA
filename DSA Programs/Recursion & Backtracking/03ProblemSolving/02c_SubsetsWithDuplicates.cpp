#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void helper(vector<int> p, vector<int> up, int start)
{
    res.push_back(p);
    for (int i = start; i < up.size(); i++)
    {
        if (i > start && up[i] == up[i - 1])
        {
            // If duplicated element then skip that element
            // i > start : means that it is not the first time when we are taking that element
            continue;
        }
        p.push_back(up[i]);
        helper(p, up, i + 1);
        p.pop_back();
    }
    return;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> p;
    sort(nums.begin(), nums.end()); // Sort the elements so that duplicates comes together
    helper(p, nums, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 2, 3};
    vector<vector<int>> res = subsets(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j];

        cout << "]";
    }
    return 0;
}
