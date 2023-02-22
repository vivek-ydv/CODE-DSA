#include <iostream>
using namespace std;
struct employees
{
    /* data */
    int eId;
    char favchar;
    float salary;
};

int main(int argc, char const *argv[])
{
    struct employees vivek;
    vivek.eId = 1;
    vivek.favchar = 'v';
    vivek.salary = 1200000.99F;

    cout << "The id is " << vivek.eId << endl;
    cout << "The favchar is " << vivek.favchar << endl;
    cout << "The salery is(inr) " << vivek.salary << endl;

    return 0;
}
