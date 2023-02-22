#include <iostream>
using namespace std;
class Base
{
protected:
    int a; // Same as private but it can be inherited

private:
    int b;

public:
    int get_a();
};
int Base::get_a()
{
    a = 15;
    return a;
}
/*                     Public_derivation   Private_derivation   Protected_derivation
1.Private   Members :    Not Inherited       Not Inherited        Not Inherited
2.Protected Members :    Protected           Private              Protected
3.Public    Members :    Public              private              Protected

*/
class derived : protected Base
{
};
int main()
{
    Base b;
    derived d;

    // cout<<d.a; //--> Will not work since a is protected in both base and derived class
    return 0;
}