#include <iostream>
using namespace std;
// Consider a 3*3 matrix You have to move from points from (0,0) to (2,2).
// You can move only right and down.
// Problem : Count the total number of paths.

int paths = 0;
void count(int r, int c)
{
    if (r == 1 || c == 1)
    {
        paths++;
        return;
    }
    count(r - 1, c);
    count(r, c - 1);
}
int main()
{
    count(3, 3);
    cout << paths;
    return 0;
}
