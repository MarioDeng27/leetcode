#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* 
    不考虑该树是二叉搜索树，直接通过递归前序遍历的方法找到与val对应的那个节点
 */
class Solution
{
public:
    TreeNode *res = NULL;
    void preOder(TreeNode *p, int val)
    {
        if (p == NULL)
            return;
        if (p->val == val)
        {
            res = p;
        }
        preOder(p->left, val);
        preOder(p->right, val);
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        preOder(root, val);
        return res;
    }
};

/* 
    不考虑该树是二叉搜索树，直接通过迭代前序遍历的方法找到与val对应的那个节点
 */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *p = NULL;
        while (!st.empty())
        {
            p = st.top();
            st.pop();
            if (p->val == val)
                return p;
            if (p->right != NULL)
            {
                st.push(p->right);
            }
            if (p->left != NULL)
            {
                st.push(p->left);
            }
        }
        return NULL;
    }
};

/* 
    考虑该树是二叉搜索树:每个节点都大于左子树上任意一个节点的值，小于右子树上任意一个节点的值
    直接通过递归前序遍历的方法找到与val对应的那个节点
 */

class Solution
{
public:
    TreeNode *res = NULL;
    void preOder(TreeNode *p, int val)
    {
        if (p == NULL)
            return;
        if (p->val == val)
        {
            res = p;
        }
        else if (p->val > val)
            preOder(p->left, val);
        else
            preOder(p->right, val);
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        preOder(root, val);
        return res;
    }
};

/* 
    自己的想法
    考虑该树是二叉搜索树:每个节点都大于左子树上任意一个节点的值，小于右子树上任意一个节点的值
    直接通过迭代前序遍历的方法找到与val对应的那个节点
 */

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return NULL;
        TreeNode *p = root;
        while (p)
        {
            if (p->val == val)
                return p;
            else if (p->val > val)
                p = p->left;
            else
                p = p->right;
        }
        return NULL;
    }
};

/* 
    官方：
    考虑该树是二叉搜索树:每个节点都大于左子树上任意一个节点的值，小于右子树上任意一个节点的值
    直接通过迭代前序遍历的方法找到与val对应的那个节点
 */

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL && val != root->val)
            root = val < root->val ? root->left : root->right;
        return root;
    }
};