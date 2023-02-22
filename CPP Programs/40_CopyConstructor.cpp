#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number() { a = 0; } // Default constructor
    Number(int n)
    {
        a = n;
    }

    /********* When no copy constructor is found then compiler supplies its own constructor *********/
    Number(Number &obj) // copy constructor
    {
        cout << "Copy constructor called! And ";
        a = obj.a;
    }

    void display()
    {
        cout << "The number is " << a << endl;
    }
};
int main()
{
    Number x, y(7), z(5);

    x.display();
    y.display();
    z.display();

    // CREATING A COPY CONSTRUCTOR(z1)--> z1 must resemble with z
    Number z1(z); // copy constructor invoked
    z1.display();

    // When user defined copy constructor will invoke and when not-->
    Number z2;
    z2 = z; // copy constructor did not invoked
    z2.display();

    Number z3 = z; // copy constructor invoked
    z3.display();
    return 0;
}