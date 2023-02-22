#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> st; // Stack to hold the values
    stack<int> ss; // supporting stack to hold the minimum values
public:
    void Push(int item)
    {
        st.push(item);
        if (ss.size() == 0 || ss.top() >= item)
        {
            ss.push(item);
        }
    }
    int PoP()
    {
        if (st.size() == 0)
        {
            return -1;
        }

        int res = st.top();
        st.pop();
        // If top of stack and supporting stack both are equal then pop from the supporting stack also
        if (res == ss.top())
        {
            ss.pop();
        }
        return res;
    }

    // Function to get the minimun element in the stack
    int getMin()
    {
        if (ss.size() == 0)
        {
            return -1;
        }
        else
        {
            return ss.top();
        }
    }
};
int main()
{
    MinStack s1;

    s1.Push(18);
    s1.Push(19);
    s1.Push(29);
    s1.Push(15);
    cout << "Minvalue : " << s1.getMin() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;
    s1.Push(16);
    cout << "Minvalue : " << s1.getMin() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;
    cout << "Minvalue : " << s1.getMin() << endl;

    return 0;
}