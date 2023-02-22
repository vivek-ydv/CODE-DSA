#include <bits/stdc++.h>
using namespace std;

#define MSIZE 10
int st[MSIZE]; // Global Declearation of stack
int top = -1;  // It will always point to the top of the stack

// Function to check stack is full or not
bool isFull()
{
    if (top == MSIZE - 1)
        return true;
    else
        return false;
}
// Function to check stack is empty or not
bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
// Function to push the element into the stack
void push(int item)
{
    if (isFull())
    {
        cout << "Can't push data! Stack Overflow";
    }
    else
    {
        top++;
        st[top] = item;
    }
}
// Function to pop the element from the stack
void pop()
{
    if (isEmpty())
    {
        cout << "Can't pop data! Stack Underflow" << endl;
    }
    else
    {
        cout << "Element poped: " << st[top--] << endl;
    }
}
// Function to get the peek element
void peek()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Peek value is: " << st[top] << endl;
    }
}
// Function to display the stack
void display()
{
    cout << "Displaying Stack: " << endl;
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}
// Drivers code
int main()
{
    push(11); // Peforming push operation
    push(17);
    push(14);
    push(28);
    push(20);
    push(16);
    display(); // Calling display function
    peek();    // Calling peek function
    pop();     // Calling pop function
    pop();     // Calling pop function
    display(); // Calling display function
    peek();    // Calling peek function

    return 0;
}