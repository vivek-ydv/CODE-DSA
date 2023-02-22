#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    Complex(int, int); //Parametrized Constructor decleration
    void printnum()
    {
        cout << "Your Complex number is " << a << " + " << b << "i" << endl;
    }
};
Complex::Complex(int x, int y) //---> It is a parametrized constructor as it accept parameters
{
    a = x;
    b = y;
};
int main()
{

    // IMPLICIT CALL
    Complex c1(4, 5);

    // EXPLICIT CALL
    Complex c2 = Complex(6, 7);

    c1.printnum();
    c2.printnum();

    return 0;
}
