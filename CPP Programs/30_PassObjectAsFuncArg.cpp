#include <iostream>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    void setdata(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    void setdatabySum(Complex o1, Complex o2) // Complex object o1 and o2 as a function argument(formal)
                                              // Complex:-> A new data type that we created using class
                                              // Formal and actual arg must be of same data type(same class)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b; // Note-> As a & b are private but inside the class they are acessible directly
    }
    void printnum()
    {
        cout << "Your Complex number is " << a << "+" << b << "i" << endl;
    }
};
int main()
{
    Complex c1, c2, c3;

    c1.setdata(1, 2);
    c1.printnum();
 
    c2.setdata(3, 4);
    c2.printnum();

    c3.setdatabySum(c1, c2); //Complex object c1,c2 as a function argument(actual)
    c3.printnum();
    return 0;
}