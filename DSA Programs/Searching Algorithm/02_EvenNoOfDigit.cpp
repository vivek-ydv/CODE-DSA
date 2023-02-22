#include <bits/stdc++.h>
using namespace std;

int digit(int n){
    if (n == 0)
        return 1;
    int digit = 0;
    while (n > 0)
    {
        digit++;
        n = n / 10;
    }
    return digit;
}
/******* Optimised Method to calculate the number of digits *********/
int digitOptimised(int n)
{
    return (int)(log10(n)) + 1;
}

bool even(int n)
{
    if (digitOptimised(n) % 2 == 0)
        return true;
    else
        return false;
}

int findNumbers(vector<int> vec)
{
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (even(vec[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    // We have to find all the number that have even number of digit
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << findNumbers(nums);
    return 0;
}
