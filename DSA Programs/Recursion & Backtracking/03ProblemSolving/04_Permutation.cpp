#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
// Method : 1
vector<vector<int>> res;
void helper(vector<int> p, vector<int> up)
{
    if (p.size() == up.size())
    {
        res.push_back(p);
        return;
    }
    // For each call at each level of recursion we will start checking from first element,
    // then we will decide wheather to take it or ignore it'
    for (int i = 0; i < up.size(); i++)
    {
        if (count(p.begin(), p.end(), up[i])) // Return 0 if ele donot exist other wise it frequency
        {
            continue; // If element alrady present then ignore it
        }
        p.push_back(up[i]);
        helper(p, up);
        p.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> p;
    helper(p, nums);
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
