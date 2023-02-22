#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/happy-number/
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

int digitSqSum(int n)
{
    int sum = 0;
    while (n)
    {
        int digit = n % 10;
        sum += pow(digit, 2);
        n = n / 10;
    }
    return sum;
}
// Simple Slow and Fast Pointer Approach
bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = digitSqSum(slow);
        fast = digitSqSum(digitSqSum(fast));
        if (fast == 1) // Means the number is happy
        {
            return true;
        }
    } while (slow != fast);
    return false;
}

int main()
{
    cout << isHappy(19);
    return 0;
}