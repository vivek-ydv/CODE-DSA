#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Pointers

    int a = 3;
    int *p = &a;

    cout << "The address of a is " << &a << endl;
    cout << "The address of a is " << p << endl;
    cout << "The value at address of p is " << *p << endl;
    cout << endl;

    // Pointers to pointer[DOUBLE POINTER]

    int **c = &p; // Double pointer have capability to store the adress of another pointer

    cout << "The address of p is " << &p << endl;
    cout << "The address of p is " << c << endl;
    cout << "The value at address c is " << *c << endl;
    cout << "The value at address value_at(value_at(c)) is " << **c << endl;

    return 0;
}
