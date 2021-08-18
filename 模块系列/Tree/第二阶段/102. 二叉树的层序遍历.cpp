//BFS实现，两种方法
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<pair<int, int>> vec;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        TreeNode *p;
        int level;
        while (!q.empty())
        {
            p = q.front().first;
            level = q.front().second;
            q.pop();
            vec.push_back({p->val, level});
            if (p->left != NULL)
                q.push({p->left, level + 1});
            if (p->right != NULL)
                q.push({p->right, level + 1});
        }
        vector<vector<int>> res(vec.back().second + 1);
        for (auto v : vec)
        {
            res[v.second].push_back(v.first);
        }
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push({root});
        TreeNode *p;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            for (int i = 0; i < n; i++)
            {
                p = q.front();
                q.pop();
                vec.push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};