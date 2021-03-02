/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 19:31:04
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 19:46:41
 */
class Solution
{
public:
    pair<ListNode *, ListNode *> reverseList(ListNode *head, ListNode *tail)
    {
        ListNode *pNode = head;
        ListNode *pNext = nullptr;
        ListNode *pPrev = nullptr;
        while (pPrev != tail)
        {
            pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return {tail, head};
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (k == 1)
            return head;

        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *pPrev = preHead;

        while (head != nullptr)
        {
            ListNode *tail = pPrev;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (tail == nullptr)
                    return preHead->next;
            }
            ListNode *pNext = tail->next;
            auto result = reverseList(head, tail);

            head = result.first;
            tail = result.second;

            pPrev->next = head;
            tail->next = pNext;
            pPrev = tail;
            head = tail->next;
        }
        return preHead->next;
    }
};

class Solution
{
public:
    //输入一个链表的头节点和尾节点，输出反转链表后新的头节点和尾节点
    pair<ListNode *, ListNode *> reverseList(ListNode *head, ListNode *tail)
    {
        ListNode *pre = nullptr;
        ListNode *pNode = head;
        while (pre != tail)
        {
            ListNode *next = pNode->next;
            pNode->next = pre;
            pre = pNode;
            pNode = next;
        }
        return {tail, head};
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while (head != nullptr)
        {
            //让尾节点先赋值为前驱节点，这样往后K次就是真正的子链表的尾部
            ListNode *tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                //若是发现尾节点到全部链表的尾部的后面，则表示剩余节点不足K个，故可以不反转直接输出结果
                if (tail == nullptr)
                    return dummy->next;
            }
            ListNode *next = tail->next;
            auto result = reverseList(head, tail);
            head = result.first;
            tail = result.second;

            //子链表反转后，与前后部分链表节点连接上
            pre->next = head;
            tail->next = next;
            //连接上后，选取新的子链表的头和头的前置节点
            pre = tail;
            head = next;
        }
        return dummy->next;
    }
};