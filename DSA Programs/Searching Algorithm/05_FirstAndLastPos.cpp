#include <bits/stdc++.h>
using namespace std;
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
int binSearch(vector<int> &vec, int target, bool issearchforfirst)
{
    int start = 0;
    int end = vec.size() - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid] == target)
        {
            if (issearchforfirst)
            {
                ans = mid; // One of the potential answar for first index
                end = ans - 1;
            }
            else
            {
                ans = mid; // One of the potential answar for last index
                start = ans + 1;
            }
        }

        if (vec[mid] < target)
            start = mid + 1;
            
        if (vec[mid] > target)
            end = mid - 1;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res;
    int first = binSearch(nums, target, true);
    int second = binSearch(nums, target, false);

    res.push_back(first);
    res.push_back(second);
    return res;
}

int main()
{
    vector<int> vec = {5, 7, 7, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(vec, 7);

    for (auto &&i : res)
    {
        cout << i << " ";
    }

    return 0;
}