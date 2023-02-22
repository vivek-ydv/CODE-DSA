#include <bits/stdc++.h>
using namespace std;
string frequencySort(string A)
{
    // A map to store the count of characters
    unordered_map<char, int> freq;
    string ans;
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Increase the count value
        freq[ch]++;
    }
    while (!freq.empty())
    {
        int max = 0;
        char ch;
        for (auto &&i : freq)
        {
            // Find the char with the maximum number of frequency
            if (i.second > max)
            {
                ch = i.first;
                max = i.second;
            }
        }
        // append into the output string
        while (max--)
        {
            ans.push_back(ch);
        }
        // remove this key value from the map
        freq.erase(ch);
    }

    return ans;
}
int main()
{
    // string A = "tree";
    // string A = "cccaaa";
    string A = "Aabb";
    string res = frequencySort(A);
    cout << res;
    return 0;
}