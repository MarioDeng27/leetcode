#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
//#include <multimap>
#include <array>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/*
    BFS求解：
    第一个循环while循环的次数其实代表有几层
    而第二个循环的次数代表每一层的节点个数，并且把节点中有孩子的把其所有孩子放入q中
    最终只要计算第一个循环的次数就行了
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        int level = 0;
        queue<Node *> q;
        Node *p = NULL;
        q.push(root);
        while (!q.empty())
        {
            level++;
            int cnt = q.size();
            while (cnt--)
            {
                p = q.front();
                q.pop();
                if (!p->children.empty())
                {
                    for (auto c : p->children)
                        q.push(c);
                }
            }
        }
        return level;
    }
};

/*
    DFS递归
    定义一个map<int,int> mlevel ，第一个int表示节点的值，第二个int表示该节点位于第几层
    定义了一个dfs，参数有p和k，p代表当前节点，正准备去遍历其作为根节点的子树，k代表其在第几层
    每次遍历到该节点，先判断该节点是否为NULL，不为NULL则将其值val和层数k放入 mlevel中
    一直遍历完整个树

    最终主函数里，遍历mlevel中的k，取最大值 
*/

class Solution
{
public:
    map<int, int> mlevel;
    void dfs(Node *p, int k)
    {
        if (p == NULL)
        {
            return;
        }
        mlevel[p->val] = k;
        if (!p->children.empty())
        {
            for (auto c : p->children)
            {
                dfs(c, k + 1);
            }
        }
    }
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        dfs(root, 1);
        int maxlevel = 0;
        for (auto m : mlevel)
        {
            maxlevel = max(maxlevel, m.second);
        }
        return maxlevel;
    }
};

/*
   DFS递归优化版 
*/

class Solution
{
public:
    int maxlevel = 0;
    map<int, int> mlevel;
    void dfs(Node *p, int k)
    {
        if (p == NULL)
        {
            return;
        }
        maxlevel = max(maxlevel, k);
        if (!p->children.empty())
        {
            for (auto c : p->children)
            {
                dfs(c, k + 1);
            }
        }
    }
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        dfs(root, 1);

        return maxlevel;
    }
};

/*
    DFS迭代版
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;
        stack<pair<Node *, int>> st;
        st.push(pair<Node *, int>(root, 1));
        Node *p = NULL;
        int k = 0;
        int maxlevel = 0;
        while (!st.empty())
        {
            p = st.top().first;
            k = st.top().second;
            st.pop();
            if (!p->children.empty())
            {
                for (auto c : p->children)
                {
                    st.push(pair<Node *, int>(c, k + 1));
                }
            }
            maxlevel = max(maxlevel, k);
        }
        return maxlevel;
    }
};