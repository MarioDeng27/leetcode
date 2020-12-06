/*
 * @Description: https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-06 15:36:39
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-06 15:37:04
 */
/*
    BFS模板
*/

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        stack<vector<int>> st;
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> track;
            for (int i = 0; i < cnt; i++)
            {
                p = q.front();
                q.pop();
                track.push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);

                if (p->right != NULL)
                    q.push(p->right);
            }
            st.push(track);
        }
        vector<vector<int>> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};