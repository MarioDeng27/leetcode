/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 15:34:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-01 15:34:48
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 != nullptr && l2 != nullptr)
        {
            ListNode *pHead = nullptr;
            if (l1->val > l2->val)
            {
                pHead = l2;
                pHead->next = mergeTwoLists(l1, l2->next);
            }
            else
            {
                pHead = l1;
                pHead->next = mergeTwoLists(l1->next, l2);
            }
            return pHead;
        }
        else if (l1 == nullptr)
        {
            return l2;
        }
        else
        {
            return l1;
        }
    }
};