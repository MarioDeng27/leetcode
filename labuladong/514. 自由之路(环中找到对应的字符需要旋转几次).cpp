/*
 * @Author: your name
 * @Date: 2021-09-17 21:49:44
 * @LastEditTime: 2021-09-17 22:33:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \test-asusf:\cpp\leetcode\labuladong\514. 自由之路(环中找到对应的字符需要旋转几次).cpp
 */

class Solution
{
public:
    unordered_map<char, vector<int>> chartoindexs;
    map<pair<int, int>, int> mem;
    int findRotateSteps(string ring, string key)
    {
        for (int i = 0; i < ring.size(); i++)
        {
            chartoindexs[ring[i]].push_back(i);
        }
        return dp(ring, 0, key, 0) + key.size();
    }
    //dp[i][j] 当前位置在ring[i] 要找到key[j...n]的最少次数
    int dp(string ring, int i, string key, int j)
    {
        if (j == key.size())
        {
            return 0;
        }
        if (mem.count({i, j}))
            return mem[{i, j}];

        char need = key[j];
        int n = ring.size();
        int res = INT_MAX;
        for (int k = 0; k < chartoindexs[need].size(); k++)
        {
            int index = chartoindexs[need][k];
            int step = abs(i - index);
            step = min(step, n - step);
            int subproblem = dp(ring, index, key, j + 1);
            res = min(res, step + subproblem);
        }
        mem[{i, j}] = res;
        return res;
    }
};

class Solution
{
public:
    unordered_map<char, vector<int>> chartoindexs;
    /*
    m 表示ring 的长度，n表示key的长度

    dp[i][j] 表示 当前指针在i位置，那么要将key的j后面包括j的字符都找到，至少要操作几次
    动态规划思路：假设key的前n-1个字符都找到了，并且是最优的情况设为x，那么只要找出第n个，即key[n-1]要旋转的次数设为y，则总共操作数是x+y
    那么y的大小取决于前n-1次操作后指针停留的位置，总共有 m种情况，将这几种情况分别记录到dp[i][j]中

    同理可知，假设key的前n-2个字符都找到了，并且是最优的情况，那么本次将第n-1和第n个字符找到的操作数是
    dp[i][j] = min(dp[index][j+1]..) index是key[j]在ring中的坐标集合

    ...有点难说清楚，反正从后往前推，假设key只有一个字符，在ring所有可能出现的位置的基础上找到这个字符的最小次数
    如果往key的前面加一个字符，倒数第二个字符，在ring所有可能出现的位置的基础上找到当前次数加上在这个条件下最后一个字符所需要的次数

    */
    int findRotateSteps(string ring, string key)
    {
        for (int i = 0; i < ring.size(); i++)
        {
            chartoindexs[ring[i]].push_back(i);
        }
        int m = ring.size();
        int n = key.size();
        int dp[m][n];
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
                        res = min(res, dp[index][j + 1] + steps);
                    }
                }
                dp[i][j] = res;
                if (i == 0 && j == 0)
                    break;
            }
        }

        return dp[0][0] + key.size();
    }
};