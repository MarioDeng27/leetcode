/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 17:22:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 17:23:51
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pNode = head;
        ListNode *pPrev = nullptr;
        ListNode *ReverseHead = nullptr;
        while (pNode != nullptr)
        {
            ListNode *pNext = pNode->next;
            if (pNext == nullptr)
                ReverseHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return ReverseHead;
    }
};