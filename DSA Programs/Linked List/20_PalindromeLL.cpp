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
    ListNode *p;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        p = slow;
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

// Main Logic of the problem :
bool isPalindrome(ListNode *head)
{
    // Find the moddle of the linked list
    ListNode *mid = middleNode(head);
    // Reverse the secondhalf
    ListNode *secondhead = reverseList(mid);

    while (head != NULL && secondhead != NULL)
    {
        if (head->val != secondhead->val)
        {
            return false;
        }
        head = head->next;
        secondhead = secondhead->next;
    }
    return true;
}
int main()
{
    create(1);
    create(2);
    create(3);
    create(2);
    create(1);
    display(head);
    cout << isPalindrome(head);
    return 0;
}