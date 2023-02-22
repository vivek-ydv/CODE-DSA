#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; // Dummy head initially pointing to the NULL
void create(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = head;
    head = temp;
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

void deleteFirstN()
{
    node *p = head;    // Assigining current head value in "p"
    head = head->next; // Moving head to next node
    free(p);
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
void deleteLastN()
{
    struct node *p = head;
    struct node *q = NULL; // Following Pointer
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    // Now p will be pointing last node which we want to delete and q will be pointing the preceeding node.
    q->next = NULL;
    free(p);
}

int main()
{
    create(1);
    create(2);
    create(4);
    create(5);
    display(head);

    // Calling deleting first node function
    // deleteFirstN();

    // Calling deleting at postion function
    // deleteatPos(3);

    // Calling deleting last node function
    deleteLastN();

    display(head);
    return 0;
}