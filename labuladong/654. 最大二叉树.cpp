/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 17:15:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 17:15:15
 */
class Solution
{
public:
    TreeNode *build(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int maxVal = nums[left];
        int maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(maxVal);
        root->left = build(nums, left, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};