#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    enum meal
    {
        breakfast,
        lunch,
        dinner
    };
    meal m1 = breakfast;
    meal m2 = lunch;
    meal m3 = dinner;

    cout << m1 << endl
         << m2 << endl
         << m3;

    return 0;
}
