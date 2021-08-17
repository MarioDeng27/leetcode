/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 16:20:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 16:20:38
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 16:20:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 16:20:27
 */
int maxProfit_k_2(vector<int> prices)
{
    int k_max = 2;
    //dp[n][3][2]
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

//太强了，根本想不出来
int maxProfit_k_2(vector<int> prices)
{
    int dp_i_1_0 = 0, dp_i_2_0 = 0;
    int dp_i_1_1 = INT_MIN, dp_i_2_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
        dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
        dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
        dp_i_1_1 = max(dp_i_1_1, -prices[i]);
    }
    return dp_i_2_0;
}