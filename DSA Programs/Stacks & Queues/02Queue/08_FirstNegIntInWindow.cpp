#include <bits/stdc++.h>
using namespace std;

// N: Number of Elements
// K: Window size
vector<int> printFirstNegativeInteger(int A[], int N, int K)
{
    deque<int> dq;
    vector<int> res;

    // Process the first window]
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i); // Store the index
        }
    }

    // Store the answar
    if (dq.empty())
    {
        res.push_back(0);
    }
    else
    {
        res.push_back(A[dq.front()]);
    }

    // Process the remaining element
    for (int i = K; i < N; i++)
    {
        // Remove all the out of window elements
        if (!dq.empty() && dq.front() == i - K)
        {
            dq.pop_front();
        }
        // Push the element index if it is negative
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // Store the answar
        if (dq.empty())
        {
            res.push_back(0);
        }
        else
        {
            res.push_back(A[dq.front()]);
        }
    }
    return res;
}
int main()
{
    // int N = 5;
    // int K = 2;
    // int Arr[N] = {-8, 2, 3, -6, 10};
    int N = 8;
    int K = 3;
    int Arr[N] = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int> res = printFirstNegativeInteger(Arr, N, K);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}