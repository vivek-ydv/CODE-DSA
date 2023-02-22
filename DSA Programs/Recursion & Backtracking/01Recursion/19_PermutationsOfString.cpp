#include <bits/stdc++.h>
using namespace std;

void permutation(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }

    for (int i = 0; i <= p.length(); i++)
    {
        string l = p.substr(0, i);
        char ch = up.at(0);
        string r = p.substr(i, p.length());
        permutation(l + ch + r, up.substr(1));
    }
}

int main()
{
    string up = "abc";
    string p;
    permutation(p, up);

    return 0;
}