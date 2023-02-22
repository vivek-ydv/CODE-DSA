#include <iostream>
using namespace std;

int main()
{
    int num, pos, mask; 
    cout << "Enter a number";
    cin >> num;
    cout << "Enter the position where you want to check the value of bit";
    cin >> pos;
    mask = 1 << (pos - 1); 
    int res = num & mask;
    if (res != 0)
    {
        cout << "Value of bit is one";
    }
    else
    {
        cout << "Value of bit is zero";
    }

    return 0;
}