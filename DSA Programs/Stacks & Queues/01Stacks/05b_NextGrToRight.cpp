#include <bits/stdc++.h>
using namespace std;

// If given array is circular!
// Note : Here we will not check the empty condition as array is circular hence we can not predict that a greater element will exist or not,
// till we had not traversed the whole array in circular manner for that element,
// For this, we will initilise the vector array of same size with value -1, if we found a result then we will override it else it will be -1.

vector<int> NextGreaterToRight(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> res(n, -1);
    for (int i = 2 * arr.size() - 1; i >= 0; i--)
    {
        // In this first we are poping all elements first
        if (st.size() > 0 && st.top() <= arr[i % n])
        {
            while (!st.empty() && st.top() <= arr[i % n])
            {
                st.pop();
            }
        }
        // After poping all the smaller values if below condition satisfies then store it in res vector array
        if (st.size() > 0 && st.top() > arr[i % n])
        {
            res[i % n] = st.top();
        }
        // Push the arr[i] element into the stack
        st.push(arr[i % n]);
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> v = NextGreaterToRight(arr);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}