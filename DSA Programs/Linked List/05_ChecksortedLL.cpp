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
bool check(struct node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (x > p->data)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}
int main()
{
    create(5);
    create(4);
    create(3);
    create(2);
    create(1);
    cout << check(head);
    return 0;
}