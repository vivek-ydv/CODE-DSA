#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *head = NULL; // Dummy head initially pointing to the NULL
void create(int val)
{
    ListNode *temp = new ListNode;
    temp->val = val;
    temp->next = head;
    head = temp;
}
void display(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
ListNode *middleNode(ListNode *head)
{
    // Simply by using slow and fast pointer method

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *reverseList(ListNode *rhead)
{
    struct ListNode *p = rhead;
    struct ListNode *q = nullptr;
    struct ListNode *r = nullptr;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r; // Reverse linking the nodes
    }
    rhead = q; // We have to modify the head also
    return rhead;
}
/***************** Method 1: Connecting the links******************/

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;
    // Find the moddle of the linked list
    ListNode *mid = middleNode(head);

    // Reverse the second haf
    ListNode *fhead = head;
    ListNode *shead = reverseList(mid);

    // Connecting the links
    while (fhead != NULL && shead != NULL)
    {
        ListNode *temp = fhead->next;
        fhead->next = shead;
        fhead = temp;

        temp = shead->next;
        shead->next = fhead;
        shead = temp;
    }
    if (fhead != NULL)
    {
        fhead->next = NULL;
    }
}
/***************** Method 2: Connecting the links(SAME APPROACH AS MERGING WITHOUT EXTRA SPACE)******************/

// void reorderList(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//         return;
//     // Find the moddle of the linked list
//     ListNode *mid = middleNode(head);

//     // Reverse the second half
//     ListNode *fhead = head;
//     ListNode *shead = reverseList(mid);

//     ListNode *third, *tail;
//     tail = third = fhead;
//     fhead = fhead->next;

//     // Connecting the links
//     while (fhead != NULL && shead != NULL)
//     {
//         tail->next = shead;
//         tail = shead;
//         shead = shead->next;
//         tail->next = fhead;
//         tail = fhead;
//         fhead = fhead->next;
//     }
//     if (fhead != NULL)
//     {
//         tail->next = NULL;
//     }
//     head = third;
// }

int main()
{
    create(5);
    create(4);
    create(3);
    create(2);
    create(1);
    display(head);
    reorderList(head);
    display(head);
    return 0;
}