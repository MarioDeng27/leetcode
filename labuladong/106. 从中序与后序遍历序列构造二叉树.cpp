/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 17:40:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 17:40:37
 */
class Solution
{
public:
    TreeNode *build(vector<int> &inorder, int in_left, int in_right, vector<int> &postorder, int post_left, int post_right)
    {
        if (in_left > in_right || post_left > post_right)
            return nullptr;
        int rootVal = postorder[post_right];
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
        root->left = build(inorder, in_left, index - 1, postorder, post_left, post_left + leftsize - 1);
        root->right = build(inorder, index + 1, in_right, postorder, post_left + leftsize, post_right - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};