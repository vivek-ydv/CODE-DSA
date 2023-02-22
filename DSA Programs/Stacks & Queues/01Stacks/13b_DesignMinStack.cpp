#include <bits/stdc++.h>
using namespace std;

// Without any extra space : O(1)
class MinStack
{
private:
    stack<int> st;     // Stack to hold the values
    int min = INT_MIN; // Variable to store the min values

public:
    void Push(int item)
    {
        if (st.empty()) // If it is the first element
        {
            st.push(item);
            min = item;
        }
        else
        {
            if (item < min)
            {
                int val = 2 * item - min;
                st.push(val);
                min = item;
            }
            else
            {
                st.push(item);
            }
        }
    }
    int PoP()
    {
        if (st.empty())
        {
            return -1;
        }

        int curr = st.top();
        if (curr > min)
        {
            st.pop();
            return curr;
        }
        else
        {
            // If control reches here means that actual current value(TOS) was the minimum value, which is stored in min variable
            // therefore store it to return as it is top of the stack.
            int res = min;

            int val = 2 * min - curr; // to get the previous min value
            min = val;                // update the min variable value

            st.pop();
            return res;
        }
    }

    // Function to get the minimun element in the stack
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return min;
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        if (st.top() > min)
        {
            return st.top();
        }
        else
        {
            // As the top of the stack was the minmum value and that was stored in the min variable.
            return min;
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
    cout << "TOSvalue : " << s1.top() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;

    s1.Push(16);
    cout << "Minvalue : " << s1.getMin() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;

    cout << "Minvalue : " << s1.getMin() << endl;
    cout << "TOSvalue : " << s1.top() << endl;
    cout << "Popedvalue : " << s1.PoP() << endl;

    return 0;
}