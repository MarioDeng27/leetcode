#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
    自己的想法：
    通过迭递归实现中序遍历
*/
class Solution
{
public:
    vector<int> res;
    void inOrder(TreeNode *p)
    {
        if (p == NULL)
            return;
        inOrder(p->left);
        res.push_back(p->val);
        inOrder(p->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        inOrder(root);
        return res;
    }
};

/*
    自己的想法：
    通过迭代归实现中序遍历方法１
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> st;
        //st.push(root);
        TreeNode *p = root;
        while (true)
        {
            if (p != NULL)
            {
                st.push(p);
                p = p->left;
            }
            else if (!st.empty())
            {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};

/*
    自己的想法：
    通过迭代归实现中序遍历方法２
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p != NULL || !st.empty())
        {
            while (p != NULL)
            {
                st.push(p);
                p = p->left;
            }
            if (!st.empty())
            {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};

/*
    通过迭代归实现中序遍历方法3
    ＊＊＊＊＊很好的一种实现方法，可以和前序后序　用同样的模板
*/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<pair<TreeNode *, bool>> st;
        st.push(make_pair(root, false));
        bool visited;
        TreeNode *p = NULL;
        while (!st.empty())
        {
            p = st.top().first;
            visited = st.top().second;
            st.pop();
            if (p == NULL)
                continue;
            if (visited)
            {
                vec.push_back(p->val);
            }
            else
            {
                st.push(make_pair(p->right, false));
                st.push(make_pair(p, true));
                st.push(make_pair(p->left, false));
            }
        }
        return vec;
    }
};