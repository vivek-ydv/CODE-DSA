#include <iostream>
using namespace std;

int main()
{
    int a = 13; // 13 = 1 1 0 1
    int pos = 3;

    int mask = ~(1 << (pos - 1));

    int res = a & mask;

    cout << res; // res = 9 = 1 0 0 1

    return 0;
}