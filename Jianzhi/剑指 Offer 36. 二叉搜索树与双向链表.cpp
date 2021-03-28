/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-28 13:19:41
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-28 13:20:02
 */
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
/*
自己根据剑指offer改变的，关键是要有一个先驱节点pre，这个是当前节点curr的前面一个
pre->right = curr
curr->left = pre
pre = curr
判断一下pre是否为空的情况
*/
class Solution
{
public:
    Node *LastNodeInList = nullptr;
    int cnt = 0;
    Node *BeginNodeInList = nullptr;
    void dfs(Node *root)
    {
        if (root == nullptr)
            return;
        Node *curr = root;
        if (curr->left != nullptr)
            dfs(root->left);
        if (cnt == 0)
        {
            BeginNodeInList = curr;
            cnt++;
        }
        curr->left = LastNodeInList;
        if (LastNodeInList != nullptr)
            LastNodeInList->right = curr;
        LastNodeInList = curr;
        if (curr->right != nullptr)
            dfs(root->right);
    }
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        BeginNodeInList->left = LastNodeInList;
        LastNodeInList->right = BeginNodeInList;
        return BeginNodeInList;
    }
};

/*
leecode精选答案
*/
class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *pre, *head;
    void dfs(Node *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};
