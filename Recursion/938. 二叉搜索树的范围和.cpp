/*
    DFS因为是二叉搜索树，则使用中序遍历，遍历的元素都是从小到大的
    只要是小于L的就pass去遍历下一个元素，只要满足大于等于L的进行再次比较是否小于等于R，如果小于等于R，则与sum相加
    如果大于R，则返回，不用去遍历后面的剩下元素，因为都比当前元素的值大，肯定不符合要求
*/
class Solution
{
public:
    int sum;
    int l;
    int r;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (root->val >= l)
        {
            if (root->val <= r)
                sum += root->val;
            else
                return;
        }
        dfs(root->right);
    }
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        sum = 0;
        l = L;
        r = R;
        dfs(root);
        return sum;
    }
};

//将树的每个节点的值放到一个数组里，然后排序搜索出符合条件的值加起来就可以了！