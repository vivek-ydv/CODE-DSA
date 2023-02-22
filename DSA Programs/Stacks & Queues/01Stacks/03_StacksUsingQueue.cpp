#include <bits/stdc++.h>
using namespace std;
// Method 1 : Push Operation is costly
// In this we are going to implement the stack data structure with the help of the two Queues

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int val) // Push operation : Costly
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val); // Push item into the first queue
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int PoP() // Pop operation 
    {
        if (q1.empty())
        {
            cout << "Stack Underflow";
            return -1;
        }

        int x = q1.front();
        q1.pop();
        return x;
    }
    int Peek()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow";
            return -1;
        }
        return q1.front();
    }
};
int main()
{
    MyStack st;
    st.Push(2);
    st.Push(3);
    st.Push(5);
    cout << "Peek Element :" << st.Peek() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;
    st.Push(7);
    st.Push(11);

    cout << "Peek Element :" << st.Peek() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;
    cout << "PoPed Element:" << st.PoP() << endl;

    return 0;
}