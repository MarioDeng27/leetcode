/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Backtracking\第一阶段\77. 组合.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-08 15:12:19
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-01 19:02:24
 */
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//自己的想法

class Solution
{
public:
    vector<vector<int>> res;
    int n;
    int k;
    void backtrack(int cnt, int start, vector<int> track)
    {
        if (cnt == k)
        {
            res.push_back(track);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            track.push_back(i);
            cnt++;
            backtrack(cnt, i + 1, track);
            track.pop_back();
            cnt--;
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n;
        this->k = k;
        backtrack(0, 1, {});
        return res;
    }
};

//方法2
class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, int cnt, vector<int> &track)
    {
        if (track.size() == k)
        {
            res.push_back(track);
            return;
        }
        for (int i = cnt; i <= n; i++)
        {
            track.push_back(i);
            backtrack(n, k, i + 1, track);
            track.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }
};