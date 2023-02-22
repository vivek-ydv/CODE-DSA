#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int> &arr, int n)
{
    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && dp1[prev] + 1 > dp1[i])
            {
                dp1[i] = dp1[prev] + 1;
            }
        }
    }

    // Reverse the direction of nested loops
    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i] && dp2[prev] + 1 > dp2[i])
            {
                dp2[i] = dp2[prev] + 1;
            }
        }
    }

    // Calculate the max lenght of bitonic subsequence
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int main()
{

    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();

    cout << "The length of the longest bitonic subsequence is "
         << longestBitonicSequence(arr, n);

    return 0;
}