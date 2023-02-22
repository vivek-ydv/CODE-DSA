#include <bits/stdc++.h>
using namespace std;
// Space optimised approach : O(N)

int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = 0 + max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }
    return prev[m];
}
int main()
{
    string s1 = "acd";
    string s2 = "ced";

    cout << "The Length of Longest Common Subsequence is " << longestCommonSubsequence(s1, s2);
    return 0;
}