#include <iostream>
using namespace std;

class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};
class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int b)
    {
        base2int = b;
    }
};
class Base3
{
protected:
    int base3int;

public:
    void set_base3int(int c)
    {
        base3int = c;
    }
};

class derived : public Base1, public Base2, public Base3
{
public:
    void show()
    {
        cout << "The value of base1 is:" << base1int << endl;
        cout << "The value of base2 is:" << base2int << endl;
        cout << "The value of base3 is:" << base3int << endl;
        cout << "The sum of these values is:" << (base1int + base2int + base3int) << endl;
    }
};
/*
The inherited derived class will look something like this:
Data members:
          base1int -->protected
          base2int -->protected
          base3int -->protected
Member functions: 
        set_base1int(int a)  -->Public
        set_base2int(int b)  -->Public
        set_base3int(int c ) -->Public
        show()               -->Public             
*/
int main()
{
    derived der;

    der.set_base1int(1);
    der.set_base2int(9);
    der.set_base3int(5);
    der.show();
    return 0;
}