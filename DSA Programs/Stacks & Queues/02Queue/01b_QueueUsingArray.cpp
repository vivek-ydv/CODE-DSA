#include <bits/stdc++.h>
using namespace std;
// Implementation using two pointer

#define MSIZE 10
int qu[MSIZE];
int front = -1; // For deletion of element
int rear = -1;  // For the insertion of the element

// Function to check queue is full or not
bool isFull()
{
    if (rear == MSIZE - 1)
        return true;
    else
        return false;
}

// Function to check queue is empty or not
bool isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}
// Function to add element to queue : O(1)
void Enque(int val)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        qu[rear] = val;
    }
}
// Function to delete element from queue : O(1)
void Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        front++;
        cout << "Deleted item: " << qu[front] << endl;
    }
}
// Function to display the queue
void display()
{
    cout << "Displaying the Queue: ";
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << qu[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Enque(11);
    Enque(12);
    Enque(13);
    Enque(14);
    Enque(15);
    display();
    
    Dequeue();
    Dequeue();
    display();
    return 0;
}