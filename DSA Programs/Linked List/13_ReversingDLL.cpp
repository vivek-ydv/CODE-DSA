#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;

void create(int A[], int n)
{
    struct node *temp;
    struct node *tail;

    // Creation of first(head node)
    head = new node;
    head->data = A[0];
    head->prev = head->next = NULL;
    tail = head; // Since Only one element is till now in linkedList hence both the head and tail are pointing to the same node.

    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = A[i];
        tail->next = temp; // Connecting the last node with this current new node
        temp->next = NULL;
        temp->prev = tail; // Connecting the current new node with last node
        tail = temp;       // Assigning this node as new last(tail) node.
    }
}
void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "-";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

// Main Logic For this problem
void reverseDLL()
{
    node *p = head;
    struct node *temp;
    while (p != NULL)
    {
        node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev; // Since we have interchange the nodes hence now next is pointing to prev
                     // and prev is pointing to next.
        if (p != NULL && p->next == NULL)
        {
            head = p; // Updating the head
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    reverseDLL();
    display(head);
    return 0;
}