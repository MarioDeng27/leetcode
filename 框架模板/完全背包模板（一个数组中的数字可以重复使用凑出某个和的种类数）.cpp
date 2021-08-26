/*
 * @Description: 
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-26 23:35:09
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-26 23:35:09
 */
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        //dp[i][w] 表示 i从1开始，前i个包含第i个数字，（只使用前i个，后面不能用）可以凑出w的种类
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        //dp[0][w] = 0, 不使用隐蔽可以凑出w，w！= 0的情况是不可能发生的
        //dp[i][0] = 1, 在可以使用了前i个的前提下，凑出为0的情况就只有一种，就是什么也不选
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (j - coins[i - 1] >= 0)
                    //若不选第i个来凑，则这个结果会有dp[i-1][j]种情况，若可以选第i个数字来凑，则要凑到j，那么就取决于dp[i][j-coins[i-1]]的情况个数了（这个是i而不是i-1表示第i个数字在凑j-coins[i-1]时可以使用）
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};