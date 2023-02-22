#include <bits/stdc++.h>
using namespace std;
// Lexicographical order solution
vector<vector<int>> res;
void helper(vector<int> p, vector<int> up, int start)
{
    res.push_back(p);
    for (int i = start; i < up.size(); i++)
    {
        p.push_back(up[i]);
        helper(p, up, i + 1);
        p.pop_back();
    }
    return;
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> p;
    helper(p, nums, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 2};
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
