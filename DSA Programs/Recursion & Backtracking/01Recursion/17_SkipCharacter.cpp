#include <iostream>
using namespace std;

// First method (If we are allowed to use another string in arguments): we can use a another string in which we will be adding char according to condtions.
// Second method : we will decleare return type as a string and add char while returning from the recursive call according to conditions.
// Second Method implementation :-
string skipchar(string s, int i)
{
    if (s[i] == '\0')
    {
        return "";
    }

    char ch = s[i];

    if (ch == 'a')
    {
        return ("" + skipchar(s, i + 1));
    }
    else
    {
        return (ch + skipchar(s, i + 1));
    }
}
int main()
{
    string st = "baccada";
    cout << skipchar(st, 0); // i:0

    return 0;
}