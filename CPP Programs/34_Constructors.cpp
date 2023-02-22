#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;

public:
    // Creating a constructor.
    // Constructor is a special member of class with same name as of the class with no return types.
    // It is used to initialise the object of the class.
    // It is automatically Invoked whenever a object is created.

    Complex(void); // Constructor decleration
    void printnum()
    {
        cout << "Your Complex number is " << a << " + " << b << "i" << endl;
    }
};
Complex::Complex(void)
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

/* Proprties of construtor 

1. It must be declered in the public section of the class.
2. They are invoked automatically  whenever object is created.
3. They can't return values as they do not have a return type(Not even void).
4. It can have default arguments.
5. We can't refer to their adress.  

*/
