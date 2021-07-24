/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 17:29:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 17:29:03
 */
class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int pre_left, int pre_right, vector<int> &inorder, int in_left, int in_right)
    {
        if (pre_left > pre_right || in_left > in_right)
            return nullptr;
        int rootVal = preorder[pre_left];

        int index = in_left;
        for (int i = in_left; i <= in_right; i++)
        {
            if (inorder[i] == rootVal)
            {
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        int leftsize = index - in_left;
        root->left = build(preorder, pre_left + 1, pre_left + leftsize, inorder, in_left, index - 1);
        root->right = build(preorder, pre_left + leftsize + 1, pre_right, inorder, index + 1, in_right);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};