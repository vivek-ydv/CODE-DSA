#include <bits/stdc++.h>
using namespace std;
vector<int> Search2d(vector<vector<int>> nums, int target)
{
    int row = 0;
    int col = nums.at(0).size() - 1;
    vector<int> res;

    while (row < nums.size() && col >= 0)
    {
        if (nums[row][col] == target)
        {
            res = {row, col};
            return res;
        }
        if (target < nums[row][col])
        {
            col--;
        }
        else // WARNING : DO NOT WRITE IF CONDITIONS AGAIN IF YOU HAVE MENTIONED LOOP BREAKING CONDITION ALREADY https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/
        {
            row++;
        }
    }

    return {-1, -1};
}
int main()
{

    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {28, 29, 37, 49},
                               {33, 34, 38, 50}};

    // vector<vector<int>> arr ={{1,1}};

    int target = 55;
    vector<int> targetindex = Search2d(arr, target);

    for (auto &&i : targetindex)
    {
        cout << i << " ";
    }

    return 0;
}