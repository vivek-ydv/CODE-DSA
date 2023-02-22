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
    struct node *temp, *last;
    // Creation of first(head node)
    head = new node;
    head->data = A[0];
    head->next = head; // Circular Links
    head->prev = head; // Circular Links
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = A[i];
        temp->next = last->next; // Connecting Circular Links
        head->prev = temp;       // Connecting Circular Links
        // Connecting the new current node with previous node
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void display(struct node *ptr)
{
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);
    return 0;
}