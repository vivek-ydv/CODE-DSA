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
// Method 1 : Reverse the elements
void reverseLList()
{
    int A[20];
    int i = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        A[i] = ptr->data;
        i++;
        ptr = ptr->next;
    }

    // Again traverse the linked list and copy the element of array in reverse order
    struct node *ptr2 = head;
    i--; // i has incresed one time more than the actual elements 
    while (ptr2 != NULL && i >= 0)
    {
        ptr2->data = A[i];
        i--;
        ptr2 = ptr2->next;
    }
}

int main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    display(head);
    reverseLList();
    cout<<"After performing reverse operation:"<<endl;
    display(head);
    return 0;
}