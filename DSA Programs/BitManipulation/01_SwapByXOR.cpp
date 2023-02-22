#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the First number: ";
    cin >> a;
    cout << "Enter the Second number number: ";
    cin >> b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "Swapped number are : First number = " << a << " and Second number =  " << b;
    return 0;
}