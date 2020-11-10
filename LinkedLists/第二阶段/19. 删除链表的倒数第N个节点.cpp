/*
    先求出列表总长度len
    然后给列表首节点前加上哑结点,则遍历len-n次就可以找到要删除节点的前驱节点
    最终答案就是哑结点的指针域,即哑结点后面一个节点的地址

*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        ListNode *p = head;
        while (p)
        {
            len++;
            p = p->next;
        }
        ListNode *dummy = new ListNode(0, head);
        p = dummy;
        int cnt = len - n;
        //找到要删除元素的前一个节点,因为加了哑结点,所以len-n次循环就会找到要删除节点的前驱节点
        while (cnt--)
        {
            p = p->next;
        }
        p->next = p->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
/*
    用栈实现
    首先创建首节点前一个节点的哑结点,并将包含哑结点的整个队列加入到一个栈中
    循环n次出栈,第n次刚好把要删除的节点给出栈了,然后栈顶元素top就是指要删除元素的前驱节点.
*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        stack<ListNode *> st;
        ListNode *dummy = new ListNode(0, head);
        ListNode *p = dummy;
        while (p)
        {
            st.push(p);
            p = p->next;
        }
        while (n--)
        {
            st.pop();
        }
        ListNode *prev = st.top();
        prev->next = prev->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
/*
    快慢指针
    关键是找到要删除元素的前一个节点prev
    让快指针比慢指针快n+1个节点
    那么如果这时快指针和慢指针同步向后推进,当快指针访问到空指针时,慢指针可以达到prev
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i <= n; i++)
            fast = fast->next;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};