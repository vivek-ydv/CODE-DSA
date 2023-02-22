#include <iostream>
using namespace std;
class Employee
{
private:
    int id;
    int salery;

public:
    void set_id()
    {
        cout << "Enter your id: ";
        cin >> id;
    }
    void get_id()
    {
        salery = 100000;
        cout << "The id of employee is " << id << " have salery " << salery << endl;
    }
};
int main()
{
    Employee fb[5]; // Array of object
                    // NOTE: It(Employee) is a new data type we had created by using class, taking the location in memory like an array
    for (int i = 0; i < 5; i++)
    {
        fb[i].set_id();
        fb[i].get_id();
    }

    return 0;
}