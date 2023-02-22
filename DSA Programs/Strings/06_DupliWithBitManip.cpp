#include <iostream>
using namespace std;
// Assume only small case latter
// It can only find duplicates but cannot count them
// Time Complexity : O(n)
void sduplicate(string s)
{
    int H = 0, Mask = 0; // Take 4 byte i.e. 32 bits

    for (int i = 0; s[i] != '\0'; i++)
    {
        Mask = 1;
        Mask = Mask << s[i] - 97; // Left shift
        if ((Mask & H) > 0)
        {
            cout << "Duplicate characters: " << s[i] << endl;
        }
        else
        {
            H = H | Mask;
        }
    }
}
int main()
{
    string s = "finding";
    sduplicate(s);
    return 0;
}