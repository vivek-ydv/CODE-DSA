/*
Find the two non repeating number in array where other every element repeat twice
a = [5,4,1,4,3,5,1,2]
Output = 3
*/

#include <iostream>
using namespace std;

int main()
{
    int a[] = {5, 4, 1, 4, 7, 5, 1, 8};
    int res = 0;
    int x = 0, y = 0;
    for (int i = 0; i < 8; i++)
    {
        res = res ^ a[i]; 
    }

    // Create a mask to get the the rightmost setbit
    int mask = res & ((~res) + 1); // ~res + 1 = -res
    for (int i = 0; i < 8; i++)
    {
        if (a[i] & mask)
        {
            x = x ^ a[i];
        }
        else
        {
            y = y ^ a[i];
        }
    }
    cout << "Number are: " << x << " and " << y;
    return 0;
}
