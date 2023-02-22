#include <bits/stdc++.h>
using namespace std;
// Method 2 : Pop Operation is costly
// In this we are going to implement the stack data structure with the help of the two Queues

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void Push(int val) // Push operation
    {
        q1.push(val);
    }
    int PoP() // Pop operation : Costly
    {
        if (q1.empty())
        {
            cout << "Stack Underflow";
            return -1;
        }
        // Move all the element from the q1 to the q2 except the last element
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        // Move back all the elements from the q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    int Peek()
    {
        // It's going to be a little tricky but simple!!!
        if (q1.empty())
        {
            cout << "Stack Underflow";
            return -1;
        }
        // Move all the element from the q1 to the q2 except the last element
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front(); 
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        // Push the poped element also as we are performing "PEEK" operation in this we have to only acess the element
        q1.push(x);
        return x;
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