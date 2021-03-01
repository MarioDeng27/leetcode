/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 20:32:56
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-01 20:32:57
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *pSlow = head->next;
        if (pSlow == nullptr)
            return false;
        ListNode *pFast = pSlow->next;
        while (pFast != nullptr && pSlow != nullptr)
        {
            if (pFast == pSlow)
                return true;
            pSlow = pSlow->next;

            pFast = pFast->next;
            if (pFast != nullptr)
                pFast = pFast->next;
        }
        return false;
    }
};