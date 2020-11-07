#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
//#include <multimap>
#include <cmath>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*递归法
    每一次递归调用都是为了从两个链表中对应遍历到的节点选出合适的节点作为当前节点（比较val值）
    如果在l1链表中遍历到了尾结点之后的那个NULL则，返回的是l2剩余没遍历的那些节点，反之l2
    所以先遍历到不能再遍历位置，相当于找到了最后的那个节点，然后通过比如l1->next = return ... 返回值逐步的连起来
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/*
    自己的方法：暴力法（迭代）
    思路很简单就不将了，主要一些细节得注意
    ListNode * p 可以用来保存 ListNode类型的对象的地址
    假设 q是保存名为m的节点当p = q时，p也保存了m节点的地址，所以对本身m进行各种操作，p和q不变，因为地址都还是原来的地址
    该ListNode结构体构成的指针必须进行初始化才能调用 -> 不然会报成nullptr
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(-1); //哑节点，它的next指向整个链表的头节点
        ListNode *prev;
        prev = head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                prev->next = p1;
                p1 = p1->next;
            }
            else
            {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }
        prev->next = p1 == NULL ? p2 : p1;
        return head->next;
    }
};