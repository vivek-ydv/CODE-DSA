#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreaterToRight(vector<int> arr)
{
    stack<int> st;
    vector<int> res;
    for (int i = arr.size() - 1; i >= 0; i--) // Travesing from the right to left
    {
        // Check all the possible condition
        if (st.empty()) // If stack is already empty
        {
            res.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > arr[i])
        {
            res.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() <= arr[i])
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty()) // if above while loop is broken due to the empty conditon
            {
                res.push_back(-1);
            }
            else if (st.top() > arr[i]) // if above while loop is broken due to the conditon that top element is greater than arr[i] element
            {
                res.push_back(st.top());
            }
        }
        // After reaching to one of the result now push the arr[i] element into the stack
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    // vector<int> arr = {1, 3, 2, 4};
    vector<int> arr = {1, 3, 0, 0, 1, 2, 4};
    vector<int> v = NextGreaterToRight(arr);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}