/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-12 15:12:56
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> mp(n);
        for (auto edge : edges)
        {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                que.push(i);
        }
        vector<int> res;
        while (!que.empty())
        {
            res.clear();
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                int node = que.front();
                que.pop();
                res.push_back(node);
                for (auto neibor : mp[node])
                {
                    degree[neibor]--;
                    if (degree[neibor] == 1)
                        que.push(neibor);
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> vec = {{1, 0}, {1, 2}, {1, 3}};
    Solution().findMinHeightTrees(4, vec);
    /* for (auto n : nums1)
        cout << n << " "; */
    cout << "ss" << endl;
    return 0;
}