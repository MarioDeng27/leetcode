
/*
    主要解决思想是：通过两个指针，对称遍历同一颗树，只要每次值相等就是对称

*/
/*
    DFS:迭代法1
*/
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> stleft;
        stack<TreeNode *> stright;
        stleft.push(root);
        stright.push(root);
        TreeNode *p = NULL;
        TreeNode *q = NULL;
        while (!stleft.empty() && !stright.empty())
        {
            p = stleft.top();
            q = stright.top();
            stleft.pop();
            stright.pop();
            if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if (p != NULL && q != NULL)
            {
                if (p->val == q->val)
                {
                    stleft.push(p->right);
                    stleft.push(p->left);
                    stright.push(q->left);
                    stright.push(q->right);
                }
                else
                    return false;
            }
        }
        return true;
    }
};
/*
    DFS:递归法
*/
class Solution
{
public:
    vector<int> vectree;
    int level = 0;
    bool dfs(TreeNode *p, TreeNode *q)
    {
        bool flag = false;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        else if (p == NULL && q == NULL)
            return true;
        flag = (p->val == q->val) && (dfs(p->left, q->right)) && (dfs(p->right, q->left));
        return flag;
    }
    bool isSymmetric(TreeNode *root)
    {

        return dfs(root, root);
    }
};