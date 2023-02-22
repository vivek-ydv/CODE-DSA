#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void create(int A[], int n)
{
    struct node *temp;

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

void insertAtbeg(int val)
{
    struct node *temp = new node;
    temp->data = val;
    temp->next = head; // Connecting the current new node with head
    temp->prev = NULL;
    head->prev = temp; // Connecting the head node 'prev' with current new node
    head = temp;       // Assigning this node as new head
}
void insertAtend(int val)
{
    struct node *temp = new node;
    temp->data = val;
    tail->next = temp; // Connecting the tail node with current new node
    temp->next = NULL;
    temp->prev = tail; // Connecting the current new node with tail
    tail = temp;       // Assigning this node as new tail
}
void inserAtpos(int pos, int val)
{
    struct node *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    struct node *temp = new node;
    temp->data = val;
    
    // Linking of new node with the next node
    temp->next = p->next;
    if (p->next) // Check if it is not last node then only modify it
        p->next->prev = temp;

    // Linking of new node with the previous node
    temp->prev = p;
    p->next = temp;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);

    // insertAtbeg(2);
    // display(head);

    // insertAtend(12);
    // display(head);

    inserAtpos(4, 11);
    display(head);

    return 0;
}