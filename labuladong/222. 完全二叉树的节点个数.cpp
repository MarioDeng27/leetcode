/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-10 20:28:19
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-10 20:28:19
 */
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int hl = 0;
        int hr = 0;
        TreeNode *p = root;
        while (p)
        {
            hl++;
            p = p->left;
        }
        p = root;
        while (p)
        {
            hr++;
            p = p->right;
        }
        if (hl == hr)
            return pow(2, hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};