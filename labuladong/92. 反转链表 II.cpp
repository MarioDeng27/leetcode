/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-21 21:42:26
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-21 21:42:46
 */
//92. 反转链表 II
class Solution
{
public:
    //方法1：自己的方法，还没正确实现
    /* pair<ListNode *, ListNode *> reverseCore(ListNode *begin, ListNode *end)
    {
        ListNode *pre;
        ListNode *cur;
        ListNode *next;
        cur = begin;
        while (cur != end->next)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {end, begin};
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int i = 0;
        ListNode *cur = head;
        ListNode *pre;
        ListNode *begin;
        ListNode *end;
        ListNode *next;
        ListNode *prebegin;
        ListNode *nextend;
        while (cur)
        {
            i++;
            if (i == left)
            {
                begin = cur;
                prebegin = pre;
            }
            if (i == right)
            {
                end = cur;
                nextend = cur->next;
                break;
            }
            next = cur->next;
            pre = cur;
            cur = next;
        }
        auto temp = reverseCore(begin, end);
        prebegin->next = temp.first;
        temp.second->next = nextend;
        return head;
    } */
    //方法2：递归实现，参考labuladong解法
    ListNode *next = nullptr;
    ListNode *reverseBeginN(ListNode *head, int N)
    {
        if (N == 1)
        {
            next = head->next;
            return head;
        }
        ListNode *last = reverseBeginN(head->next, N - 1);
        head->next->next = head;
        head->next = next;
        return last;
    }
    ListNode *reverseBetween2(ListNode *head, int left, int right)
    {
        if (left == 1)
            return reverseBeginN(head, right);
        ListNode *last = reverseBetween2(head->next, left - 1, right - 1);
        head->next = last;
        return head;
    }
};