/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-02 02:51:08
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-02 03:06:15
 */
//贪心算法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                sum += (prices[i + 1] - prices[i]);
            }
        }
        return sum;
    }
};

//----------------------
//动态规划
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int prev0 = 0;
        int prev1 = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int temp = prev0;
            prev0 = max(prev0, prev1 + prices[i]);
            prev1 = max(prev1, prev0 - prices[i]);
        }

        return max(prev0, prev1);
    }
};