#include <iostream>
#include <math.h>
using namespace std;

int fun(int n, int c)
{
    if (n == 0)
    {
        return c;
    }
    if (n % 2 == 0)
    {
        n = n / 2;
        c++;
        return fun(n, c);
    }
    else
    {
        n = n - 1;
        c++;
        return fun(n, c);
    }
}

int numberOfSteps(int num)
{
    int count = 0;
    return fun(num, count);
}

int main()
{
  // Return the number of steps required to reduce a number to zero.
    cout << numberOfSteps(14);
}