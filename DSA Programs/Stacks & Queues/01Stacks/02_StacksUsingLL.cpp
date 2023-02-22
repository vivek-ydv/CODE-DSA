#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

// Function to check stack is empty or not
bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
// Function to check stack is full or not
bool isFull()
{
    struct Node *temp;
    temp = new Node;
    struct Node *ptr = temp;
    free(temp);

    if (ptr == NULL)
        return true;
    else
        return false;
}

// Function to push the element into the stack
void push(int val)
{
    if (isFull())
        cout << "Stack Overflow";
    else
    {
        struct Node *temp;
        temp = new Node; // Creating the new Node
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}
// Function to pop the element from the stack
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        cout << "Element poped: " << ptr->data << endl;
        free(ptr);
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
        cout << "Peek value is: " << top->data << endl;
    }
}
// Function to display the stack
void display()
{
    struct Node *ptr = top;
    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
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