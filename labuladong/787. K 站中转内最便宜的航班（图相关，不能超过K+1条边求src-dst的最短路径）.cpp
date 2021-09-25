/*
 * @Author: your name
 * @Date: 2021-09-25 19:48:02
 * @LastEditTime: 2021-09-25 20:45:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \test-asusf:\cpp\leetcode\labuladong\787. K 站中转内最便宜的航班（图相关，不能超过K+1条边求src-dst的最短路径）.cpp
 */
class Solution
{
public:
    int start;
    map<int, vector<pair<int, int>>> fromset;
    map<pair<int, int>, int> mem;
    int dp(int s, int k)
    {
        if (s == start)
        {
            return 0;
        }
        if (k == 0)
            return -1;
        if (mem.count({s, k}))
            return mem[{s, k}];
        int res = INT_MAX;
        if (fromset.count(s))
        {
            auto temp = fromset[s];

            for (int i = 0; i < temp.size(); i++)
            {
                int subproblem = dp(temp[i].first, k - 1);
                if (subproblem != -1)
                    res = min(res, subproblem + temp[i].second);
            }
        }
        if (res == INT_MAX)
            res = -1;
        mem[{s, k}] = res;
        return res;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        start = src;
        for (int i = 0; i < flights.size(); i++)
        {
            int to = flights[i][1];
            int from = flights[i][0];
            int cost = flights[i][2];
            fromset[to].push_back({from, cost});
        }
        return dp(dst, k + 1);
    }
};
//dp
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