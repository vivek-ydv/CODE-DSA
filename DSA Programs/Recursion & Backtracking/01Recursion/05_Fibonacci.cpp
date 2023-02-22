#include <iostream>
using namespace std;
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 2) + fib(n - 1); // Recurrence relation
    }
}
// OPTiMiSED METHOD USING (MEMOISATION TECHNIQUE : Storing the results of function call so the can be utilised again when we need the same call)

int F[50];
int fibopt(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = fibopt(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = fibopt(n - 1);
        }
        F[n] = F[n - 2] + F[n - 1];
        return F[n];
    }
}

int main()
{
    int num;
    cout << "Enter the number:";
    cin >> num;
    for (int i = 0; i < 50; i++)
    {
        F[i] = -1;
    }

    //    cout << fib(num);
    cout << "The value at " << num << " position of fibonacci series is : " << fibopt(num) << endl;
    cout << "The Fibonacci series is ";
    for (int i = 0; i <= num; i++)
    {
        cout << F[i] << " ";
    }
    return 0;
}