//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans;
    int longestPath(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int maxValue = 0;
        int left = longestPath(root->left);
        int right = longestPath(root->right);
        //维护这个最大路径值ans
        //特殊情况，出现了倒V型，除此之外都是直线型，因为再上一层的节点与本节点相连和倒V型只是两个路径方向，后面根据ans会再次判断哪个大,因为倒V的出现，返回值并不能用ans来定，如果没倒V型，ans应该和当前节点的maxValue同步
        if (root->left != NULL && root->val == root->left->val && root->right != NULL && root->val == root->right->val)
        {
            ans = max(ans, left + right + 2);
        }

        if (root->left != NULL && root->val == root->left->val)
        {
            maxValue = max(maxValue, left + 1);
        }
        if (root->right != NULL && root->val == root->right->val)
        {
            maxValue = max(maxValue, right + 1);
        }
        ans = max(ans, maxValue);
        return maxValue;
    }

    int longestUnivaluePath(TreeNode *root)
    {
        ans = 0;
        longestPath(root);
        return ans;
    }
};