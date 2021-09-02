/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 19:21:12
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
    pair<int, int> expandAroundCenter(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s)
    {
        //表示回文串的左右两边索引,循环过程中维护这两个值,表示最长的回文串
        int start = 0;
        int end = 0;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            //两种基本的case,其中一种就是以单个字母进行向外扩展,也就是说回文串的长度是奇数的情况
            auto p1 = expandAroundCenter(s, i, i);
            //以两个相邻字母进行向外扩展,是偶数的情况
            auto p2 = expandAroundCenter(s, i, i + 1);
            //当以当前i值的情况向外扩展,得到的符合回文串并且是该情况下最长的,与目前的答案长度进行比较
            if (p1.second - p1.first > end - start)
            {
                start = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > end - start)
            {
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    cout << Solution().longestPalindrome("babad");
    return 0;
}