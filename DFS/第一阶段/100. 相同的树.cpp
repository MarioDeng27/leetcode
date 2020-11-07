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
#include <set>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//同时比较
class Solution
{
public:
    bool flag = true;
    bool preOder(TreeNode *p, TreeNode *q)
    {
        bool flag = false;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        else if (p == NULL && q == NULL)
            return true;
        flag = (p->val == q->val) && (preOder(p->left, q->left)) && (preOder(p->right, q->right));
        return flag;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return preOder(p, q);
    }
};

//分开比较
class Solution
{
public:
    void preOder(TreeNode *p, vector<int> &vec)
    {
        if (p == NULL)
        {
            vec.push_back(NULL);
            return;
        }
        vec.push_back(p->val);
        preOder(p->left, vec);
        preOder(p->right, vec);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> pvec;
        vector<int> qvec;
        preOder(p, pvec);
        preOder(q, qvec);
        return pvec == qvec;
    }
};