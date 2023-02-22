#include <bits/stdc++.h>
using namespace std;

// Function to find NSR index vector
vector<int> NSR(vector<int> arr)
{
    stack<pair<int, int>> st; // Stack to store a pair of integers
    vector<int> res;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            res.push_back(arr.size());
        }
        else
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.empty()) // if above loops break due to empty condition means that no smaller element found in right so push pseudo index
            {
                res.push_back(arr.size());
            }
            else
            {
                res.push_back(st.top().second); // Pushing the index of the NSR element
            }
        }
        st.push({arr[i], i}); // Pushing the element and its index into the stack
    }
    reverse(res.begin(), res.end());
    return res;
}

// Function to find NSL index vector
vector<int> NSL(vector<int> arr)
{
    stack<pair<int, int>> st; // Stack to store a pair of integers
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            res.push_back(-1);
        }
        else
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.empty()) // if above loops break due to empty condition means that no smaller element found in left so push pseudo index
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top().second); // Pushing the index of the NSL element
            }
        }
        st.push({arr[i], i}); // Pushing the element and its index into the stack
    }
    return res;
}

// aCTUAL lOGIC oF tHIS pROBLEM
int largestRectangleArea(vector<int> &heights)
{
    vector<int> right = NSR(heights); // Get the NSR indexes
    vector<int> left = NSL(heights);  // Get the NSL indexes

    vector<int> width; // Vector array to store widyh
    for (int i = 0; i < heights.size(); i++)
    {
        width.push_back(right[i] - left[i] - 1);
    }
    vector<int> area; // Vector array to store area
    for (int i = 0; i < heights.size(); i++)
    {
        area.push_back(heights[i] * width[i]);
    }

    int maxarea = *max_element(area.begin(), area.end());
    return maxarea;
}
int main()
{
    // vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    int res = largestRectangleArea(arr);
    cout << "MAH = " << res;
    return 0;
}