#include <bits/stdc++.h>
using namespace std;
// Method 2 : Enqueue Operation is costly
// In this we are going to implement the queue data structure with the help of the two stacks

class MyQueue
{
private:
    stack<int> st1; // using C++ STL
    stack<int> st2;

public:
    void EnQueue(int val) // Enqueue operation : Costly
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val); // Push item into the first stack
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    int DeQueue() // Dequeue Operation
    {
        if (st1.empty())
        {
            cout << "Queue is empty";
        }
        int x = st1.top();
        st1.pop();
        return x;
    }
    int Peek() // returns the element at front of queue
    {
        if (st1.empty())
        {
            return -1;
        }
        return st1.top();
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