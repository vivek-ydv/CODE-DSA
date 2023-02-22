#include <iostream>
using namespace std;

// Skip the string "apple" in string ""baccdappledh""
string skipstring(string s)
{
    if (s.empty())
    {
        return "";
    }
    if (s[0] == 'a' && s[1] == 'p' && s[2] == 'p' && s[3] == 'l' && s[4] == 'e')
    {
        return skipstring(s.substr(5));
    }
    else
    {
        return (s.at(0) + skipstring(s.substr(1)));
    }
}
int main()
{
    string st = "bacdappleah";

    // string r = st.substr(1);
    // cout << r;

    cout << skipstring(st); 

    return 0;
}
