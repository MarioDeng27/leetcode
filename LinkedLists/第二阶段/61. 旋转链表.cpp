class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return NULL;
        int len = 0;
        ListNode *p = head;
        ListNode *last;
        while (p)
        {
            len++;
            if (!p->next)
                last = p;
            p = p->next;
        }
        k = k % len;
        int cnt = len - k - 1;
        p = head;
        while (cnt--)
        {
            p = p->next;
        }
        last->next = head;
        ListNode *ans = p->next;
        p->next = NULL;
        return ans;
    }
};