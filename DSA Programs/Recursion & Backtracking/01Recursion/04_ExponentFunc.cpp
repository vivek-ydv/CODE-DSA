#include <iostream>
using namespace std;

int exp(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return exp(m, n - 1) * m; // Recurrence relation
    }
}
// Optimised method
/*
(2)^8 = ((2)^2)^2 =(2*2)^2
(2)^9 = 2*((2)^2)^2 =2*((2*2)^2)
*/
int expop(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return expop(m * m, n / 2);
    }
    else
    {
        return m * expop(m * m, (n - 1) / 2);
    }
}
int main()
{
    int r = expop(2, 5);
    cout << r;
    return 0;
}