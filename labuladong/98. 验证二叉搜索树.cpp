/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-28 21:03:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-28 21:10:46
 */

class Solution
{
public:
    /* 限定以 root 为根的子树节点必须满足 max.val > root.val > min.val */
    bool traverse(TreeNode *root, long long min, long long max)
    {
        if (root == nullptr)
            return true;
        // 若 root.val 不符合 max 和 min 的限制，说明不是合法 BST
        if (root->val >= max || root->val <= min)
            return false;
        // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
        bool flag1 = traverse(root->left, min, root->val);
        bool flag2 = traverse(root->right, root->val, max);
        return flag1 && flag2;
    }
    bool isValidBST(TreeNode *root)
    {
        return traverse(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
//方法2 中序遍历，若出现前一个数字比当前数字大于或者等于的情况则返回false
class Solution
{
public:
    long long pre = LONG_LONG_MIN;
    bool traverse(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool flag1 = traverse(root->left);
        if (pre >= root->val)
            return false;
        pre = root->val;
        bool flag2 = traverse(root->right);
        return flag1 && flag2;
    }
    bool isValidBST(TreeNode *root)
    {
        return traverse(root);
    }
};