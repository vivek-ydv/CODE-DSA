#include <bits/stdc++.h>
using namespace std;

bool search(string str, char target)
{
    for (int i = 0;  str[i] != '\0'; i++)
    {
        if (target == str[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string str = "Vivek";
    char target = 'e';
    cout << search(str, target);
    return 0;
}