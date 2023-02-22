#include <iostream>
using namespace std;

class Employee
{
    // If we donot specify type of members then by default it is "private"
private:
    int a, b, c; // Only function inside this class can acess the data.
public:
    int d, e;

    void setdata(int a1, int b1, int c1); // Decleration  of function.
    void getdata()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};

void Employee ::setdata(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee vivek;
    vivek.setdata(1, 2, 4); // These value will be privately assigned to thir respective automatically i.e. a1=1,a2=4,a3=6.
    vivek.d = 6;
    vivek.e = 8;
    // vivek.a=7; // It will throw an error as it is a private type data.
    vivek.getdata();
    return 0;
}