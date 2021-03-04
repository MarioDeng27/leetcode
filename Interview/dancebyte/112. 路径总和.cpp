/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-03 13:19:00
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-03 13:36:11
 */
//DFS
class Solution
{
public:
    int target;
    bool res = false;
    void dfs(TreeNode *node, int sum)
    {
        if (res == true)
            return;

        sum += node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum == target)
                res = true;
        }
        if (node->left != nullptr)
            dfs(node->left, sum);
        if (node->right != nullptr)
            dfs(node->right, sum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        target = targetSum;
        dfs(root, 0);
        return res;
    }
};
//BFS
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        queue<TreeNode *> qt;
        queue<int> qs;
        qt.push(root);
        qs.push(root->val);

        while (!qt.empty())
        {
            int size = qt.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *p = qt.front();
                int val = qs.front();
                qt.pop();
                qs.pop();
                if (p->left == nullptr && p->right == nullptr && val == targetSum)
                    return true;
                if (p->left != nullptr)
                {
                    qt.push(p->left);
                    qs.push(p->left->val + val);
                }
                if (p->right != nullptr)
                {
                    qt.push(p->right);
                    qs.push(p->right->val + val);
                }
            }
        }
        return false;
    }
};