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
// Method 3 : Recursion - By utilising the recusrsive phase of recursion
void reverseLList(struct node *p, struct node *q)
{
    if (p == NULL)
    {
        head = q; // updaing the head
        return;
    }
    reverseLList(p->next, p);
    p->next = q; // reverse linking the links of nodes in return phase
}

int main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    create(6);
    display(head);

    reverseLList(head, nullptr);
    cout << "After performing reverse operation:" << endl;
    display(head);
    return 0;
}