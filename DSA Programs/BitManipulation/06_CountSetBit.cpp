#include <iostream>
using namespace std;

int main()
{

    int num = 16, count = 0; // 1 0 1
/*
    // Method 1 : (Time complexity = log(n))
    while (num != 0)
    {
        if (num & 1 != 0)
        {
            count++;
        }
        num = num >> 1; // Updating the number
    }
*/
    // Method 2(Trick) : (Time Complexity = log(No of set bits))
    while (num != 0)
    {
        num = num & (num - 1);
        count++;
    }

    cout << "No of set bit in number are:" << count;
    return 0;
}