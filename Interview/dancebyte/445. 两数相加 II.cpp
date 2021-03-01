/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 17:29:20
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-01 17:38:12
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isjw = false;
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1, st2, st3;
        while (l1 != nullptr)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int op1, op2, sum;
        while (!st1.empty() && !st2.empty())
        {
            op1 = st1.top();
            st1.pop();
            op2 = st2.top();
            st2.pop();
            sum = op1 + op2;
            if (isjw)
                sum++;
            st3.push(sum % 10);
            if (sum > 9)
            {
                isjw = true;
            }
            else
            {
                isjw = false;
            }
        }
        while (!st1.empty())
        {
            op1 = st1.top();
            st1.pop();
            sum = op1;
            if (isjw)
                sum++;
            st3.push(sum % 10);
            if (sum > 9)
            {
                isjw = true;
            }
            else
            {
                isjw = false;
            }
        }
        while (!st2.empty())
        {
            op2 = st2.top();
            st2.pop();
            sum = op2;
            if (isjw)
                sum++;
            st3.push(sum % 10);
            if (sum > 9)
            {
                isjw = true;
            }
            else
            {
                isjw = false;
            }
        }
        if (isjw)
            st3.push(1);
        int p;
        ListNode *pHead = new ListNode(0);
        ListNode *curr = pHead;
        while (!st3.empty())
        {
            p = st3.top();
            st3.pop();
            ListNode *pNode = new ListNode(p);
            curr->next = pNode;
            curr = pNode;
        }
        return pHead->next;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1, st2;
        while (l1 != nullptr)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int op1, op2, carry = 0, sum;
        ListNode *ans = nullptr;
        while (!st1.empty() || !st2.empty() || carry == 1)
        {
            op1 = st1.empty() ? 0 : st1.top();
            op2 = st2.empty() ? 0 : st2.top();
            if (!st1.empty())
                st1.pop();
            if (!st2.empty())
                st2.pop();
            sum = op1 + op2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            auto currnode = new ListNode(sum);
            currnode->next = ans;
            ans = currnode;
        }
        return ans;
    }
};