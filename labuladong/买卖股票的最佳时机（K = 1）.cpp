/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 14:21:47
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 14:21:47
 */
int maxProfit_k_1(vector<int> prices)
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
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[prices.size() - 1][0];
}
int maxProfit_k_1(vector<int> prices)
{
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}