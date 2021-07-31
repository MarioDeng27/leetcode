/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-01 00:29:24
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-01 00:29:44
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else //root->val == key
        {
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            else if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            else
            {
                TreeNode *minNode = getRightMinNode(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }
        }
        return root;
    }
    TreeNode *getRightMinNode(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
};

//BST删除节点模板框架
TreeNode deleteNode(TreeNode root, int key)
{
    if (root == null)
        return null;
    if (root.val == key)
    {
        // 这两个 if 把情况 1 和 2 都正确处理了
        if (root.left == null)
            return root.right;
        if (root.right == null)
            return root.left;
        // 处理情况 3
        TreeNode minNode = getMin(root.right);
        root.val = minNode.val;
        root.right = deleteNode(root.right, minNode.val);
    }
    else if (root.val > key)
    {
        root.left = deleteNode(root.left, key);
    }
    else if (root.val < key)
    {
        root.right = deleteNode(root.right, key);
    }
    return root;
}

TreeNode getMin(TreeNode node)
{
    // BST 最左边的就是最小的
    while (node.left != null)
        node = node.left;
    return node;
}