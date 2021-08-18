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
//先序遍历：对于当前节点，先输出该节点，然后输出他的左孩子，最后输出他的右孩子。以上图为例，递归的过程如下：
//中序遍历：对于当前结点，先输出它的左孩子，然后输出该结点，最后输出它的右孩子。以上图为例：
//后序遍历：对于当前结点，先输出它的左孩子，然后输出它的右孩子，最后输出该结点。依旧以上图为例：
//https : //blog.csdn.net/young2415/article/details/87467118?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.baidujs&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.baidujs
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    通过迭代归实现前序遍历方法
    ＊＊＊＊＊很好的一种实现方法，可以和中序后序　用同样的模板
    else里的三条语句．谁先放进stack栈里，谁就是靠后操作，这里把当前的节点最后放入stack里，则应该最先输出
*/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
                st.push(make_pair(p->left, false));
                st.push(make_pair(p, true));
            }
        }
        return vec;
    }
};

/*
    通过迭代归实现中序遍历方法
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