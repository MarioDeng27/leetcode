#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

//BFS　求　树中每个元素值的深度

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> level(TreeNode *root)
{
    vector<vector<int>> levelList;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        vector<int> nodevalList;
        while (count--)
        {
            TreeNode *p = q.front();
            q.pop();
            nodevalList.push_back(p->val);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        levelList.push_back(nodevalList);
    }
    return levelList;
}

/*
    BFS法
    利用BFS遍历树中每个节点，出现下列情况必定表示元素若为ｘ，ｙ必定不是堂兄弟
    1.若一个结点的左孩子和右孩子的值刚好是ｘ和ｙ或者是ｙ和ｘ，则必定不是堂兄弟，返回false
    2.若在同一深度ｋ只找到一个节点的值满足ｘ或ｙ，则这两节点必定不是堂兄弟，返回false
    其余情况都为true

    BFS 中第一个循环　while (!q.empty())
    每一次遍历都代表某一深度或者某一层　
    
    BFS 中第二个循环　while (count--)
    每次遍历都是同一层的几个节点取遍历各自的左右孩子
    ｑ总是让队列中第一个元素出队作为父节点访问它的两个个孩子，分别让它们进入队列，已被后面轮到它们取遍历孩子

    这里设置了一个flag
    首先将情况１发生时，返回false
    再者，在第二个循环中，遍历同一层每个节点时，如果出现它们的孩子符合ｘ或ｙ则让flag　＋　１，若找到两个节点的各自的其中一个孩子都符合ｘ和ｙ则视为堂兄弟
*/
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left && p->right && ((p->left->val == x && p->right->val == y) || (p->left->val == y && p->right->val == x)))
                    return false;
                //nodevalList.push_back(p->val);
                if (p->left)
                {

                    q.push(p->left);
                    if (p->left->val == x || p->left->val == y)
                        flag++;
                }
                if (p->right)
                {
                    q.push(p->right);
                    if (p->right->val == x || p->right->val == y)
                        flag++;
                }
            }
            if (flag == 2)
                return true;
            if (flag == 1)
                return false;
        }
        return false;
    }
};

/*
    DFS法
    在类内创建了两个变量共享数据信息，mlevel 和　mparnt
    利用前序遍序将整个树的所有节点访问了一次，将val 和　层数ｋ以及　节点的父节点地址都保存到map里
*/
class Solution
{
public:
    map<int, int> mlevel;        //int,int分别表示　值作为关键词，层数作为对应值
    map<int, TreeNode *> mparnt; //int,TreeNode*分别表示　值作为关键词，该值对应的节点的父节点　作为对应值

    void preorder(TreeNode *root, TreeNode *parnt, int k)
    {
        if (!root)
            return;
        mlevel[root->val] = k;
        mparnt[root->val] = parnt;
        parnt = root;
        preorder(root->left, parnt, k + 1);
        preorder(root->right, parnt, k + 1);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        preorder(root, NULL, 0);
        if (mlevel[x] != mlevel[y])
            return false;
        else if (mparnt[x] == mparnt[y])
            return false;
        return true;
    }
};