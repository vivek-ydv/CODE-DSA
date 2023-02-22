#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    // We can redefine the problem as the maxmimum window size that contains at most k zeroes
    int l = 0, r = 0;
    int zeroc = 0;
    int res = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
            zeroc++;

        while (zeroc > k) // condition voilated
        {
            res = max(res, r - l);
            if (nums[l] == 0)
                zeroc--;
            l++;
        }
        r++;
    }

    if (zeroc <= k) // for such edge cases [1,1,1,0,0,0,1,1,1,1] & k = 0
        res = max(res, r - l);

    return res;
}
int main()
{
    // return the maximum number of consecutive 1's in the array if you can flip at most k 0's
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << longestOnes(nums, k);
    return 0;
}