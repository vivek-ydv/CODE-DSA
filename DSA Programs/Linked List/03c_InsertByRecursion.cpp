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
void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

/******* Node return type ***********/
node *insertR(int val, int index, node *head)
{
    if (index == 0)
    {
        struct node *temp = new node;
        temp->data = val;
        temp->next = head;
        return temp;
    }

    head->next = insertR(val, index - 1, head->next);
    return head;
}
/******* Void return type ***********/
void insertr(int val, int index, node *p)
{
    if (index == 0)
    {
        struct node *temp = new node;
        temp->data = val;
        temp->next = p->next;
        p->next = temp;
        return;
    }
    insertR(val, index - 1, p->next);
}

int main()
{
    create(5);
    create(4);
    create(3);
    create(7);
    display(head);

    // insertr(11, 2, head);
    // display(head);

    node *nhead = insertR(11, 2, head);
    display(nhead);
    return 0;
}