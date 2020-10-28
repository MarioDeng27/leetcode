class Solution
{
public:
    vector<int> vec;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        vec.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        dfs(root);
        sort(vec.begin(), vec.end());
        int res = INT_MAX;
        for (int i = 0; i < vec.size() - 1; i++)
            res = min(res, vec[i + 1] - vec[i]);
        return res;
    }
};
/* 
在二叉搜索树中，中序遍历会将树中节点按数值大小顺序输出。只需要遍历计算相邻数的差值，取其中最小的就可以了。
 */
class Solution
{
public:
    int res;
    int prev;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;

        dfs(root->left);
        if (prev != -1)
            res = min(res, root->val - prev);
        prev = root->val;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        res = INT_MAX;
        prev = -1;
        dfs(root);
        return res;
    }
};