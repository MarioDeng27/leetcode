/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 21:04:20
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 21:04:21
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (p->val > q->val)
        {
            TreeNode *t = p;
            p = q;
            q = t;
        }
        while (root != nullptr)
        {
            if ((root->val > p->val && root->val < q->val) || root->val == q->val || root->val == p->val)
                return root;
            if (root->val < p->val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};