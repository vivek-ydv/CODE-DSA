#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
int len(ListNode *ptr)
{
    int l = 0;
    while (ptr != NULL)
    {
        l++;
        ptr = ptr->next;
    }
    return l;
}
// Main Logic For this problem
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    int l1 = len(headA);
    int l2 = len(headB);
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    if (l1 > l2)
    {
        int d = l1 - l2;
        while (d--)
        {
            ptr1 = ptr1->next;
        }
    }
    else
    {
        int d = l2 - l1;
        while (d--)
        {
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return 0;
}
int main()
{

    return 0;
}