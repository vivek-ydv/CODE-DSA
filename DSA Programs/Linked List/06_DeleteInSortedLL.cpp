#include <bits/stdc++.h>
using namespace std;
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
void removeDuplicates(struct node *q)
{
    struct node *p = q->next; // Sucseedar node of 'q'
    // Currently q is poiting to head node & p is poiting to next node of head
    while (p != NULL)
    {
        if (q->data == p->data)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

int main()
{
    create(5);
    create(4);
    create(4);
    create(3);
    create(2);
    create(2);
    create(2);
    create(1);
    display(head);
    removeDuplicates(head);
    display(head);

    return 0;
}
