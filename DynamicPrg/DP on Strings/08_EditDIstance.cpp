#include <bits/stdc++.h>
using namespace std;

// Memoisation approach
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    // base case
    if (i < 0)
    {
        return j + 1; // insert j + 1 characters to convert s1 to s2
    }
    if (j < 0)
    {
        return i + 1; // delete i + 1 characters to convert s1 to s2
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    // if matches
    if (s1[i] == s2[j])
    { 
        return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2, dp);
    }
    else
    {
        return dp[i][j] = 1 + min(f(i, j - 1, s1, s2, dp),
                                  min(f(i - 1, j, s1, s2, dp), f(i - 1, j - 1, s1, s2, dp)));
        // min of all three possible operations : insert,delete,replace
    }
}
int editDistance(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, S1, S2, dp);
}

int main()
{

    string s1 = "horse";
    string s2 = "ros";

    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
}
