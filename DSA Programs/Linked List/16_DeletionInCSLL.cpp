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
    struct node *last;
    // Creating the First(head) node
    head = new node;
    head->data = val[0];
    head->next = head; // Circular link
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = val[i];
        temp->next = last->next; // Connecting the circular link
        last->next = temp;
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

void deleteatPos(int pos)
{
    struct node *p = head;
    struct node *q = NULL; // Following Pointer
    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    // Now p will be pointing to the node which we want to delete and q will be pointing the preceeding node.
    q->next = p->next;
    free(p);
}
void deleteAtBeg()
{
    struct node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    struct node *p = head;
    head = head->next;
    last->next = head;
    delete (p);
}
void deleteAtLast()
{
    struct node *last = head;
    while (last->next->next != head)
    {
        last = last->next;
    }
    struct node *p = last->next;
    last->next = head;
    free(p); 
}
int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);

    // deleteatPos(6);
    // display(head);

    // deleteAtBeg();
    // display(head);

    // deleteAtLast();
    // display(head);

    return 0;
}