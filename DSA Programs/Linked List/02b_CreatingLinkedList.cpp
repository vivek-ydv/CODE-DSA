#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; // Dummy head initially pointing to the NULL
struct node *tail = NULL; // Dummy tail initially pointing to the NULL

// In this method of creation of linkedlist, link will created on right side of dummy node & first enterd element be the head.
// In this method we have to maintain one more pointer "tail".
// In this we always insert at last.
void create(int val)
{
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) // Creation of Head Node
    {
        // If till now there is no element hence both head and tail will be pointing to null,
        // hence this will be the first(head) node.
        head = tail = temp; // Since Only one element is till now in linkedList hence both the head and tail are pointing to the same node.
    }
    else
    {
        tail->next = temp; // Linking the last tail with current new node.
        tail = temp;       // Updating the tail.
    }
}

void display(struct node *ptr)
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
    create(1);
    create(2);
    create(4);
    create(3);
    create(5);

    display(head);
    return 0;
}