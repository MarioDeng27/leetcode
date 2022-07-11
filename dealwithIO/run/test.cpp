/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-11 15:08:15
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
    /* 输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
     */
    int t;
    vector<vector<int>> res;
    void dfs(vector<int> &candidates, vector<bool> &visited, int index, int sum, vector<int> nums)
    {
        if (sum == t)
        {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (sum + candidates[i] > t)
                return;
            if (visited[i])
                continue;
            if (i > 0 && !visited[i - 1] && candidates[i - 1] == candidates[i])
                continue;
            visited[i] = true;
            sum += candidates[i];
            nums.push_back(candidates[i]);
            dfs(candidates, visited, i + 1, sum, nums);
            visited[i] = false;
            sum -= candidates[i];
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        t = target;
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        vector<bool> visited(candidates.size(), false);
        dfs(candidates, visited, 0, 0, nums);
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