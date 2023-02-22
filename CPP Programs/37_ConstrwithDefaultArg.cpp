#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    Complex(int x, int y = 5) //-->Declearing default argument constructor
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
    Complex c1(2);
    c1.printnum();

    return 0;
}
