#include <iostream>
using namespace std;
class Data
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int terms;
    Data *poly;

public:
    Polynomial(int n)
    {
        this->terms = n;
        poly = new Data[terms];
    }
    void setdata()
    {
        for (int i = 0; i < terms; i++)
        {
            cout << "Enter the Coefficient and Exponent for " << i + 1 << " term :" << endl;
            cin >> poly[i].coeff >> poly[i].exp;
        }
    }
    void display()
    {
        for (int i = 0; i < terms; i++)
        {
            cout << poly[i].coeff << "x^" << poly[i].exp << " + ";
        }
    }
};
int main()
{
    Polynomial p1(5);
    p1.setdata();
    p1.display();
    return 0;
}