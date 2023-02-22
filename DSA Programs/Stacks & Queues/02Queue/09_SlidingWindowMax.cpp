#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> res;
    // Process the first window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back(); // remove the rear element
        }

        dq.push_back(i); // push the element index
    }
    // Store the answar
    res.push_back(nums[dq.front()]);

    // Process the remaining element
    for (int i = k; i < nums.size(); i++)
    {
        // Remove all the out of window elements
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back(); // remove the rear element
        }
        dq.push_back(i); // push the element index

        // Store the answar
        res.push_back(nums[dq.front()]);
    }
    return res;
}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(arr, k);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}