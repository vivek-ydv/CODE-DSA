#include <bits/stdc++.h>
using namespace std;
// Consider a 3*3 matrix You have to move from points from (0,0) to (2,2).
// You can move only right and down.
// Problem : Print all the possible paths.
void printpath(string p, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << p << endl;
        return;
    }
    if (r > 1)
    {
        printpath(p + "D", r - 1, c);
    }
    if (c > 1)
    {
        printpath(p + "R", r, c - 1);
    }
}

int main()
{
    printpath("", 3, 3);
    return 0;
}