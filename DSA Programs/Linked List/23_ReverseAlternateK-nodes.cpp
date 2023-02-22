#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    struct ListNode *next;
};
struct ListNode *head = NULL; // Dummy head initially pointing to the NULL
void create(int val)
{
    ListNode *temp = new ListNode;
    temp->data = val;
    temp->next = head;
    head = temp;
}
void display(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
int countNodes(ListNode *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
/****** Main Logic of this problem ******/

ListNode *reverseAltrKGroup(ListNode *head, int k)
{
    if (k == 1 || head->next == NULL)
    {
        return head;
    }
    int count = countNodes(head);

    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *r = NULL;

    while (p != NULL && count >= k)
    {
        ListNode *last = q;
        ListNode *newEnd = p;

        for (int i = 0; i < k; i++)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            count--;
        }
        newEnd->next = p;
        if (last != NULL)
        {
            last->next = q;
        }
        else
        {
            head = q;
        }
        q = newEnd;
        //Now just simply move for the next 3 times and donot reverse link during this loop and also
        //check along with it that did we had reached the last node.
        for (int i = 0; p != NULL && i < k; i++)
        {
            r = q;
            q = p;
            p = p->next;
            count--;
        }
    }
    return head;
}
int main()
{
    create(9);
    create(8);
    create(7);
    create(6);
    create(5);
    create(4);
    create(3);
    create(2);
    create(1);
    display(head);
    ListNode *newhead = reverseAltrKGroup(head, 3);
    cout << "After performing reverse operation:" << endl;
    display(newhead);
    return 0;
}