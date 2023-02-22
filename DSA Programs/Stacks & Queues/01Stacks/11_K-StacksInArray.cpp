#include <bits/stdc++.h>
using namespace std;

class KStack
{
private:
    int *arr;
    int *top;
    int *next;
    int n, k; // k: number of stacks, n: size of array
    int freespot;

public:
    // Initialising the data structure inside the constructor
    KStack(int N, int K)
    {
        n = N;
        k = K;

        arr = new int[n]; // To store the elements
        next = new int[n];
        top = new int[k]; // To store the top of all the k stacks

        // initilaise the top
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }

        // initialise the next
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // update the last index value to -1
        next[n - 1] = -1;

        // intialise the freespot
        freespot = 0;
    }

    // reutrns true if the element is sucessfully pushed into given stack
    bool push(int item, int sn) // sn: stack number (0 to k)
    {
        // Check overflow conditon
        if (freespot == -1)
        {
            return false; // stack overflow
        }
        else
        {
            // Find index
            int i = freespot;

            // Update the freespot
            freespot = next[i];

            // Insert the element
            arr[i] = item;

            // Update next
            next[i] = top[sn]; // since now arr[i] contains a element therefore next[i] will now contains next element index after stack top element
                               // simply : purane wale top ka value dal do

            // Update the top
            top[sn] = i;

            return true;
        }
    }

    // pop the element from stack : reverse the process
    int pop(int sn) // sn: stack number (0 to k)
    {
        // Check underflow conditon
        if (top[sn] == -1)
        {
            return -1;
        }
        else
        {
            // Find index of top item in stack number 'sn'
            int i = top[sn];

            // Update the top, as previous top is stored in next[i]
            top[sn] = next[i];

            next[i] = freespot; // update the next[i]
            freespot = i;       // update the free spot value

            return arr[i];
        }
    }
};
int main()
{
    // Let us create 3 stacks in an array of size 6
    int k = 3, n = 6;
    KStack ks(n, k);

    // Let us put some items in stack number 0
    ks.push(10, 0);
    ks.push(20, 0);

    // Let us put some items in stack number 1
    ks.push(22, 1);

    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;

    // Let us put some items in stack number 2
    ks.push(27, 2);
    ks.push(15, 2);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;

    return 0;
}