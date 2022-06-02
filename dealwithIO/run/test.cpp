/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-02 19:57:21
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
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int x = nums[i - 1];
            int y = nums[i];
            if (x > y)
            {
                cnt++;
                if (cnt > 1)
                    return false;
                if (i > 1 && nums[i - 2] > y)
                {
                    nums[i] = x;
                }
            }
        }
        return true;
    }
};
int main()
{
    auto v = {1, 0, 0, 0, 1};
    auto b = Solution().partitionLabels("bceacbacdbbadea");
    cout << "ss" << endl;
    return 0;
}