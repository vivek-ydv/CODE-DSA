#include <bits/stdc++.h>
using namespace std;
int fun(int i, int j, string &pattern, string &text)
{
    if (i >= pattern.size() && j >= text.size())
        return true;
    if (i >= pattern.size())
        return false;

    bool match_cur = (j < text.size()) && (pattern[i] == text[j] || pattern[i] == '.');

    // check for next char to be'*'
    if (i + 1 < pattern.size() && pattern[i + 1] == '*')
    {
        return (fun(i + 2, j, pattern, text) || (match_cur && fun(i, j + 1, pattern, text)));

        // Here we are taking "and(&&) with match_cur" because,
        // As we want to use '*' for matching of next character of text string only when,
        // curr char of text string matches with curr char of pattern string.
    }
    if (match_cur)
        return fun(i + 1, j + 1, pattern, text);
    else
        return false;
}
bool isMatch(string s, string p)
{

    // vector<vector<int>> dp(n,vector<int>(m,-1));
    return fun(0, 0, p, s);
}
int main()
{

    return 0;
}