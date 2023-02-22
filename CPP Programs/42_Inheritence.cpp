#include <iostream>
using namespace std;

// Base class
class Employee
{
public:
    int id;
    float salery = 25;

    Employee(int inpid)
    {
        id = inpid;
    }
    Employee() {} // Default constructor
};

// Derived class syntax
/*
class derived_class_name : visibility_mode base_class_name
{
  body of subclass
};
NOTES:
1. Default visibility mode: Private.
2. Private visibility mode: Public members of Base class becomes Private member of derived class.
3. Public  visibility mode: Public members of Base class becomes Public  member of derived class.
4. Private members are never inherited.
*/

// Creating a Programmer class derived from the Employee Base class

class Programmer : public Employee
{
public:
    int languagecode;
    Programmer(int inpid)
    {
        id = inpid;
        languagecode = 9;
    }
};

main()
{
    Employee vivek(1), harry(2);
    cout << vivek.id << endl;
    cout << vivek.salery << endl;

    Programmer skillF(3);
    cout << skillF.id << endl;
    cout << skillF.salery << endl;

    cout << skillF.languagecode << endl;

    return 0;
}