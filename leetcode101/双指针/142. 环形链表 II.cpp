/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-03 18:22:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-03 18:22:34
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return nullptr;
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while (fast != slow)
        {
            if (fast && fast->next)
            {
                fast = fast->next->next;
            }
            else
            {
                return nullptr;
            }
            slow = slow->next;
        }
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        else
        {
            return nullptr;
        }
    }
};