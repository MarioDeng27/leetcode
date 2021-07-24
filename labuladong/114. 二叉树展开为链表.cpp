/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 16:47:45
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 16:48:05
 */
/*
    1. 先将root的左子树和右子树摊平
    2. 将摊平的右子树挂到左子树最下端（左子树摊平后的最后一个节点的右边）
    3. 将左子树挂到root的右边，并将root的左边变为nullptr

    注意：要考虑root左边为nullptr的特殊情况，即直接将root的右子树摊平即可完成当前节点的摊平
*/
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode *p = root->left;
        if (p == nullptr)
            return;
        root->left = nullptr;
        while (p->right)
            p = p->right;
        p->right = right;
        root->right = left;
    }
};
/*
    1. 将root的左右子树摊平
    2. 将摊平后的左子树挂到root的右边，并将root的左边变为nullptr
    3. 将root的右子树挂到root现在右边（之前左子树的最右边），关键这里的p一开始是指向root的
*/
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->right = left;
        root->left = nullptr;
        TreeNode *p = root;
        while (p->right)
            p = p->right;
        p->right = right;
    }
};