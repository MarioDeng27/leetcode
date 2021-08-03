/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-03 20:13:39
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-03 20:20:53
 */
/*
    伪代码，未实现，因为traverse本身要递归，而isBST，findMax，findMin，getSum这些辅助函数全要递归，这样会使算法的复杂度大大增加
    可以进行后序遍历，这样要对当前节点进行处理时，就要计算 isBST，findMax，findMin，getSum 这4个值，维护好四个值就能解决这个问题，
    为什么要后序遍历，因为每个节点去维护四个值的时候，和前面的左右子树有关系，而且只要遍历一次就行
*/
class Solution
{
public:
    int res = INT_MIN;
    bool isBST(TreeNode *root) {}
    int findMax(TreeNode *root) {}
    int findMin(TreeNode *root) {}
    int getSum(TreeNode *root) {}
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        //如果左子树和右子树都是BST
        if (isBST(root->left) && isBST(root->right))
        {
            //找到左子树的最大值
            int leftMax = findMax(root->left);
            //找到右子树的最小值
            int rightMin = findMin(root->right);
            //若root的值在它们两个之间则以root为根的树也是BST,计算以它为根的树的总和，与res进行比较。如果不满足则继续向root的左子树和右子树进行遍历
            if (root->val > leftMax && root->val < rightMin)
            {
                int leftSum = getSum(root->left);
                int rightSum = getSum(root->right);
                res = max(res, leftSum + rightSum + root->val);
            }
        }
        traverse(root->left);
        traverse(root->right);
    }
    int maxSumBST(TreeNode *root)
    {
        traverse1(root);
        return res;
    }
};

//结合拉哥实现的代码
class Solution
{
public:
    int res = 0 /* INT_MIN */;
    // isBST,minVal,maxVal,sum
    // 0, 1, 2, 3
    vector<int> traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {1, INT_MAX, INT_MIN, 0};
        }
        auto left = traverse(root->left);
        auto right = traverse(root->right);
        int isBST = 0;
        int minVal = min(left[1], root->val);
        int maxVal = max(right[2], root->val);
        int sum = left[3] + right[3] + root->val;
        //只有确定以root为根的子树确实是BST则才试图去更新res，其他情况就是在维护4个值，因为后序遍历每次对root节点做处理的时候要依赖前面处理后的left和right 的值
        if (left[0] == 1 && right[0] == 1 && left[2] < root->val && right[1] > root->val)
        {
            isBST = 1;
            res = max(res, sum);
        }
        return {isBST, minVal, maxVal, sum};
    }
    int maxSumBST(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};
