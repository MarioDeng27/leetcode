/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-28 20:22:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-28 20:22:27
 */
class Solution
{
public:
    int index = 0;
    int K;
    int ans;
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        traverse(root->left);
        index++;
        if (index == K)
        {
            ans = root->val;
            return;
        }
        else
            traverse(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        K = k;
        traverse(root);
        return ans;
    }
};