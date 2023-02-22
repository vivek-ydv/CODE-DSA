#include <iostream>
using namespace std;
class Test
{
    int a;

public:
    void setdata(float a)
    {
        // (*this).a = a;
        this->a = a; // "this" is a keyword, which is a pointer which points to the object which invokes the member function
    }
    void getdata()
    {
        cout << "The value of a is : " << a;
    }
};
int main()
{
    Test A;
    A.setdata(5);
    A.getdata();
    return 0;
}