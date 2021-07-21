/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-21 21:44:22
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-21 21:44:23
 */
class Solution
{
public:
    ListNode *reverseCore(ListNode *first, ListNode *last)
    {
        ListNode *pre, *cur, *next;
        cur = first;
        while (cur != last)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur, *next;
        cur = head;
        for (int i = 0; i < k; i++)
        {
            if (cur == nullptr)
                return head;
            next = cur->next;
            cur = next;
        }
        ListNode *last = reverseCore(head, next);
        head->next = reverseKGroup(next, k);
        return last;
    }
};