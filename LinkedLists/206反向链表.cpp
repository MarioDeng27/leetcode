#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
    迭代法:
    循环里分两段,前一段主要就是为了让当前节点指向它前一节点,后一段主要是为了让所保存的指针向后推移
    cur:当前节点； pre:用于保存cur节点的前一节点；nexttemp主要是用于保存cur节点的后一节点
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = NULL; //很关键
        ListNode *nexttemp = NULL;
        while (cur != NULL)
        {
            //前一段
            nexttemp = cur->next;
            cur->next = pre;
            //后一段
            pre = cur;
            cur = nexttemp;
        }
        return pre;
    }
};

/*
    https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
    递归法:
    让程序一直递归到找到最后一个节点,其next 必定指向NULL,在本次递归次序里对它不进行任何操作,相当于保存了它,直接返回
    再倒数第二个递归次序里让head就是当前节点,倒数第二个节点,让它对它后面的那个节点进行操作,让它后面的节点就是最后的节点指向本身
    就相当于,每次递归次序里都是本身节点对它后一节点的操作
    然后在某次递归次序里,比如倒数第三次里,这时的当前节点上倒数第三个几点,它是对倒数第二个节点进行操作的,但是不用考虑最后一节点,因为它已经操作过里
    只需要慢慢返回递归次序,它就慢慢的往前回里,每次都让后一节点的next指向本身
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL; //很关键,让第一个节点的next指向NULL
        return p;
    }
};