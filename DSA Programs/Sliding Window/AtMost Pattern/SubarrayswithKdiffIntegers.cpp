#include <bits/stdc++.h>
using namespace std;
int atMostKdistinct(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    unordered_map<int, int> mp;
    int res = 0;
    while (r < nums.size())
    {
        mp[nums[r]]++; // add current element in map
        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]); // decrease the size of map
            l++;                   // increase the left pointer
        }
        res += r - l + 1; // store result for curr val of k
        r++;              // increase the right pointer
    }
    return res;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    // exactly(K) = atMost(K) - atMost(K-1)
    return atMostKdistinct(nums, k) - atMostKdistinct(nums, k - 1);
}
int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k);
    return 0;
}

/*
Quick explanation of j - i + 1 or r - l + 1 :

For a given array [i, j]: (length is j - i + 1),
the count of all the subarray which ends at j == the length (j - i + 1)

For example, [1,2,1,2,3] with K = 2
let us list all the valid subarrays with at most K numbers which ends with each number start from beginning to end of the array
and count them:

Valid subarrays ends at index 0 (j = 0, i = 0):
[1] (how many? 1 which equals to the length == j - i + 1);
Valid subarrays ends at index 1 (j = 1, i = 0):
[2] , [1, 2] (how many? 2 which is the length == j - i + 1);
Valid subarrays ends at index 2, (j = 2, i = 0):
[1] , [2, 1], [1, 2, 1] (how many? 3 which is the length == j - i + 1);
Valid subarrays ends at index 3 (j = 3, i = 0):
[2] , [1, 2], [2, 1, 2], [1, 2, 1, 2] (how many? 4 which is the length == j - i + 1);
Valid subarrays ends at index 4 (j = 4, i = 3):
[3], [2, 3] ( how many? 2 which is the length == j - i + 1, i has been moved to index 3 to match K == 2)

Valid subarrays ends with each number in the array:

Arr[] =[1,       2,          1,           2,       3]
       [1]      [2]         [1]          [2]      [3]
              [1,2]       [2,1]        [1,2]    [2,3]
                        [1,2,1]      [2,1,2]
                                   [1,2,1,2]
*/