#include <iostream>
using namespace std;

int main()
{
    // Array Example
    int marks[4] = {23, 45, 56, 89};

    int mathMarks[4];
    mathMarks[0] = 2278;
    mathMarks[1] = 738;
    mathMarks[2] = 378;
    mathMarks[3] = 578;

    cout << "These are math marks" << endl;
    cout << mathMarks[0] << endl;
    cout << mathMarks[1] << endl;
    cout << mathMarks[2] << endl;
    cout << mathMarks[3] << endl;

    cout << "These are marks" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "The value of marks " << i << " is " << marks[i] << endl;
    }

    // Pointers and arrays
    int *p = marks; // Pointer will store the base adress i.e. the adress of marks[0]
    cout << *(p++) << endl;
    cout << *(++p) << endl;
   // cout << "The value of *p is " << *p << endl;
   // cout << "The value of *(p+1) is " << *(p + 1) << endl;
   // cout << "The value of *(p+2) is " << *(p + 2) << endl; 
   // cout << "The value of *(p+3) is " << *(p + 3) << endl;

    return 0;
}
