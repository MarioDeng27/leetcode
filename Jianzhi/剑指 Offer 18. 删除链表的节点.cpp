/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 16:49:18
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 16:49:19
 */
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = head;
        ListNode *pre = dummy;
        while (curr)
        {
            if (curr->val == val)
            {
                pre->next = curr->next;
                return dummy->next;
            }
            pre = curr;
            curr = curr->next;
        }
        return nullptr;
    }
};