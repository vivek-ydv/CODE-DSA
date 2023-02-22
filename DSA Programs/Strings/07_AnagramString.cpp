#include <iostream>
using namespace std;
//  Assuming equal length of both string

int check(string A, string B)
{
    int H[26];
    for (int i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++; // Incrementing on the hashtable at that index
    }
    
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--; // Decrementing on the hashtable at that index

        if (H[B[i] - 97] < 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string A = "medical";
    string B = "decimal";

    if (check(A, B))
    {
        cout << "Anagram";
    }
    else
    {
        cout << "Not Anagram";
    }

    return 0;
}