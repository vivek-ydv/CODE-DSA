#include <iostream>
#include <string>
using namespace std;
void reverseit(string s)
{
    int i = 0;
    int j = s.length() - 1; // doing length-1 as index start from 0
    int temp;
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout << "Revrsed string is : ";
    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i];
    }
}
int main()
{
    string s = "vivek yadav";
    reverseit(s);
    return 0;
}