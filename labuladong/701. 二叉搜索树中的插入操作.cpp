/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-01 00:02:47
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-01 00:03:08
 */
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};