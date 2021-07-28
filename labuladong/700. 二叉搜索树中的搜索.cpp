/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-28 21:14:47
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-28 21:14:47
 */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        return root;
    }
};