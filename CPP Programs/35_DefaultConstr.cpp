#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    Complex(void); //Default Constructor decleration
    void printnum()
    {
        cout << "Your Complex number is " << a << " + " << b << "i" << endl;
    }
};
Complex::Complex(void) //---> It is a default constructor as it do not accept any parameters
{
    a = 0;
    b = 0;
}
int main()
{
    Complex c1;
    c1.printnum();
    return 0;
}
