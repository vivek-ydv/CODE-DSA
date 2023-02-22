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
    struct node *temp = new node;
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
void insertatPos(int v, int pos)
{
    struct node *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    struct node *temp = new node;
    temp->data = v;
    temp->next = p->next;
    p->next = temp;
}
void insertatEnd(int v)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    // After finishing of loop p will be pointing to last node
    struct node *temp = new node;
    temp->data = v;
    temp->next = NULL;
    p->next = temp;
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

int main()
{
    create(5);
    create(4);
    create(3);
    create(7);
    display(head);

    // Calling insert at begining function
    insertatBeg(1);
    display(head);

    // Calling insert at position function
    insertatPos(10, 3);
    display(head);

    // Calling insert at end function
    insertatEnd(9);
    display(head);

    return 0;
}