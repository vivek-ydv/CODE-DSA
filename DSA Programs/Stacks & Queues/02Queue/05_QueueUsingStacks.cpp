#include <bits/stdc++.h>
using namespace std;
// Method 1 : Dequeue Operation is costly
// In this we are going to implement the queue data structure with the help of the two stacks

class MyQueue
{
private:
    stack<int> st1; // using C++ STL
    stack<int> st2;

public:
    void EnQueue(int val) // Enqueue operation
    {
        st1.push(val); // Push item into the first stack
    }
    int DeQueue() // Dequeue Operation : Costly
    {
        if (st1.empty() && st2.empty()) // If both the stacks are empty
        {
            cout << "Queue is empty";
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    int Peek() // returns the element at front of queue
    {
        if (st1.empty() && st2.empty()) // If both the stacks are empty
        {
            return -1; // Empty
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
};

int main()
{
    MyQueue qu;
    qu.EnQueue(5);
    qu.EnQueue(8);
    cout << "Peek Element:" << qu.Peek() << endl;
    cout << "Element deleted:" << qu.DeQueue() << endl;

    qu.EnQueue(9);
    qu.EnQueue(10);
    cout << "Peek Element:" << qu.Peek() << endl;
    cout << "Element deleted:" << qu.DeQueue() << endl;
    cout << "Element deleted:" << qu.DeQueue() << endl;
    cout << "Element deleted:" << qu.DeQueue() << endl;
    cout << "Peek Element:" << qu.Peek() << endl;
    return 0;
}