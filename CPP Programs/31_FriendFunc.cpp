#include <iostream>
using namespace std;
class Complex
{
private:
    int a;
    int b;

public:
    void setnumber(int n1, int n2);
    void displaynum()
    {
        cout << "Your complex number is: " << a << " + " << b << "i" << endl;
    }

    friend Complex sumcomplex(Complex o1, Complex o2); /* It means that non member - sumcomplex function is,
                                                          allowed to do anything with private member*/
};

void Complex ::setnumber(int n1, int n2)
{
    a = n1;
    b = n2;
}

Complex sumcomplex(Complex o1, Complex o2) // Note:-> Friend function is not a member of class hence it can be decleared without scope resolution operator
                                           // **This function will take object as arguments and return object**
{
    Complex o3;
    o3.setnumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    Complex c1, c2, s;

    c1.setnumber(2, 4);
    c2.setnumber(6, 8);
    c1.displaynum();
    c2.displaynum();

    // s.sumcomplex(c1,c2);  -> Invalid (Read point number 2)
    s = sumcomplex(c1, c2);
    s.displaynum();
    return 0;
}

/* Properties of FRIEND function 

1. Not in the scope of class
2. Since it is not in the scope of the class, it cannot be called from the object of that class: c1.sumcomplex() == Invalid
3. Can be invoked(CALL) without the help of any object
4. Usually contains the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need (object_name.member_name) to access any member

*/