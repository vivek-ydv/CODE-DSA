#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // Push all the peoples in stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Pop two elements and compare them
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (M[a][b] == 1)
        {
            // if above condition is true means 'a' is not a celebrity definitely
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    // One element remained is a potential candidate for the celebrity, therfore check all satisfying conditions for the celebrity
    int res = st.top();

    // All elements in row must be zero as celebrity knows no one
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[res][i] == 0)
        {
            zerocount++;
        }
    }
    if (zerocount != n)
    {
        return -1;
    }

    // All elements in col must be one except the diagonal
    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][res] == 1)
        {
            onecount++;
        }
    }
    if (onecount != n - 1)
    {
        return -1;
    }

    return res;
}

// Drivers code
int main()
{
    // int n = 3;
    // vector<vector<int>> M = {{0, 1, 0},
    //                          {0, 0, 0},
    //                          {0, 1, 0}};

    int n = 4;
    vector<vector<int>> M = {{0, 0, 1, 0},
                             {0, 0, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 1, 0}};
    cout << "The celebrity person is : " << celebrity(M, n);
    return 0;
}