#include <bits/stdc++.h>
using namespace std;

vector<int> SSPAN(vector<int> price)
{
    stack<pair<int, int>> st; // Dceleration of stack that stores a pair of integer type
    vector<int> span;         // Vector to store the result

    for (int i = 0; i < price.size(); i++)
    {
        if (st.empty())
        {
            span.push_back(1);
        }
        else
        {
            while (!st.empty() && st.top().first <= price[i])
            {
                st.pop();
            }
            if (st.empty()) // If above loop breaks due to becuse stack gets empty, it means all the elememts preceeding it are smaller
            {
                span.push_back(i + 1);
            }
            else
            {
                span.push_back(i - st.top().second); // difference of current index and NGL index
            }
        }
        st.push({price[i], i}); // Pushing the element and its index into the stack
    }
    return span;
}
int main()
{
    // vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> price = {100, 80, 60, 70, 55, 57, 60, 75, 85};
    // vector<int> price = {10, 4, 5, 90, 120, 80};
    vector<int> v = SSPAN(price);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}