/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 19:15:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-08 18:54:56
 */
/* base case：
    dp[-1][k][0] = dp[i][0][0] = 0 dp[-1][k][1] = dp[i][0][1] = -infinity

 状态转移方程：
        dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]) */

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

int maxProfit_with_fee(vector<int> prices, int fee)
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
            dp[i][1] = -prices[i] - fee;
            //解释：
            //   dp[i][1]
            // = max(dp[-1][1], dp[-1][0] - prices[i])
            // = max(-infinity, 0 - prices[i])
            // = -prices[i]
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
    }
    return dp[prices.size() - 1][0];
}
int maxProfit_with_fee(vector<int> prices, int fee)
{
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = dp_i_0;
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
    }
    return dp_i_0;
}

int maxProfit_k_inf(vector<int> prices)
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
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
}
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