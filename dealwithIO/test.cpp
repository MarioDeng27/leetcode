/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 10:37:37
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

class Solution
{
public:
    unordered_map<int, int> mem;
    //偷 [start,end) 的房子的最大利润
    int dp(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return 0;
        if (mem.count(start) > 0)
            return mem[start];
        //偷start这一房子
        int done = nums[start] + dp(nums, start + 2, end);
        //不偷start这一房子
        int notdone = dp(nums, start + 1, end);
        int res = max(done, notdone);
        mem[start] = res;
        return res;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        //偷不包含第一个房子，从第二个房子开始到最后一个房子的结果
        int nostart = dp(nums, 1, nums.size());
        mem.clear();
        //偷不包含最后一个房子，从第一个房子开始，到倒数第二个房子的结果
        int noend = dp(nums, 0, nums.size() - 1);
        return max(nostart, noend);
    }
};

int main()
{
    vector<int> nums = {200, 3, 140, 20, 10};
    cout << Solution().rob(nums);
    return 0;
}
