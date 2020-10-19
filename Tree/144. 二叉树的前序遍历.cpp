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
    自己的想法：
    通过迭代法实现前序遍历
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *p = NULL;
        while (!st.empty())
        {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->right != NULL)
                st.push(p->right);
            if (p->left != NULL)
                st.push(p->left);
        }
        return res;
    }
};
/*
    自己的想法：
    通过迭递归实现前序遍历
*/
class Solution
{
public:
    vector<int> res;
    void preOder(TreeNode *p)
    {
        if (p == NULL)
            return;
        res.push_back(p->val);
        preOder(p->left);
        preOder(p->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        preOder(root);
        return res;
    }
};