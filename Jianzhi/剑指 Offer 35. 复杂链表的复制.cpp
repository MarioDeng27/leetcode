/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-27 17:49:04
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-27 17:49:07
 */
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        map<Node *, Node *> m;
        Node *curr = head;
        Node *cloneHead = new Node(curr->val);
        m[head] = cloneHead;

        Node *cloneNode = cloneHead;
        curr = curr->next;
        while (curr)
        {
            Node *tmp = new Node(curr->val);
            cloneNode->next = tmp;
            m[curr] = tmp;
            curr = curr->next;
            cloneNode = tmp;
        }
        curr = head;
        cloneNode = cloneHead;
        while (curr)
        {
            cloneNode->random = m[curr->random];
            curr = curr->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};