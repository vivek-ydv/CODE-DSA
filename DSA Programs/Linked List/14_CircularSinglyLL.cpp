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
// Iterative Display Function
void display(struct node *ptr)
{
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
// Recursive Display Function
void Rdisplay(struct node *ptr)
{
    static int flag = 0; // We are using it so that our recursive display function runs atleast once
    if (ptr != head || flag == 0)
    {
        flag = 1;
        cout << ptr->data << " ";
        display(ptr->next);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 10};
    create(arr, 6);
    display(head);
    Rdisplay(head);
    return 0;
}