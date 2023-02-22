#include <iostream>
using namespace std;

class BankDeposit
{
private:
    int principal;
    float intrestrate;
    int years;
    float returnvalue = 0;

public:
    BankDeposit() {} /*We must have to define a default constructor if we are declaring all object first.
                       Reason:--> Even we decleare arguments or not, default constructor is invoked,
                                  it creates a blank object when program is executed and after that we can overwrite the blank objects.
                      */
    BankDeposit(int p, int y, int r)
    {
        principal = p;
        years = y;
        intrestrate = (float(r)) / 100;
        returnvalue = principal;

        for (int i = 0; i < years; i++)
        {
            returnvalue = returnvalue * (1 + intrestrate);
        }
    }
    BankDeposit(int p, int y, float r)
    {
        principal = p;
        years = y;
        intrestrate = r;
        returnvalue = principal;
        for (int i = 0; i < years; i++)
        {
            returnvalue = returnvalue * (1 + intrestrate);
        }
    }
    void show()
    {
        cout << "The Principal amount " << principal << " after " << years << " years have return value " << returnvalue << endl;
    }
};
int main()
{
    BankDeposit b1, b2, b3;

    int p;
    int r;
    int y;
    float R;

    cout << "Enter the value of p,r and y:" << endl;
    cin >> p >> r >> y;
    b1 = BankDeposit(p, y, r); // EXPLICIT CALLING METHOD
    b1.show();

    cout << "Enter the value of p,R and y:" << endl;
    cin >> p >> R >> y;
    b2 = BankDeposit(p, y, R);
    b2.show();
    return 0;
}