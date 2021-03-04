/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-03 13:50:07
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-03 13:50:08
 */
class Solution
{
public:
    int target;
    vector<vector<int>> res;
    void dfs(TreeNode *node, int sum, vector<int> track)
    {
        sum += node->val;
        track.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && sum == target)
        {
            res.push_back(track);
        }
        if (node->left != nullptr)
            dfs(node->left, sum, track);
        if (node->right != nullptr)
            dfs(node->right, sum, track);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return {};
        target = targetSum;
        dfs(root, 0, {});
        return res;
    }
};