#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
// Method : 2 By Swapping the element
vector<vector<int>> res;
void helper(vector<int> up, int start)
{
    if (start == up.size())
    {
        res.push_back(up);
        return;
    }
    for (int i = start; i < up.size(); i++)
    {
        swap(up[start], up[i]);
        helper(up, start + 1); // Why it's not :i + 1, explained in notebook clearly.
                               // i.e. if draw the tree diagram of the problem then it's clear that each level start value is same,
                               // hence new value of start for recursion call will depend only on its prevoius value of start.
        swap(up[start], up[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    helper(nums, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j];

        cout << "]";
    }
    return 0;
}
