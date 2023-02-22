#include <iostream>
using namespace std;
class Employee
{
private:
    int Id;
    static int count; /*
                      If donot give it a static datatype then we can not count total number of object,
                      because if do not give a static data type then each object have its own initial value of count,
                      after giving a static data type all object will share a single value of count.
                      */
public:
    void setdata(void);
    void getdata(void);
    static void getcount(void); // Decleration of Static member function.
                                // It can acess Static data members only.
                                // It can run without making any object for the class.
};

int Employee ::count; // We have to define a static data member in this way outside the class.
                      // Count is a static data member of class Employee.
                      // Default value is zero.

void Employee ::setdata()
{
    cout << "Enter the id:" << endl;
    cin >> Id;
    count++;
}
void Employee ::getdata()
{
    cout << "The id of employee number " << count << " is " << Id << endl;
}
void Employee ::getcount()
{
    cout << "The value of count is " << count << endl;
    // cout << Id; // --> It will throw an error as this function have acess only static data members
}

int main()
{
    Employee vivek, harray, sonal;

    vivek.setdata();
    vivek.getdata();
    Employee::getcount(); // Runing it without making any object

    harray.setdata();
    harray.getdata();
    Employee::getcount(); // Runing it without making any object

    sonal.setdata();
    sonal.getdata();
    Employee::getcount(); // Runing it without making any object

    return 0;
}