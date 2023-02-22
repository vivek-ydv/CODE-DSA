#include <bits/stdc++.h>
using namespace std;
// Explanation in NoteBook
void lettercombination(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }

    int digit = int(up.at(0) - 48); // It will convert '1' into 1

    for (int i = (digit - 1) * 3; i < digit * 3; ++i)
    {
        char ch = char('a' + i);
        lettercombination(p + ch, up.substr(1));
    }
}
int main()
{
    string digits = "12";
    string p;
    lettercombination(p, digits);

    return 0;
}