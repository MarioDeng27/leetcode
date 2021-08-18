/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-20 14:33:33
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-20 14:33:48
 */
//自底向上递归
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1 || leftHeight == -1 || rightHeight == -1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (getHeight(root) == -1)
            return false;
        return true;
    }
};