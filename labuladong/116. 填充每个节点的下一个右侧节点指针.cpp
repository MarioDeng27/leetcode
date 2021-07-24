/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-24 16:30:53
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-24 16:31:13
 */
class Solution
{
public:
    void connectCore(Node *left, Node *right)
    {
        if (left == nullptr || right == nullptr)
            return;
        left->next = right;
        connectCore(left->left, left->right);
        connectCore(right->left, right->right);
        connectCore(left->right, right->left);
    }
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        connectCore(root->left, root->right);
        return root;
    }
};