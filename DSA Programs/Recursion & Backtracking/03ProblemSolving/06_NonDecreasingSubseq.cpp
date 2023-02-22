#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void helper(int start, vector<int> &v, vector<int> &nums)
    {
        if (start == nums.size())
            return;

        unordered_set<int> hash; // since we want to avoid the duplicate vectors at current level
        for (int i = start; i < nums.size(); i++)
        {
            if (hash.count(nums[i]) || v.size() && nums[i] < v[v.size() - 1])
                continue;

            hash.insert(nums[i]); //******insert into hash******
            v.push_back(nums[i]);

            if (v.size() > 1)
                res.push_back(v);
            helper(i + 1, v, nums);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> v;
        helper(0, v, nums);
        return res;
    }
};
int main()
{

    return 0;
}