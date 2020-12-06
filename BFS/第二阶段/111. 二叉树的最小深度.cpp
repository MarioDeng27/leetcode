/*
 * @Description: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-06 15:56:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-06 15:59:07
 */

/*
    BFS实现
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *p;
        int res = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            res++;
            for (int i = 0; i < cnt; i++)
            {
                p = q.front();
                q.pop();
                if (p->left == NULL && p->right == NULL)
                    return res;
                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
        }
        return res;
    }
};
/*
    DFS实现,将大问题变成若干小问题
    要知道根节点到叶子节点最短距离的个数,
    可以判断其左子节点到最短叶子节点的最短距离的个数 a
            其右子节点到最短叶子节点的最短距离的个数 b
    取 a,b较小值,less
    则最后值为less+1,1代表根节点
    然后一直递归
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int min_depth = INT_MAX;
        if (root->left != NULL)
            min_depth = min(minDepth(root->left), min_depth);
        if (root->right != NULL)
            min_depth = min(minDepth(root->right), min_depth);
        return min_depth + 1;
    }
};