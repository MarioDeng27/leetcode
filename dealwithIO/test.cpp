/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-19 21:16:41
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
    vector<vector<int>> twoSumTarget(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        vector<vector<int>> res;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            int left = nums[low];
            int right = nums[high];
            if (sum < target)
            {
                //去除nums从low位置开始与left一样的值
                while (low < high && nums[low] == left)
                    low++;
            }
            else if (sum > target)
            {
                //去除nums从high位置开始与right一样的值
                while (low < high && nums[high] == right)
                    high--;
            }
            else if (sum == target)
            {
                res.push_back({left, right});
                while (low < high && nums[low] == left)
                    low++;
                while (low < high && nums[high] == right)
                    high--;
            }
        }
        return res;
    }

    vector<vector<int>> threeSumTarget(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto tuples = twoSumTarget(nums, target - num);
            for (auto tuple : tuples)
            {
                tuple.push_back(num);
                res.push_back(tuple);
            }
            while (i < n - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {200, 3, 140, 20, 10};
    // cout << Solution().rob(nums);
    return 0;
}
