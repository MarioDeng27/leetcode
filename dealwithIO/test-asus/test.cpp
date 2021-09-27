/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-27 17:51:06
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
    const long N = 1000000007;
    int numDecodings(string s)
    {
        int n = s.size();
        long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;

        long pre = 1;
        long cur;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                if (s[i] == '*')
                    cur = 9;
                else if (s[i] == '0')
                    cur = 0;
                else
                    cur = 1;
                continue;
            }

            if (s[i] == '0')
            {
                pre = cur;
                cur = 0;
                continue;
            }

            long a = 0;
            if (s[i] == '*')
            {
                a = 9 * cur;
                if (s[i + 1] == '*')
                {
                    a += (15 * pre);
                }
                else if (s[i + 1] != '*')
                {
                    int num = s[i + 1] - '0';
                    if (num >= 0 && num <= 6)
                        a = a + 2 * pre;
                    else
                        a = a + pre;
                }
            }

            else
            {
                a = cur;
                if (i + 1 <= s.size() - 1 && s[i + 1] != '*')
                {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num <= 26)
                    {
                        a += pre;
                    }
                }
                else if (i + 1 <= s.size() - 1 && s[i + 1] == '*')
                {
                    if (s[i] == '1')
                        a = a + 9 * pre;
                    if (s[i] == '2')
                        a = a + 6 * pre;
                }
            }
            pre = cur;
            cur = a % N;
        }
        return cur;
    }
};
int main()
{
    int n = 3;
    //vector<vector<int>> flights = {{4, 1, 1}, {1, 2, 3}, {0, 3, 2}, {0, 4, 10}, {3, 1, 1}, {1, 4, 3}};
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << Solution().numDecodings("*1") << endl;
    return 0;
}