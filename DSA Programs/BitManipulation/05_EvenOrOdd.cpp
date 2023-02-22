#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number:";
    cin >> num;
    /*
    Simple concept we will use that even number have 0 as first bit and odd number have the 1 as first bit
    8 - 1 0 0 0
    5 - 1 0 1
    and we will and(&) it with 1
    */

    if (num & 1 != 0)
    {
        cout << "Odd number";
    }
    else
    {
        cout << "Even number";
    }

    return 0;
}