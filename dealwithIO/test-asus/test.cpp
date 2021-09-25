/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-25 20:42:54
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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        map<int, vector<pair<int, int>>> fromset;
        // dp[i][k]表示 在k步之内（k条边内）到达i的最小路径
        int dp[n][k + 1];
        //-1代表src在k个中转点的情况下不能到达 i
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < flights.size(); i++)
        {
            int to = flights[i][1];
            int from = flights[i][0];
            int cost = flights[i][2];
            fromset[to].push_back({from, cost});
            if (from == src)
            {
                dp[to][0] = cost;
            }
        }
        for (int i = 0; i <= k; i++)
            dp[src][i] = 0;
        for (int j = 1; j <= k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (fromset.count(i) == 0 || i == src)
                    continue;
                auto froms = fromset[i];
                int res = INT_MAX;
                for (int t = 0; t < froms.size(); t++)
                {
                    int from = froms[t].first;
                    int cost = froms[t].second;
                    if (dp[from][j - 1] == -1 || dp[from][j - 1] == INT_MAX)
                        continue;
                    res = min(dp[from][j - 1] + cost, res);
                }
                dp[i][j] = res;
            }
        }
        return dp[dst][k] == INT_MAX ? -1 : dp[dst][k];
    }
};
int main()
{
    int n = 3;
    //vector<vector<int>> flights = {{4, 1, 1}, {1, 2, 3}, {0, 3, 2}, {0, 4, 10}, {3, 1, 1}, {1, 4, 3}};
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << Solution().findCheapestPrice(3, flights, 0, 2, 1) << endl;
    return 0;
}