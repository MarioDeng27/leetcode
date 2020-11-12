/*
    自己的想法,双指针

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
        //int temp = dummy->val;
        bool flag = false;
        while (p->next->next)
        {
            //temp = p->val;
            if (p->next->val == p->next->next->val)
            {
                p->next->next = p->next->next->next;
                flag = true;
            }
            else
            {
                if (flag)
                {
                    p->next = p->next->next;
                    flag = false;
                }

                else
                {
                    p = p->next;
                    flag = false;
                }
            }
        }
        if (flag)
            p->next = p->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
/*
    方法一的优化
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
                p->next = q->next;
                q = q->next;
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