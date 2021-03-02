/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 21:40:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 21:40:44
 */

//方法二：存储父节点
class Solution
{
public:
    map<int, TreeNode *> m;
    map<int, bool> visited;
    void dfs(TreeNode *node, TreeNode *parent)
    {
        if (node == nullptr)
            return;
        m[node->val] = parent;
        dfs(node->left, node);
        dfs(node->right, node);
    }
    void dfs1(TreeNode *node)
    {
        if (node->left != nullptr)
        {
            m[node->left->val] = node;
            dfs1(node->left);
        }
        if (node->right != nullptr)
        {
            m[node->right->val] = node;
            dfs1(node->right);
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        m[root->val] = nullptr;
        dfs1(root);

        while (p != nullptr)
        {
            visited[p->val] = true;
            p = m[p->val];
        }
        while (q != nullptr)
        {
            if (visited[q->val] == true)
            {
                return q;
            }
            q = m[q->val];
        }
        return nullptr;
    }
};