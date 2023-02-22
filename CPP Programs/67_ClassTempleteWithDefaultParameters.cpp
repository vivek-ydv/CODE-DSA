#include <iostream>
using namespace std;

template <class T1 = int, class T2 = float, class T3 = char>
class Vivek
{
    T1 a;
    T2 b;
    T3 c;

public:
    Vivek(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        c = z;
    }
    void display()
    {
        cout << "The value of a is:" << a << endl;
        cout << "The value of b is:" << b << endl;
        cout << "The value of c is:" << c << endl;
        cout << endl;
    }
};
int main()
{
    Vivek<> v1(19, 2.7, 'J'); // Template will be executed default data types
    v1.display();

    Vivek<char, int, float> v2('V', 27, 1.9); // Template will be executed according to user given data types
    v2.display();

    return 0; 
}