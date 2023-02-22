#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getdata()
    {
        cout << "The real part is:" << real << endl;
        cout << "The imaginary part is:" << imaginary << endl;
    }
    void setdata(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};
int main()
{
    //  Complex c1;
    //  Complex *ptr = &c1;

    Complex *ptr = new Complex;

    //  (*ptr).setdata(1, 54); is exactely same as
    ptr->setdata(1, 54); // "->" is arrow operator

    // (*ptr).getdata();
    ptr->getdata();

    //We called member function with pointers by using arrow operator “->” instead of the dot operator “.” but still it will give the same results.

    return 0;
}