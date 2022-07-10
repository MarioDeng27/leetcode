/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-10 15:35:06
 */
/*
 * @FilePath: \Sort\test.cpp
 * @Brief:
 * @Version: 1.0
 * @Date: 2020-10-05 22:41:14
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 00:37:48
 */
#include <algorithm>
#include <array>
#include <atomic>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <pthread.h> // pthread_create(), pthread_join()
#include <queue>
#include <semaphore.h> // sem_init()
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <vector>
using namespace std;

/* #include <bits/stdc++.h>
using namespace std; */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<string> res;
    vector<vector<int>> paths;
    void dfs(TreeNode *root, vector<int> path)
    {
        if (!root->left && !root->right)
        {
            paths.push_back(path);
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            dfs(root->left, path);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            dfs(root->right, path);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return res;
        vector<int> path = {root->val};
        dfs(root, path);
        for (int i = 0; i < paths.size(); i++)
        {
            string str = "";
            for (int j = 0; j < paths[i].size(); j++)
            {
                if (j == paths[i].size() - 1)
                {
                    str += to_string(paths[i][j]);
                }
                else
                {
                    str += (to_string(paths[i][j]) + "->");
                }
            }
            res.push_back(str);
        }
        return res;
    }
};
int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root5 = new TreeNode(5);
    root1->left = root2;
    root1->right = root3;
    root2->right = root5;

    Solution()
        .binaryTreePaths(root1);
    /* for (auto n : nums1)
        cout << n << " "; */
    cout << "ss" << endl;
    return 0;
}