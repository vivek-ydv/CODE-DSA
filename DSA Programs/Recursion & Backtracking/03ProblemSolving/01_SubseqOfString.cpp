#include <bits/stdc++.h>
using namespace std;
// Without using substring functotin
void subSeq(string p, string up, int i)
{
    if (i == up.length())
    {
        cout << "[" << p << "]";
        return;
    }
    subSeq(p + up[i], up, i + 1); // Taking current index element
    subSeq(p, up, i + 1);         // Ignoring current index element
}
int main()
{

    string p;          // p: processed string, initially empty
    string up = "abc"; // up: unprocessed string
    subSeq(p, up, 0);

    return 0;
}