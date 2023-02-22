#include <iostream>

using namespace std;
int c = 27;

int main(int argc, char const *argv[])
{
    int a, b, c;
    cout << "Enter the value of a & b" << endl;
    cin >> a >> b;
    c = a + b;
    cout << "The value of c is " << c << endl;
    cout << "The value of global c without using scoperslopr is " << c << endl;
    cout << "The value of global c after using scoperslopr is " << ::c; // :: is known as Scope Resolution Operator

    return 0;
}
