/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 16:25:16
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 16:27:01
 */
int maxProfit_k_inf(vector<int> prices)
{
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = dp_i_0;
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}
int maxProfit_k_any(vector<int> prices, int k_max)
{
    if (prices.size() == 0)
        return 0;
    if (k_max > prices.size() / 2)
        return maxProfit_k_inf(prices);
    //dp[n][k_max+1][2]
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k_max + 1, vector<int>(2)));
    for (int i = 0; i < prices.size(); i++)
    {
        for (int k = k_max; k >= 1; k--)
        {
            // i == -1时，dp[-1][k][0] = 0, dp[-1][k][1] = INT_MIN
            if (i == 0)
            {
                dp[i][k][0] = 0;
                // 解释：
                //   dp[i][k][0]
                // = max(dp[-1][k][0], dp[-1][k][1] + prices[i])
                // = max(0, -infinity + prices[i]) = 0
                dp[i][k][1] = -prices[i];
                //解释：
                //   dp[i][k][1]
                // = max(dp[-1][k][1], dp[-1][k-1][0] - prices[i])
                // = max(-infinity, 0 - prices[i])
                // = -prices[i]
            }
            else
            {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
    }
    return dp[prices.size() - 1][k_max][0];
}