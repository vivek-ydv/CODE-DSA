#include <iostream>
using namespace std;

class Complex; // FORWARD DECLERATION
class Calculate
{
public:
    int realcomplexSum(Complex, Complex); // We will only decleare the function here as we had forward decleared the class complex only,
    int imagcomplexSum(Complex, Complex); // Compiler donot know about the its object, hence it will throw an error.
};
class Complex
{
private:
    int a;
    int b;

public:
    void setnum(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    // Individually declearing function as friends
    /*
    friend int Calculate::realcomplexSum(Complex o1, Complex o2);
    friend int Calculate::imagcomplexSum(Complex o1, Complex o2);
    */

    // Declearing entire Calculte class as friend

    friend class Calculate;
};

int Calculate::realcomplexSum(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}
int Calculate::imagcomplexSum(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main(int argc, char const *argv[])
{
    Complex c1, c2;
    c1.setnum(2, 3);
    c2.setnum(4, 6);

    Calculate calc;
    int resreal = calc.realcomplexSum(c1, c2);
    cout << "The sum of real part is " << resreal << endl;

    int resimag = calc.imagcomplexSum(c1, c2);
    cout << "The sum of imag part is " << resimag << endl;

    return 0;
}
