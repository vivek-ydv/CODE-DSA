#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; // Dummy head initially pointing to the NULL

void create(int *val, int n)
{
    struct node *temp;
    struct node *tail; // Will be Pointing to last node.
    // Creating the First(head) node
    head = new node;
    head->data = val[0];
    head->next = NULL;
    tail = head; // Since Only one element is till now in linkedList hence both the head and tail are pointing to the same node.

    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = val[i];
        temp->next = NULL;

        // For the First time when loop is runing after creation of head node, both head and tail are same node as pointing to the same NULL value,
        // So in below line(3rd last) when we are updating the next of tail, then next of head will also get updated as both are same node during first run of loop, 
        // that is the how NULL value of next of head node is also updated and linked with second node.
        tail->next = temp;
        //In below line we are updating tail node, hence now tail and head are independent node after creation of second node.
        tail = temp; // Assiging this node as the last(tail) node.
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);
    return 0;
}