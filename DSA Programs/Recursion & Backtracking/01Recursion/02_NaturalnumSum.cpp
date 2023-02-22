#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1); // Recurrence relation
    }
}
int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int res = sum(num);
    cout << "Sum of natural number upto " << num << " is " << res;
    return 0;
}