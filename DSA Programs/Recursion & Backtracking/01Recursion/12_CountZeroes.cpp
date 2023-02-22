#include <iostream>
using namespace std;

int fun(int n, int c)
{
    if (n == 0)
    {
        return c;
    }
    if (n % 10 == 0) // It means it have 0 at unit place
    {
        c++; // increasing the counter
        return fun(n / 10, c);
    }
    else
    {
        return fun(n / 10, c);
    }
}

int main()
{
    // Problem is that we have a number and we have to count number of zeroes in it
    // Ex. 1200503, o/p = 3

    int num = 1200503;
    int count = 0;
    cout << fun(num, count);
    return 0;
}