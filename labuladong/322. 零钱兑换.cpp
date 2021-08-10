/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-06 18:44:28
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-06 18:44:48
 */
class Solution
{
public:
    int res = INT_MAX;
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int temp = coinChange(coins, amount - coins[i]);
            if (temp == -1)
                continue;
            res = min(1 + temp, res);
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};

class Solution
{
public:
    int res = INT_MAX;
    map<int, int> mp;
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (mp.count(amount) != 0)
            return mp[amount];
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int temp = coinChange(coins, amount - coins[i]);
            if (temp == -1)
                continue;
            res = min(1 + temp, res);
        }
        if (res == INT_MAX)
            return -1;
        mp[amount] = res;
        return res;
    }
};

class Solution
{
public:
    int res = INT_MAX;
    map<int, int> mp;
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            for (auto coin : coins)
            {
                if (i - coin >= 0)
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};