#include <bits/stdc++.h>
using namespace std;

// While applying this implementation in problem solving, take one size extra than the given,
// e.g. for 4 elements take array of 5 size.

#define MSIZE 5
int qu[MSIZE];
int front = 0; // For deletion of element
int rear = 0;  // For the insertion of the element

// Function to check queue is full or not
bool isFull()
{
    if ((rear + 1) % MSIZE == front)
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
        rear = (rear + 1) % MSIZE;
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
        front = (front + 1) % MSIZE;
        cout << "Deleted item: " << qu[front] << endl;
    }
}
// Function to get front element from queue : O(1)
int Front()
{
    if (isEmpty())
        return -1;
    else
        // Since in this element wherever the front is pointing is always a vaccant space therefore
        // if want to get the element at front return element at one position ahead where front is pointing.
        return qu[(front + 1) % MSIZE];
}
// Function to get rear element from queue : O(1)
int Rear()
{
    if (isEmpty())
        return -1;
    else
        return qu[rear];
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
        int i = (front + 1) % MSIZE;
        while (i != (rear + 1) % MSIZE) // Since we have to display the last element also hence rear + 1
        {
            cout << qu[i] << " ";
            i = (i + 1) % MSIZE;
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
    display();

    Dequeue();
    Enque(69);
    Enque(51);
    display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    display();
    return 0;
}