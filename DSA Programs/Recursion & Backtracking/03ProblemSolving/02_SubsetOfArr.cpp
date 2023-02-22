#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;

void helper(vector<int> p, vector<int> up, int i)
{
    if (i == up.size())
    {
        cout << "[";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
        }
        cout << "]";
        return;
    }
    p.push_back(up[i]); 
    helper(p, up, i + 1); // Picking the current element index
    p.pop_back();         // backtrack : what if we had not picked that element
    helper(p, up, i + 1); // Not picking the current index element
}
void subsets(vector<int> &nums)
{
    vector<int> p;
    helper(p, nums, 0);
    return;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    subsets(nums);
    return 0;
}