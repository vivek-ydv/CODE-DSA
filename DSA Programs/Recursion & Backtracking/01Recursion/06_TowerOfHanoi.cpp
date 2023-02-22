#include <iostream>
using namespace std;
void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B); 
        cout << "Move disk " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
}
int main()
{
    /*
    A = Source tower
    B = Auxillary tower
    C = Destination tower
    */
    TOH(3, 'A', 'B', 'C');
    return 0;
}