class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return findRoot(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    TreeNode *findRoot(vector<int> pre, int pLeft, int pRight, vector<int> vin, int vLeft, int vRight)
    {
        if (pLeft > pRight)
        {
            return nullptr;
        }
        int rootVal = pre[pLeft];
        TreeNode *root = new TreeNode(rootVal);
        for (int i = vLeft; i <= vRight; i++)
        {
            if (vin[i] == rootVal)
            {
                root->left = findRoot(pre, pLeft + 1, pLeft + i - vLeft, vin, vLeft, i - 1);
                root->right = findRoot(pre, pLeft + i - vLeft + 1, pRight, vin, i + 1, vRight);
                break;
            }
        }
        return root;
    }
};