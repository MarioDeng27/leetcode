struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
    dfs中序遍历,然后通过比较当前节点和其前序节点的值,如果都是出现前序节点>当前节点的值,则整个结果为false
    那么中序遍历的遍历的第一个节点,就是树最左边的那个节点,的前序节点定为NULL,然后如果是NULL将前序节点赋值为p,然后开始往后遍历
*/
class Solution
{
public:
    void dfs(TreeNode *p, bool &isValid, TreeNode *&q)
    {
        if (p == NULL || isValid == false)
            return;
        dfs(p->left, isValid, q);
        if (q == NULL)
            q = p;
        else if (q->val >= p->val)
            isValid = false;
        else
            q = p;
        dfs(p->right, isValid, q);
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        bool isValid = true;
        TreeNode *tn = NULL;
        dfs(root, isValid, tn);
        return isValid;
    }
};
/*
    也是中序遍历,主要是找到最左边的节点,通过firstvisited这个标志为来判断是否是第一个节点
*/
class Solution
{
public:
    void dfs(TreeNode *p, bool &isValid, TreeNode *&q)
    {
        if (p == NULL || isValid == false)
            return;
        dfs(p->left, isValid, q);
        if (q == NULL)
            q = p;
        else if (q->val >= p->val)
            isValid = false;
        else
            q = p;
        dfs(p->right, isValid, q);
    }
    bool isValidBST(TreeNode *root)
    {
        stack<pair<TreeNode *, bool>> st;
        st.push({root, false});
        bool res = true;
        TreeNode *p;
        int temp = 0;
        bool visited;
        bool firstvisited = false;
        while (!st.empty() && res)
        {
            p = st.top().first;
            visited = st.top().second;
            st.pop();
            if (p == NULL)
                continue;
            else if (visited)
            {
                if (firstvisited == false)
                {
                    firstvisited = true;
                    temp = p->val;
                }
                else if (temp < p->val)
                    temp = p->val;
                else
                    res = false;
            }
            else
            {
                st.push({p->right, false});
                st.push({p, true});
                st.push({p->left, false});
            }
        }
        return res;
    }
};