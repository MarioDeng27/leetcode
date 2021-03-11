/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 21:04:10
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-01 21:10:39
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *pSlow = head;
        ListNode *pFast = head->next;
        ListNode *MeetingNode = nullptr;
        while (pFast != nullptr && pSlow != nullptr)
        {
            if (pFast == pSlow)
            {
                MeetingNode = pFast;
                break;
            }
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast != nullptr)
                pFast = pFast->next;
        }

        if (MeetingNode == nullptr)
            return nullptr;
        int nodesInloop = 1;
        ListNode *pNode = MeetingNode;
        while (pNode->next != MeetingNode)
        {
            nodesInloop++;
            pNode = pNode->next;
        }
        pNode = head;
        for (int i = 0; i < nodesInloop; i++)
        {
            pNode = pNode->next;
        }
        ListNode *pNode2 = head;
        while (pNode2 != pNode)
        {
            pNode = pNode->next;
            pNode2 = pNode2->next;
        }
        return pNode;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *pSlow = head;
        ListNode *pFast = head;
        while (pFast != nullptr)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast == nullptr)
                return nullptr;
            pFast = pFast->next;
            if (pSlow == pFast)
            {
                ListNode *pNode = head;
                while (pNode != pSlow)
                {
                    pNode = pNode->next;
                    pSlow = pSlow->next;
                }
                return pNode;
            }
        }
        return nullptr;
    }
};
