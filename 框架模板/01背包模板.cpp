/*
 * @Description: 
 给你一个可装载重量为 W 的背包和 N 个物品，每个物品有重量和价值两个属性。其中第 i 个物品的重量为 wt[i]，价值为 val[i]，现在让你用这个背包装物品，最多能装的价值是多少？
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-25 23:10:12
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-26 23:36:48
 */
int knapsack(int W, int N, vector<int> &wt, vector<int> &val)
{
    // base case 已初始化
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (w - wt[i - 1] < 0)
            {
                // 这种情况下只能选择不装入背包
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // 装入或者不装入背包，择优
                dp[i][w] = max(dp[i - 1][w - wt[i - 1]] + val[i - 1],
                               dp[i - 1][w]);
            }
        }
    }

    return dp[N][W];
}