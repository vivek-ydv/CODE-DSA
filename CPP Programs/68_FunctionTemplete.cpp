/*
SYNTAX(Function Template):->
-----------------------------------------
templete<class T>
return_type function_name (arguments of type T)
{
   body of function of type T
   Where T can be char, int, float etc...
}; 
-----------------------------------------
*/

#include <iostream>
using namespace std;
template <class T>
void Swap(T &x, T &y) // Swapping by using c++ refrence variable
{
    T temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 2.6, b = 7;
    float c = 2.6, d = 6.7;
    char p = 'V', q = 'J';
    Swap(a, b);
    Swap(c, d);
    Swap(p, q);

    cout << "a: " << a << " b: " << b << endl
         << "c: " << c << " d: " << d << endl
         << "p: " << p << " q: " << q << endl;
    return 0;
}    