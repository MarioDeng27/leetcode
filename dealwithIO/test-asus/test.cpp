/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-17 22:34:43
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
    unordered_map<char, vector<int>> chartoindexs;
    int findRotateSteps(string ring, string key)
    {
        for (int i = 0; i < ring.size(); i++)
        {
            chartoindexs[ring[i]].push_back(i);
        }
        int m = ring.size();
        int n = key.size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                char need = key[j];
                int res = INT_MAX;
                for (int k = 0; k < chartoindexs[need].size(); k++)
                {
                    int index = chartoindexs[need][k];
                    int steps = abs(i - index);
                    steps = min(steps, m - steps);
                    if (j == n - 1)
                        res = min(res, steps);
                    else
                    {
                        res = min(res, dp[j + 1][index] + steps);
                    }
                }
                dp[j][i] = res;
                if (i == 0 && j == 0)
                    break;
            }
        }

        return dp[0][0] + key.size();
    }
};

int main()
{
    cout << 123;
    return 0;
}