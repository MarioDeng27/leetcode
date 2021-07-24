/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 15:54:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 15:54:43
 */

// 方法1：找到链表中间点的后半段，反转然后和前面的链表逐一进行比较
class Solution
{
public:
    // 1->2->2->3->2->2->1
    // fast != nullptr
    //1->2->3->3->2->1
    // fast == nullptr
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr)
            slow = slow->next;
        ListNode *last = reverseCore1(slow);
        while (last)
        {
            if (head->val != last->val)
                return false;
            head = head->next;
            last = last->next;
        }
        return true;
    }
    ListNode *reverseCore(ListNode *p)
    {
        if (p == nullptr || p->next == nullptr)
            return p;
        ListNode *last = reverseCore(p->next);
        p->next->next = p;
        p->next = nullptr;
        return last;
    }
    ListNode *reverseCore1(ListNode *p)
    {
        ListNode *pre = nullptr;
        ListNode *cur = p;
        ListNode *next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


//方法2：通过递归找到链表最后一个，然后通过递归函数调用的顺序逐一和前面的点进行比较
class Solution
{
public:
    // 1 2 2 1    -    1 2 2 3 2 2 1
    ListNode *left;
    bool core(ListNode *right)
    {
        if (right == nullptr)
            return true;
        bool flag = core(right->next);
        flag = flag && (left->val == right->val);
        left = left->next;
        return flag;
    }
    bool isPalindrome(ListNode *head)
    {
        left = head;
        return core(head);
    }
};
