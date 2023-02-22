#include <iostream>
using namespace std;
/*
SYNTAX FOR INITIALISATION LIST IN CONSTRUCTOR:

constructor(argument-list) : initialistion-section
{
    assignment + other-code
}
*/

class Test
{
    int a;
    int b;

public:
    // Test(int i, int j) : a(i), b(j)
    // Test(int i, int j) : a(i), b(i + j)
    // Test(int i, int j) : a(i), b(a + j)
    // Test(int i, int j) : b(j), a(i + b) //--> This will be create problem becauase 'a' will be initilised first as we had decleared it first.
    Test(int i, int j) : a(i)
    {
        b = j;
        cout << "Constructor Executed" << endl;
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
    }
};

int main()

{
    Test t(4, 6);

    return 0;
}
