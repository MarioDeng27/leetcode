/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 15:13:08
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 15:13:08
 */
int maxProfit_with_cool(vector<int> prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    for (int i = 0; i < prices.size(); i++)
    {
        // i == -1时，dp[-1][0] = 0, dp[-1][1] = INT_MIN
        if (i == 0)
        {
            dp[i][0] = 0;
            // 解释：
            //   dp[i][0]
            // = max(dp[-1][0], dp[-1][1] + prices[i])
            // = max(0, -infinity + prices[i]) = 0
            dp[i][1] = -prices[i];
            //解释：
            //   dp[i][1]
            // = max(dp[-1][1], dp[-1][0] - prices[i])
            // = max(-infinity, 0 - prices[i])
            // = -prices[i]
            continue;
        }
        if (i == 1)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            //解释：
            //   dp[i][1]
            // = max(dp[0][1], dp[-1][0] - prices[i])
            // = max(-prices[0], 0 - prices[1])
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
}
int maxProfit_with_cool(vector<int> prices)
{
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    int dp_i_0_pre = 0; //当前i的前两天对应的最大利润
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = dp_i_0;
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, dp_i_0_pre - prices[i]);
        dp_i_0_pre = temp;
    }
    return dp_i_0;
}