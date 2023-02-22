#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    int sum = 0;

    cout << "Input three numbers \n"; /* << is called INSERTION OPERATOR */

    cin >> a >> b >> c; // Takes three number as input  /* >> is called EXTRACTION OPERATOR */

    sum = a + b + c;

    cout << "sum is:" << sum; // Prints the value of sum
    return 0;
}
