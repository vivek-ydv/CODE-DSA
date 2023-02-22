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

void insertAtBegorLast(int v)
{
    struct node *temp = new node;
    temp->data = v;

    struct node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    last->next = temp;
    temp->next = head;
    //  head = temp;   // For insertion at beg just assign it as the new head
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);

    insertatPos(12, 4);
    display(head);

    insertAtBegorLast(15);
    display(head);
    return 0;
}