/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-08 17:22:05
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-08 17:22:05
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        vector<int> res;
        while (!q.empty())
        {
            int cnt = q.size();
            int maxval = INT_MIN;
            for (int i = 0; i < cnt; i++)
            {
                p = q.front();
                q.pop();
                maxval = max(maxval, p->val);
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
            res.push_back(maxval);
        }
        return res;
    }
};