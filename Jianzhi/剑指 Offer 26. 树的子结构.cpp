/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 22:00:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 22:00:35
 */
class Solution
{
public:
    bool isSubStructureCore(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return isSubStructureCore(A->left, B->left) && isSubStructureCore(A->right, B->right);
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        bool res = false;
        if (A != nullptr && B != nullptr)
        {
            //如果A和B的根节点值相同就继续往下找，通过core
            if (A->val == B->val)
                res = isSubStructureCore(A, B);
            //如果当前根不行，就开始从左子树和B以及右子树和B进行判断
            if (res == false)
                res = isSubStructure(A->left, B);
            if (res == false)
                res = isSubStructure(A->right, B);
        }
        return res;
    }
};