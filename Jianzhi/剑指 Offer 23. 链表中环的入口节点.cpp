/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 15:06:46
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 15:43:40
 */

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

#include <unordered_set>
class Solution
{
public:
    unordered_set<ListNode *> mySet;
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *curr = pHead;
        while (curr != nullptr)
        {
            if (mySet.count(curr) != 0)
                return curr;
            mySet.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};
//快慢指针
//原理推导有整理过，看印象笔记
class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *slow = pHead, *fast = pHead;
        while (fast != nullptr)
        {
            if (fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *curr = pHead;
                while (curr != slow)
                {
                    curr = curr->next;
                    slow = slow->next;
                }
                return curr;
            }
        }
        return nullptr;
    }
};
