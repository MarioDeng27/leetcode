/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-03 19:15:32
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
    string minWindow(string s, string t)
    {
        int l = 0;
        map<char, int> need;
        for (int i = 0; i < t.size(); i++)
        {
            need[t[i]]++;
        }
        map<char, int> windows;
        string res;
        int len = INT_MAX;
        for (int r = 0; r < s.size(); r++)
        {
            if (need.find(s[r]) != need.end())
            {
                windows[s[r]]++;
                if (windows[s[r]] >= need[s[r]])
                {
                    bool isok = true;
                    for (auto it = need.begin(); it != need.end(); it++)
                    {
                        if (windows[it->first] < it->second)
                        {
                            isok = false;
                            break;
                        }
                    }
                    if (isok)
                    {
                        while (need.find(s[l]) == need.end() || windows[s[l]] > need[s[l]])
                        {
                            if (need.find(s[l]) != need.end())
                                windows[s[l]]--;
                            l++;
                        }
                        if (len > r - l + 1)
                        {
                            res = s.substr(l, r - l + 1);
                            len = r - l + 1;
                        }
                        windows[s[l]]--;
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    auto v = {1, 0, 0, 0, 1};
    auto b = Solution().minWindow("ADOBECODEBANC", "ABC");
    cout << "ss" << endl;
    return 0;
}