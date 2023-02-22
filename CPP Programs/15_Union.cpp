#include <iostream>
using namespace std;
union employees
{
    /* data */
    int eId;
    char favchar;
    float salary;
};

int main(int argc, char const *argv[])
{
    union employees vivek; // Union Share a single memory location with each datatype and allocate memory to thst data which is written in the last

    vivek.salary = 1000;
    vivek.favchar = 'v';
    vivek.eId = 1;

    cout << "The id is " << vivek.eId << endl;
    cout << "The favchar is " << vivek.favchar << endl;
    cout << "The salery is(inr) " << vivek.salary << endl;

    return 0;
}
