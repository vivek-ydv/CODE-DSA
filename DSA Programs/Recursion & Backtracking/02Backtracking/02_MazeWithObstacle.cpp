#include <bits/stdc++.h>
using namespace std;
// Consider a 3*3 matrix You have to move from points from (0,0) to (2,20).
// You can move only right and down.
// There is obstacle at (1,1) so you can't pass that.
// Problem : Print all the possible paths.
// Suggestion : See notebook for clear understanding of problem.

void printpathrestriction(string p, int r, int c)
{
    if (r == 2 && c == 2)
    {
        cout << p << endl;
        return;
    }
    if (r == 1 && c == 1) // Obstacle found so just return
    {
        return;
    }

    if (r < 2)
    {
        printpathrestriction(p + "D", r + 1, c);
    }
    if (c < 2)
    {
        printpathrestriction(p + "R", r, c + 1);
    }
}

int main()
{
    printpathrestriction("", 0, 0);
    return 0;
}