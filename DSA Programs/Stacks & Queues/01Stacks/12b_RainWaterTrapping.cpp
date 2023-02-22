#include <bits/stdc++.h>
using namespace std;

// Without any extra space : O(1)
int trapWater(vector<int> &height)
{
    int n = height.size();
    int res = 0;

    // Use two pointers to scan the entire array until they meet with each other
    int lo = 0;
    int hi = n - 1;

    // Maximum element on left and right
    int leftmax = 0;
    int rightmax = 0;

    while (lo <= hi)
    {
        leftmax = max(leftmax, height[lo]);
        rightmax = max(rightmax, height[hi]);

        // how much water is stored will depend on the shorter building
        if (leftmax < rightmax)
        {
            res += leftmax - height[lo];
            lo++;
        }
        else
        {
            res += rightmax - height[hi];
            hi--;
        }
    }
    return res;
}
int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {3, 0, 0, 2, 0, 4};
    vector<int> height = {2,0, 0, 1, 0, 3, 1, 0, 2, 2, 0, 5};

    cout << "Total water trapped is : " << trapWater(height) << " units.";
    return 0;
}