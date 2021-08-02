/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-02 20:18:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-02 20:18:58
 */

class Solution
{
public:
    //返回min-max之间作为根节点的BST的数组，min对应一个BST,min+1对应一个BST。。。
    vector<TreeNode *> build(int min, int max)
    {
        vector<TreeNode *> res;
        if (min > max)
        {
            TreeNode *p = nullptr;
            res.push_back(p);
            return res;
        }
        for (int i = min; i <= max; i++)
        {
            vector<TreeNode *> left = build(min, i - 1);
            vector<TreeNode *> right = build(i + 1, max);
            for (auto p : left)
                for (auto q : right)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = p;
                    node->right = q;
                    res.push_back(node);
                }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return build(1, n);
    }
};

//官方模板
/*
步骤：
1、穷举 root 节点的所有可能。
2、递归构造出左右子树的所有合法 BST。
3、给 root 节点穷举所有左右子树的组合。
*/
/* 主函数 */
public
List<TreeNode> generateTrees(int n)
{
    if (n == 0)
        return new LinkedList<>();
    // 构造闭区间 [1, n] 组成的 BST
    return build(1, n);
}

/* 构造闭区间 [lo, hi] 组成的 BST */
List<TreeNode> build(int lo, int hi)
{
    List<TreeNode> res = new LinkedList<>();
    // base case
    if (lo > hi)
    {
        res.add(null);
        return res;
    }

    // 1、穷举 root 节点的所有可能。
    for (int i = lo; i <= hi; i++)
    {
        // 2、递归构造出左右子树的所有合法 BST。
        List<TreeNode> leftTree = build(lo, i - 1);
        List<TreeNode> rightTree = build(i + 1, hi);
        // 3、给 root 节点穷举所有左右子树的组合。
        for (TreeNode left : leftTree)
        {
            for (TreeNode right : rightTree)
            {
                // i 作为根节点 root 的值
                TreeNode root = new TreeNode(i);
                root.left = left;
                root.right = right;
                res.add(root);
            }
        }
    }

    return res;
}