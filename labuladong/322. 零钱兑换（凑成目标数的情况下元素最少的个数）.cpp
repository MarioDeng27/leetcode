/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-19 13:32:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-19 13:49:05
 */
//方法一：自己想的回溯
class Solution
{
public:
    unordered_map<string, int> mem;
    //通过index来保证元素是否被选中，思路比较复杂，有点像回溯来实现
    int backtrack(vector<int> &coins, int amount, int index, vector<int> &track)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0 || index == coins.size())
            return -1;
        string key = to_string(amount) + "," + to_string(index);
        if (mem.count(key))
            return mem[key];
        //不选中
        int a = backtrack(coins, amount, index + 1, track);

        //选中index
        track.push_back(coins[index]);

        int b = backtrack(coins, amount - coins[index], index, track);

        track.pop_back();

        int res = -1;
        if (a == -1 && b != -1)
            res = b + 1;
        if (a != -1 && b == -1)
            res = a;
        if (a != -1 && b != -1)
            res = min(a, b + 1);

        mem[key] = res;
        return res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> track;
        int res = backtrack(coins, amount, 0, track);
        return res;
    }
};

//方法2：一定要掌握：有一个dp 的方法，它用来计算从coins中凑出amount目标值最少的硬币个数
//转换，要求上一步，只要求 dp(coins, amount - coin)的最小值，coin是coins中每个硬币的类型
//用一个备忘录记录已经计算过的问题，来节省时间，用线性的vector来做备忘录会比unordered_map快很多
class Solution
{
public:
    //unordered_map<int, int> mem;
    vector<int> count;
    int dp(vector<int> &coins, int amount)
    {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        if (count[amount] != 0)
            return count[amount];
        int minval = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int a = dp(coins, amount - coins[i]);
            if (a == -1)
                continue;
            minval = min(minval, a + 1);
        }
        int res = -1;
        if (minval != INT_MAX)
            res = minval;
        count[amount] = res;
        return res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        count.resize(amount + 1, 0);
        int res = dp(coins, amount);
        return res;
    }
};

//基于上一种dp实现的动态规划
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        /* count.resize(amount + 1, 0);
        int res = dp(coins, amount);
        return res; */
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= amount)
                dp[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; i++)
        {
            int minval = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                    minval = min(dp[i - coins[j]] + 1, minval);
            }
            dp[i] = minval;
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};