#include <iostream>
using namespace std;

// Approach 1 : First reverse the string and store it in another string then compare both string index by index by two index pointer
// Approach 2 : Take two index pointer first pointing to first and second to the last and compare each element till (i < j)
int check(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main()
{
    string str = "madam";
    if (check(str))
    {
        cout << "String is palindrome";
    }
    else
    {
        cout << " Not palindrome";
    }

    return 0;
}