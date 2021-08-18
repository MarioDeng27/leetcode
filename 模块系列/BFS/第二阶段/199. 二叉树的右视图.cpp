/*
 * @Description: https://leetcode-cn.com/problems/binary-tree-right-side-view/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-07 16:41:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-07 17:06:34
 */
//自己的想法
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        vector<int> res;
        while (!q.empty())
        {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++)
            {

                p = q.front();
                q.pop();
                if (i == cnt - 1)
                    res.push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
        }
        return res;
    }
};

//自己的想法dfs
class Solution
{
public:
    unordered_set<int> depthset;
    vector<int> res;
    void dfs(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return;
        if (depthset.find(depth) == depthset.end())
        {
            res.push_back(root->val);
            depthset.insert(depth);
        }
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};