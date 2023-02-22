#include <iostream>
using namespace std;
void CapToSmall(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] += 32;
    }
    cout << "Converted to the small case : ";
    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i];
    }
    cout << endl;
}
void ToggleCase(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] <= 90 && s[i] >= 65)
        {
            s[i] += 32;
        }
        else
        {
            s[i] -= 32;
        }
    }
    cout << "Toggled string is : ";
    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i];
    }
}
int main()
{
    string s1, s2;
    s1 = "VIVEK";
    s2 = "viVeK";

    CapToSmall(s1);
    ToggleCase(s2);
    return 0;
}