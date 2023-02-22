#include <iostream>
using namespace std;

int fact(int num)
{
    if (num == 1 || num == 0) // Base condition
    {
        return (1);
    }
    else
    {
        return ((num)*fact(num - 1));
    }
}

// Step by step calculation of factorial(4)
// factorial(4) = 4 * factorial(3);
// factorial(4) = 4 * 3 * factorial(2);
// factorial(4) = 4 * 3 * 2 * factorial(1);
// factorial(4) = 4 * 3 * 2 * 1;
// factorial(4) = 24;

int main(int argc, char const *argv[])
{
    int n;
    int result;
    cout << "Enter the number of which you want to calculate factoraial:";
    cin >> n;
    result = fact(n);
    cout << "The factorial of inputed number is " << result;
    return 0;
}

