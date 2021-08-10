/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-10 19:02:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-10 19:23:21
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;
        return nullptr;
    }
};

class Solution
{
public:
    set<TreeNode *> myset;
    bool dfs(TreeNode *root, TreeNode *p)
    {
        if (root == nullptr)
            return false;
        if (root == p)
            return true;
        bool left = dfs(root->left, p);
        bool right = dfs(root->right, p);
        if (left || right)
            myset.insert(root);
        return left || right;
    }
    bool isfound = false;
    TreeNode *lca = nullptr;
    bool dfs2(TreeNode *root, TreeNode *p)
    {
        if (root == nullptr)
            return false;
        if (root == p)
        {
            if (!isfound && myset.count(root) != 0)
            {
                isfound = true;
                lca = root;
            }
            return true;
        }
        bool left = dfs2(root->left, p);
        bool right = dfs2(root->right, p);
        if ((left || right) && !isfound && myset.count(root) != 0)
        {
            isfound = true;
            lca = root;
        }
        return left || right;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        myset.insert(p);
        dfs(root, p);
        dfs2(root, q);
        return lca;
    }
};