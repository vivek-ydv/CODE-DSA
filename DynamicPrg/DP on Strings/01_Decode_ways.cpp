#include <bits/stdc++.h>
using namespace std;
// Recursive Approach
int fun(int i, string s)
{
    // Base case : when we are reached at end of the string-that is we have found a path to decode the string
    if (i >= s.size())
        return 1;

    // If Substring starts from '0' we can't decode it so simply return 0
    if (s[i] == '0')
        return 0;

    // There are two ways to decode the string either,
    // by taking the single character or by taking the 2 character at a time but for both we have to perform the some checks.
    // -> idx+1 < n , mean we are not going out of bounds.
    // -> s[idx] == '1' && s[idx+1] <= '9' , here range [10, 19] is covered
    // -> s[idx] == '2' && s[idx+1] < '7' , here range [20, 26] is covered

    int first, second = 0;

    // way 1: pick single
    if (s[i] != '0')
        first = fun(i + 1, s);

    // way 2: pick couple
    if (i + 1 < s.size() && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] < '7')))
    {
        second = fun(i + 2, s);
    }
    return first + second;
}

/*------------------------------------------------------------------------------------------------------------------------*/

// Explanation : https://www.youtube.com/watch?v=YcJTyrG3bZs
// Memoisation
int fun2(int i, string s, vector<int> &dp)
{
    // Base case : when we are reached at end of the string-that is we have found a path to decode the string
    if (i >= s.size())
        return 1;

    if (dp[i] != -1)
    {
        return dp[i];
    }

    // If Substring starts from '0' we can't decode it so simply return 0
    if (s[i] == '0')
        return 0;

    int first, second = 0;

    // way 1: pick single
    if (s[i] != '0')
        first = fun2(i + 1, s, dp);

    // way 2: pick couple
    if (i + 1 < s.size() && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] < '7')))
    {
        second = fun2(i + 2, s, dp);
    }
    return dp[i] = first + second;
}

// Driver Code
int numDecodings(string s)
{
    vector<int> dp(s.size(), -1);
    return fun2(0, s, dp);
}
int main()
{
    // string s = "11106";
    string s = "226";
    cout << numDecodings(s);
    return 0;
}