/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-28 21:12:00
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-28 21:12:00
 */
class Solution
{
public:
    //dfs用来计算以root为起点的情况下，符合题意的种数
    int dfs(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        int res = 0;
        if (root->val == targetSum)
            res = 1;
        int a = dfs(root->left, targetSum - root->val);
        int b = dfs(root->right, targetSum - root->val);

        return res + a + b;
    }
    //pathsum用来计算，以root为根节点的树中符合题意的种数
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        int a = dfs(root, targetSum);
        int b = pathSum(root->left, targetSum);
        int c = pathSum(root->right, targetSum);
        return a + b + c;
    }
};
