#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *create(int *val, int n)
{
    struct node *head = NULL;
    struct node *temp;
    struct node *tail;
    // Creating the head Node
    head = new node;
    head->data = val[0];
    head->next = NULL;
    tail = head; // Since Only one element is till now in linkedList hence both the head and tail are pointing to the same node.
    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = val[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp; // Assiging this node as the last(tail) node.
    }
    return head;
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

/***************** Main logic for Merging of two linked list*****************/
struct node *mergeSLL(struct node *f, struct node *s)
{
    /* First Method : Creating a third Linked list and Comparing the value of nodes of first and second linked list and adding them in third linked list,
       and incrementing the nodes of that linked list similer to arrays method. */

    // Second Method : Without using any extra space(linked list)
    node *third = NULL; // It will be always point to the head of merged linked list
    node *tail = NULL;  // It will always point to last element of merged linked list
    if (f == NULL && s == NULL)
    {
        return third;
    }
    if (f == NULL) // If first is NULL then simply return the second
    {
        return s;
    }
    else if (s == NULL)
    {
        return f;
    }
    else if (f->data < s->data)
    {
        third = tail = f; // We got the new head of our merged linked list intially third and tail will be pointing here,
                          // as we got the other elements by comparing we will be linking it with tail
        f = f->next;
        tail->next = NULL;
    }
    else
    {
        third = tail = s;
        s = s->next;
        tail->next = NULL;
    }

    while (f != NULL && s != NULL)
    {
        if (f->data < s->data)
        {
            tail->next = f; // Updaing the link of last tail
            tail = f;       // Assigining this node as the new tail
            f = f->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = s;
            tail = s;
            s = s->next;
            tail->next = NULL;
        }
    }

    if (f != NULL)
    {
        // Means that second linked list is finished hence simply connect the tail of merged list with the first
        tail->next = f;
    }
    else
    {
        tail->next = s;
    }

    return third; // Simply return the head of merged list
}

int main()
{
    int arr1[] = {1, 4, 5, 6, 8};
    struct node *f = create(arr1, 5);

    int arr2[] = {2, 3, 6, 9, 12, 15};
    struct node *s = create(arr2, 6);

    display(f);
    display(s);

    struct node *newHead = mergeSLL(f, s);
    display(newHead);

    return 0;
}