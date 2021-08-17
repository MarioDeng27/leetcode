/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 16:26:52
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

int maxProfit_k_inf(vector<int> prices)
{
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = dp_i_0;
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}

int maxProfit_k_any(vector<int> prices, int k_max)
{
    if (prices.size() == 0)
        return 0;

    if (k_max > prices.size() / 2)
        return maxProfit_k_inf(prices);
    //dp[n][k_max+1][2]
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k_max + 1, vector<int>(2)));
    for (int i = 0; i < prices.size(); i++)
    {
        for (int k = k_max; k >= 1; k--)
        {
            // i == -1时，dp[-1][k][0] = 0, dp[-1][k][1] = INT_MIN
            if (i == 0)
            {
                dp[i][k][0] = 0;
                // 解释：
                //   dp[i][k][0]
                // = max(dp[-1][k][0], dp[-1][k][1] + prices[i])
                // = max(0, -infinity + prices[i]) = 0
                dp[i][k][1] = -prices[i];
                //解释：
                //   dp[i][k][1]
                // = max(dp[-1][k][1], dp[-1][k-1][0] - prices[i])
                // = max(-infinity, 0 - prices[i])
                // = -prices[i]
            }
            else
            {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
    }
    return dp[prices.size() - 1][k_max][0];
}

int maxProfit_k_2(vector<int> prices)
{
    int dp_i_1_0 = 0, dp_i_2_0 = 0;
    int dp_i_1_1 = INT_MIN, dp_i_2_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
        dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
        dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
        dp_i_1_1 = max(dp_i_1_1, -prices[i]);
    }
    return dp_i_2_0;
}
int main()
{

    cout << Solution().lengthOfLongestSubstring("abcabcbb");
    return 0;
}
