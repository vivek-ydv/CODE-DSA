#include <iostream>
using namespace std;

void func(int a)
{
    cout << "I am First function" << endl;
}

template <class T>
void func(T a)
{
    cout << "I am Templatised function" << endl;
}

template <class T>
void func1(T a)
{
    cout << "I am Templatised function" << endl;
}

int main()
{
    func(4);  // Exact match will take highest priority
    func1(4); // Exact match will take highest priority

    return 0;
}
