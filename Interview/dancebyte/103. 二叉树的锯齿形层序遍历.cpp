/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-03 14:27:36
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-03 14:27:38
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        stack<TreeNode *> lStack;
        stack<TreeNode *> rStack;
        bool isleft = true;
        lStack.push(root);
        while (!lStack.empty() || !rStack.empty())
        {
            vector<int> track;
            if (isleft)
            {
                int size = lStack.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *p = lStack.top();
                    lStack.pop();
                    track.push_back(p->val);
                    if (p->left != nullptr)
                        rStack.push(p->left);
                    if (p->right != nullptr)
                        rStack.push(p->right);
                }
            }
            else
            {
                int size = rStack.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *p = rStack.top();
                    rStack.pop();
                    track.push_back(p->val);
                    if (p->right != nullptr)
                        lStack.push(p->right);
                    if (p->left != nullptr)
                        lStack.push(p->left);
                }
            }
            isleft = !isleft;
            res.push_back(track);
        }
        return res;
    }
};