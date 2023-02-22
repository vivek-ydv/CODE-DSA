#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (st.empty())
                    return false;
                else
                {
                    if (s[i] == ')' && st.top() == '(')
                        st.pop();
                    else if (s[i] == '}' && st.top() == '{')
                        st.pop();
                    else if (s[i] == ']' && st.top() == '[')
                        st.pop();
                    else
                        return false; // Donot forget this conditon if already a closing bracket comes before its opening bracket,
                                      // then it is sure it is not a valid parethesis.
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    Solution obj;
    cout << obj.isValid("()") << endl;
    cout << obj.isValid("()[]{}") << endl;
    cout << obj.isValid("(]") << endl;
    return 0;
}