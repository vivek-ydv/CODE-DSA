#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = head;
    head = temp;
}
void insertatBeg(int v)
{
    struct node *temp = new node;
    temp->data = v;
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

// Main logic for this problem
void insertinSorted(int x)
{
    struct node *p = head;
    struct node *q = NULL; // A FOLLOWING pointer it will follow the "p" and will point to node left of "p"

    if (head == NULL) // If it is the first element then
    {
        insertatBeg(x);
    }
    else if (x < p->data) // If element is smaller than the first element then
    {
        insertatBeg(x);
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        // Now 'p' will be pointing to node of which data value is greater than the x and 'q' is poiting to its preceeding node
        // Hence we have to insert the value between q and p
        struct node *temp = new node;
        temp->data = x;
        temp->next = q->next;
        q->next = temp;
    }
}
int main()
{
    create(5);
    create(4);
    create(2);
    create(1);
    display(head);

    insertinSorted(3);
    display(head);
    insertinSorted(0);
    display(head);

    return 0;
}