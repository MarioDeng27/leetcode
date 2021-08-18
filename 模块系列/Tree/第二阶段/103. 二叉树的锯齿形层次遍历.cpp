//通过两个栈来实现BFS
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        st1.push(root);
        TreeNode *p;
        bool isleft = true;
        while (!st1.empty() || !st2.empty())
        {
            vector<int> vec;
            if (isleft)
            {
                int n = st1.size();
                for (int i = 0; i < n; i++)
                {
                    p = st1.top();
                    st1.pop();
                    vec.push_back(p->val);
                    if (p->left != NULL)
                        st2.push(p->left);
                    if (p->right != NULL)
                        st2.push(p->right);
                }
            }
            else
            {
                int n = st2.size();
                for (int i = 0; i < n; i++)
                {
                    p = st2.top();
                    st2.pop();
                    vec.push_back(p->val);
                    if (p->right != NULL)
                        st1.push(p->right);
                    if (p->left != NULL)
                        st1.push(p->left);
                }
            }
            isleft = !isleft;
            res.push_back(vec);
        }
        return res;
    }
};