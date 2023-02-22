#include <iostream>
using namespace std;
void countword(string s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            count++;
        }
    }
    cout << "The number of words are : " << count + 1 << endl;
}
int main()
{
    string s1;
    string s2;

    s1 = "Hi this is vivek";    // case 1 : Single space between the two words
    s2 = "Hi this  is   vivek"; // case 2 : More than one spce between two words

    countword(s1);
    countword(s2);
    return 0;
}