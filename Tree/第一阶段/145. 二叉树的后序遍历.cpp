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
    通用模板实现迭代后序遍历，只需改最后的else里面三条语句的顺序即可，
    因为stack栈先进后出的特点，所以else里面要先把中间节点放进去，左节点最后放进去．
*/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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
                st.push(make_pair(p, true));
                st.push(make_pair(p->right, false));
                st.push(make_pair(p->left, false));
            }
        }
        return vec;
    }
};

/*
    递归后序遍历实
*/
class Solution
{
public:
    vector<int> vec;
    void postOder(TreeNode *p)
    {
        if (p == NULL)
            return;
        postOder(p->left);
        postOder(p->right);
        vec.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        postOder(root);
        return vec;
    }
};

/* 
    迭代实现，不具备通用性，使用了一个前驱节点来判断是否为当前节点的右孩子节点
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> st;
        TreeNode *p = root;
        TreeNode *prev = NULL;
        while (p != NULL || !st.empty())
        {
            //如果p一直都有左孩子节点就一直循环放入栈，直到无左孩子节点的节点作为最后一个放入栈
            while (p != NULL)
            {
                st.push(p);
                p = p->left;
            }
            //将栈中第一个元素弹出栈，即整个树中最左边的节点
            p = st.top();
            st.pop();
            //一直到p没有右孩子节点或者p的右孩子节点等于p的前驱节点，才让程序对当前节点进行操作，即放入数组中
            //并且让前驱节点变成当前节点，作为下一个弹出栈的前驱节点，然后当前节点p = NULL
            //p->right == prev主要是为了判断prev是不是p的右孩子，如果不是肯定是p的左孩子，画个图就知道了
            if (p->right == NULL || p->right == prev)
            {
                res.push_back(p->val);
                prev = p;
                p = NULL;
            }
            //若p有右孩子且右孩子和前驱节点不是同一个则再次将p压回栈内
            //让当前节点p指向p的右孩子
            else
            {
                st.push(p);
                p = p->right;
            }
        }
        return res;
    }
};
