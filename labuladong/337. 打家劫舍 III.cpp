/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 11:09:46
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 11:22:10
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 11:09:46
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 11:09:46
 */
//方法1：
class Solution
{
public:
    //偷以root为根节点的两种情况的最大金额{包含root, 不包含root}
    vector<int> robCore(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        auto left = robCore(root->left);
        auto right = robCore(root->right);
        //如果包含root，则root的左右节点必定不能包含，所以选索引为1的值
        int done = root->val + left[1] + right[1];
        //如果不包含root，则这里从left中找到最大利润的情况 + 从right中找到最大利润的情况，因为root不包含，则从left和right中选任何一个都不会影响
        int notdone = max(left[0], left[1]) + max(right[0], right[1]);
        return {done, notdone};
    }

    int rob(TreeNode *root)
    {
        auto res = robCore(root);
        return max(res[0], res[1]);
    }
};

//方法2：
class Solution
{
public:
    unordered_map<TreeNode *, int> mem;
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (mem.count(root) > 0)
            return mem[root];

        int done = root->val + (root->left != nullptr ? rob(root->left->right) + rob(root->left->left) : 0) + (root->right != nullptr ? rob(root->right->left) + rob(root->right->right) : 0);
        int notdone = rob(root->left) + rob(root->right);

        int res = max(done, notdone);
        mem[root] = res;

        return res;
    }
};
