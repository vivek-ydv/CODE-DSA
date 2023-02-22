#include <iostream>
using namespace std;
/*
Case1:
class B: public A
{
    Order of execution of constructor--> first A() then B()
    Reason: If both base and derived classes have constructors, base class constructor is executed first
};

Case2:
Class A: public B, public C
{
    Order of execution of contructor --> first B() then C() and A()
    Reason: In multiple inheritances, base classes are constructer are executed in the order in which they appear in the class deceleration
};
Case3:
Class A: public B, virtual public C
{
    Order of execution of contructor --> first C() then B() and A()
    Reason:The constructors for virtual base classes are invoked before a non-virtual base class, If there are multiple virtual base classes, they are invoked in the order declared
};
*/

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }
    void printdataBase1()
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};
class Base2
{
    int data2;

public:
    Base2(int j)
    {
        data2 = j;
        cout << "Base2 class constructor called" << endl;
    }
    void printdataBase2()
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};
class Derived : public Base2, public Base1
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b) // Special syntax for passing arguments to multiple base classes funcntion/constructor
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printdataDerived()
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};
int main()
{
    Derived der(1, 2, 3, 4);
    der.printdataBase1();
    der.printdataBase2();
    der.printdataDerived();
    return 0;
}