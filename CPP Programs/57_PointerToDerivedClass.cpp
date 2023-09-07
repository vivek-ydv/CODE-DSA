#include <iostream>
using namespace std;

class BaseClass
{
public:
    int var_base;
    void display()
    {
        cout << "Executing base class display function:" << endl;
        cout << "Displaying base class variable var_base " << var_base << endl;
        cout << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display()
    {
        cout << "Executing derived class display function:" << endl;
        cout << "Displaying base class variable var_base " << var_base << endl;
        cout << "Displaying derived class variable var_derived " << var_derived << endl;
        cout << endl;
    }
};

int main()

{
    BaseClass *Base_class_pointer;
    DerivedClass *derived_class_pointer;
    
    BaseClass obj_base;
    DerivedClass obj_derived;

    Base_class_pointer = &obj_derived; // Pointing base class pointer to derived class
    Base_class_pointer->var_base = 27;
    Base_class_pointer->display();

    // Just to demonstrate 
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 23;
    derived_class_pointer->var_derived = 19;
    derived_class_pointer->display();

    return 0;
}