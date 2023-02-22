#include <iostream>
using namespace std;

class BaseClass
{
public:
    int var_base = 27;
    virtual void display() // Declearing Virtual function
    {
        cout << "Executing base class display function:" << endl;
        cout << "Displaying base class variable var_base " << var_base << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived = 19;
    void display()
    {
        cout << "Executing derived class display function:" << endl;
        cout << "Displaying base class variable var_base " << var_base << endl;
        cout << "Displaying derived class variable var_derived " << var_derived << endl;
    }
};

int main(int argc, char const *argv[])
{

    BaseClass *Base_class_pointer;
    DerivedClass *Derived_class_pointer;

    BaseClass obj_base;
    DerivedClass obj_derived;

    Base_class_pointer = &obj_derived;
    Base_class_pointer->display();

    // Derived_class_pointer = &obj_base; // Not possible, it will throw an error ,Reason : https://stackoverflow.com/questions/4937180/a-base-class-pointer-can-point-to-a-derived-class-object-why-is-the-vice-versa/4937234
    return 0;
}


/*
Rules for Virtual Functions:
1.They cannot be static.
2.They are accessed by object pointers.
3.Virtual functions can be a friend of another class.
4.A virtual function in the base class might not be used.
5.If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class.
*/