#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    //CONSTRUCTOR OVERLOADING
    Complex()
    {
        a = 0;
        b = 0;
    }
    Complex(int x)
    {
        a = x;
        b = 0;
    }
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    void printnum()
    {
        cout << "Your Complex number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{

    Complex c1;
    c1.printnum();

    Complex c2(5);
    c2.printnum();

    Complex c3(5, 10);
    c3.printnum();

    return 0;
}