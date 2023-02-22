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

/****** Main Logic of this problem ******/
node *reverseBetween(node *head, int left, int right)
{
    if (left == right)
    {
        return head;
    }
    node *last = NULL; // the last node of the previous part that we have before this range,in which we want to reverse.
                       // the node just before the left range.
    node *current = head;
    for (int i = 0; current != NULL && i < left - 1; i++)
    {
        last = current;
        current = current->next;
    }
    node *newEnd = current; // left range node will be the new end after reversing.

    // Now Perform Simple reverse operation
    node *p = current->next;
    node *q = current;
    node *r = current;
    for (int i = 0; p != NULL && i < right - left; i++)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    // After the loop is finished the : p will be on the next node of right range node & q will be on the right range node.

    newEnd->next = p; // Both cases will be handeld if the right range node is rightmost(tail) node or the any node behind tail.
    if (last != NULL)
    {
        last->next = q;
    }
    else // i.e. if left range node value is 1(head node).
    {
        head = q;
    }
    return head;
}

int main()
{
    create(5);
    create(4);
    create(3);
    create(2);
    create(1);
    display(head);

    node *newhead = reverseBetween(head, 2, 4);
    cout << "After performing reverse operation:" << endl;
    display(newhead);
    return 0;
}