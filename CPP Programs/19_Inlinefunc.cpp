#include <iostream>
using namespace std;
inline int product(int a, int b) /* The inline function expands the whole function code at the point of a function call,instead of running the function,
                                    When one function is being called multiple times in the program it increases the execution time,
                                    Inline functions are considered to be used when the function is small otherwise it will not perform well.
                                 */
{
    return a * b;
}
int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter the two number" << endl;
    cin >> a >> b;
    cout << "The product of two number is " << product(a, b);
    return 0;
}
