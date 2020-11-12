/*
    方法一:
*/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        bool flag = false;
        while (p->next->next)
        {
            if (p->next->val == p->next->next->val)
            {
                p->next->next = p->next->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
/*
    方法二:
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        ListNode *q = head;
        while (q && q->next)
        {
            if (p->next->val == q->next->val)
            {
                while (q->next && p->next->val == q->next->val)
                    q = q->next;
                p->next = q;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
