#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    int cntA = 0, cntB = 0, cntC = 0;
    int l = 0, r = 0;
    int res = 0;
    int len = s.size() - 1;

    while (r < s.size())
    {
        if (s[r] == 'a')
            cntA++;
        else if (s[r] == 'b')
            cntB++;
        else if (s[r] == 'c')
            cntC++;

        while (cntA && cntB && cntC)
        {
            res += 1 + (len - r);
            // Above line means that : If are able to found the substring that contains 'a'&'b'&'c',
            // then substring formed by adding the remaining chracter of string, also satify the given conditon so we are including all those also i.e. 1 + (len - r)
            // After that simply shrink the window from left and again check for condition

            if (s[l] == 'a')
                cntA--;
            else if (s[l] == 'b')
                cntB--;
            else if (s[l] == 'c')
                cntC--;
            l++;
        }
        r++;
    }

    return res;
}
int main()
{
    // Return the number of substrings containing at least one occurrence of all these characters a,b and c
    string s = "abcabc";
    cout << numberOfSubstrings(s);
    return 0;
}