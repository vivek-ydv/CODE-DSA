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

// Main Logic
// Method 2 :Inplace reversal of Linked list(Sliding pointers)
void reverseLList()
{
    struct node *p = head;
    struct node *q = nullptr;
    struct node *r = nullptr;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r; // Reverse linking the nodes
    }

    head = q; // We have to modify the head also
}

int main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    display(head);
    reverseLList();
    cout << "After performing reverse operation:" << endl;
    display(head);
    return 0;
}