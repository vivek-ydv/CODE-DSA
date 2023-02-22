#include <iostream>
using namespace std;

void pattern(int r, int c)
{
    if (r == 0)
        return;
    if (c < r)
    {
        cout << "*";
        pattern(r, c + 1);
    }
    else
    {
        cout << endl;
        pattern(r - 1, 0);
    }
}

int main()
{
    pattern(4, 0); // r:4 & c:0
    return 0;
}