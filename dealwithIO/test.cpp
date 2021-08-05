/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-05 21:46:49
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

void func(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> B(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            B[j][R - 1 - i] = A[i][j];
        }
    }
    A = B;
}
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

class Codec
{
public:
    // Encodes a tree to a single string.
    string splitstr = ",";
    string nullstr = "#";
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        queue<TreeNode *> que;
        que.push(root);
        string res = "";
        while (!que.empty())
        {
            TreeNode *p = que.front();
            que.pop();
            if (p == nullptr)
            {
                res += nullstr + splitstr;
                continue;
            }
            res += to_string(p->val) + splitstr;
            que.push(p->left);
            que.push(p->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> strlist;
        string temp = "";
        for (auto chr : data)
        {
            if (chr == ',')
            {
                strlist.push_back(temp);
                temp = "";
            }
            else
                temp += chr;
        }
        return deserializehelp(strlist);
    }
    TreeNode *deserializehelp(list<string> &strlist)
    {
        if (strlist.empty())
            return nullptr;
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(stoi(strlist.front()));
        strlist.pop_front();
        que.push(root);
        while (!strlist.empty())
        {
            TreeNode *parent = que.front();
            que.pop();
            string left = strlist.front();
            strlist.pop_front();
            if (left != nullstr)
            {
                parent->left = new TreeNode(stoi(left));
                que.push(parent->left);
            }

            string right = strlist.front();
            strlist.pop_front();
            if (right != nullstr)
            {
                parent->right = new TreeNode(stoi(right));
                que.push(parent->right);
            }
        }
        return root;
    }
};

int main()
{
    vector<int> vec(4);
    cout << " " << endl;
    return 0;
}
