#include <iostream>
#include <cmath>
using namespace std;
class Simplecalculator
{
    int a, b;

public:
    void getdataSimple()
    {
        cout << "Enter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
    }
    void performOperationSimple()
    {
        cout << "The value of a + b is: " << a + b << endl;
        cout << "The value of a - b is: " << a - b << endl;
        cout << "The value of a * b is: " << a * b << endl;
        cout << "The value of a / b is: " << a / b << endl;
    }
};
class Scientificcalculator
{
    int a, b;

public:
    void getdataScientific()
    {
        cout << "Enter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
    }
    void performOperationScientific()
    {
        cout << "The value of sin(a) is: " << sin(a) << endl;
        cout << "The value of cos(a) is: " << cos(a) << endl;
        cout << "The value of tan(a) is: " << tan(a) << endl;
        cout << "The value of sin(b) is: " << sin(b) << endl;
        cout << "The value of cos(b) is: " << cos(b) << endl;
        cout << "The value of tan(b) is: " << tan(b) << endl;
        cout << "The value of exp(b) is: " << exp(b) << endl;
    }
};
class Hybridcalculator : public Simplecalculator, public Scientificcalculator
{
};

int main()
{
    Hybridcalculator calci;
    calci.getdataScientific();
    calci.performOperationScientific();
    calci.getdataSimple();
    calci.performOperationSimple();
    return 0;
}