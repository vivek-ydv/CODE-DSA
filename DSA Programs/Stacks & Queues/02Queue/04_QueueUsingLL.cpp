#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
// Function to check queue is full or not
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

// Function to check queue is empty or not
bool isEmpty()
{
    if (front == NULL)
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
        struct Node *temp;
        temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if (front == NULL) // if it's the first node
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}
void Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        struct Node *ptr = front;
        front = front->next;
        cout << "Element deleted: " << ptr->data << endl;
        free(ptr);
    }
}
// Function to display the queue
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Enque(11);
    Enque(12);
    Enque(13);
    Enque(14);
    Enque(14);
    Enque(15);

    display(front);
    Dequeue();
    Dequeue();
    Enque(19);
    display(front);

    return 0;
}