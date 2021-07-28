/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-28 20:34:40
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-28 20:34:40
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-28 20:34:40
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-28 20:34:40
 */
class Solution
{
public:
    int sum = 0;
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        traverse(root);
        return root;
    }
};