#include <bits/stdc++.h>
using namespace std;

// Implementation using one pointer
#define MSIZE 10
int qu[MSIZE];
int rear = -1;

// Function to add element to queue : O(1)
void Enque(int val)
{
    if (rear == MSIZE - 1)
    {
        cout << "Queue is Full";
    }
    else
    {
        rear++;
        qu[rear] = val;
    }
}
// Function to delete element from queue : O(n)
void Dequeue()
{
    if (rear == -1)
    {
        cout << "Queue is Empty";
    }
    else
    {
        cout << "Element removed: " << qu[0] << endl;
        for (int i = 1; i <= rear; i++)
        {
            qu[i - 1] = qu[i];
        }
        rear--;
    }
}
// Function to display the queue
void display()
{
    cout << "Displaying the Queue: ";
    for (int i = 0; i <= rear; i++)
    {
        cout << qu[i] << " ";
    }
    cout << endl;
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