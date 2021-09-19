/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-19 13:40:59
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
/* #include <bits/stdc++.h>
using namespace std; */

class Solution
{
public:
    //unordered_map<int, int> mem;
    vector<int> count;
    int dp(vector<int> &coins, int amount)
    {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        if (count[amount] != 0)
            return count[amount];
        int minval = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int a = dp(coins, amount - coins[i]);
            if (a == -1)
                continue;
            minval = min(minval, a + 1);
        }
        int res = -1;
        if (minval != INT_MAX)
            res = minval;
        count[amount] = res;
        return res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        /* count.resize(amount + 1, 0);
        int res = dp(coins, amount);
        return res; */
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= amount)
                dp[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; i++)
        {
            int minval = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (coins[j] <= i)
                    minval = min(dp[i - coins[j]] + 1, minval);
            }
            dp[i] = minval;
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
int main()
{
    vector<int> nums = {2, 3, 6, 7};
    auto res = Solution().combinationSum(nums, 7);

    return 0;
}