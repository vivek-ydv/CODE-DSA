#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL; // Dummy head initially pointing to the NULL

// In this we always insert at begining.
// In this method of creation of linkedlist, link will created on left side of dummy node & last enterd element be the head.
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
    cout << "NULL"<<endl;
}

int main()
{
    create(1);
    create(2);
    create(4);
    create(5);

    display(head);
    return 0;
}