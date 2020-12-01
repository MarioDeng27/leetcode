/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Backtracking\第二阶段\216. 组合总和 III.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-12-01 19:18:47
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-01 19:19:17
 */
//自己的方法
//参照77以及40
class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(int k, int n, vector<int> &track, int sum, int cnt)
    {
        if (track.size() == k)
        {
            if (n == sum)
                res.push_back(track);
            return;
        }
        for (int i = cnt; i <= 9; i++)
        {
            if (sum + i <= n)
            {
                sum += i;
                track.push_back(i);
                backtrack(k, n, track, sum, i + 1);
                sum -= i;
                track.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> track;
        backtrack(k, n, track, 0, 1);
        return res;
    }
};