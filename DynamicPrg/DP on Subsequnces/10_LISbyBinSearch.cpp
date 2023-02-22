#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44

int longestIncreasingSubsequence(vector<int> arr)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // If LIS is disturbed then replace the element (which disturbs LIS) with the element just greater than it.
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    return len;
}

int main()
{

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(arr);

    return 0;
}