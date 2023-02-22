#include <iostream>
using namespace std;

// Finding duplicate in a string of the small cases
void sduplicate(string str)
{
    int H[26]={0};
   
    for (int i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            char dupl = i + 97;
            cout << "Duplicate : " << dupl << endl;
        }
    }
}
int main()
{
    string s = "finding";
    sduplicate(s);
    return 0;
}