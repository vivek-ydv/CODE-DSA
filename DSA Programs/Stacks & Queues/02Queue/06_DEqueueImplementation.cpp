#include <bits/stdc++.h>
using namespace std;

// Implementation will be very much similer to the circular queue,
// We had to add two more function insertFront and deleteEnd , rest logic will be same as circular.

#define MSIZE 5
int qu[MSIZE];
int front = 0;
int rear = 0;

bool isFull()
{
    if ((rear + 1) % MSIZE == front)
        return true;
    else
        return false;
}
bool isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}
// Function to insert from the front
void insertFront(int value)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
    }
    // Since in this element wherever the front is pointing is always a vaccant space therefore
    // first insert element at that position and after that update front position.
    if (front == 0)
    {
        qu[front] = value;
        front = MSIZE - 1;
    }
    else
    {
        qu[front] = value;
        front = front - 1;
    }
}

// Function to insert from the rear
void insertLast(int value)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear = (rear + 1) % MSIZE;
        qu[rear] = value;
    }
}

// Function to dellte from the front
void deleteFront()
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

// Function to delelte from the rear
void deleteLast()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    if (rear == 0)
    {
        rear = MSIZE - 1;
    }
    else
    {
        rear--;
    }
}

int getFront()
{
    if (isEmpty())
        return -1;
    else
        // Since in this element wherever the front is pointing is always a vaccant space therefore
        // if want to get the element at front return element at one position ahead where front is pointing.
        return qu[(front + 1) % MSIZE];
}
int getRear()
{
    if (isEmpty())
        return -1;
    else
        return qu[rear];
}

int main()
{

    return 0;
}