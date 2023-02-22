#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    // A Map to store the frequency of charactrs.
    // In map all integer type values are already initialised with 0.
    unordered_map<char, int> freq;
    string ans;
    queue<int> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Increase the count value
        freq[ch]++;

        // Push into the queue
        q.push(ch);

        while (!q.empty())
        {
            // If Count value for a char exceeds 1 then it will be poped out complelty from the queue
            if (freq[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    // string A = "aabc";
    string A = "leetlovecode";
    string res = FirstNonRepeating(A);
    cout << res;
    return 0;
}