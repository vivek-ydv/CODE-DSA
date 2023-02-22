/*
Find the only one non repeating number in array where other every element repeat twice
a = [5,4,1,4,3,5,1]
Output = 3
*/

#include <iostream>
using namespace std;

int main()
{
    int a[7] = {5, 4, 1, 4, 3, 5, 1}, count;
    // Approach 1 : Using Nesteed Loop : Time Complexity O(n^2)
    /*
    for (int i = 0; i < 7; i++)
    {
        count = 0;
        for (int j = 0; j < 7; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        if (count == 2)
        {
            continue;
        }
        else
        {
            cout << "Number is " << a[i];
            break;
        }
    }
    */
    // Approach 2 : Using XOR Proprty(n^n=0) : Time complexity O(n)
    int res = 0;
    for (int i = 0; i < 7; i++)
    {
        res = res ^ a[i];  // All the same element will cancel each other and only non repeating number will remain
    }
    cout << "Number is " << res;
    return 0;
}
