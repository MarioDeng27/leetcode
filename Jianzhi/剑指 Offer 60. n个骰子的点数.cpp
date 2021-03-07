/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-07 16:31:37
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-07 16:31:58
 */

class Solution
{
public:
    int maxValue = 6;
    //dp[n][i] = k 表示投了n次，和为i的次数为k，它和上一次的状态有联系
    vector<double> dicesProbability(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= maxValue; i++)
        {
            dp[1][i] = 1;
        }

        for (int j = 2; j <= n; j++)
        {
            for (int m = j; m <= j * maxValue; m++)
            {
                for (int k = 1; k <= maxValue; k++)
                {
                    if (m - k < 1)
                        break;
                    dp[j][m] += dp[j - 1][m - k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> res;
        for (int i = 0; i < dp[n].size(); i++)
        {
            if (dp[n][i] == 0)
                continue;
            double p = dp[n][i] * 1.0 / all;
            res.push_back(p);
        }
        //sort(res.begin(), res.end());
        return res;
    }
};

class Solution
{
public:
    int maxValue = 6;
    //dp[n][i] = k 表示投了n次，和为i的次数为k，它和上一次的状态有联系
    vector<double> dicesProbability(int n)
    {
        //vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        vector<int> dp(6 * n + 1, 0);
        for (int i = 1; i <= maxValue; i++)
        {
            dp[i] = 1;
        }

        for (int j = 2; j <= n; j++)
        {
            for (int m = j * maxValue; m >= j; m--)
            {
                dp[m] = 0;
                for (int k = 1; k <= maxValue; k++)
                {
                    if (m - k < j - 1)
                        break;
                    dp[m] += dp[m - k];
                }
            }
        }

        int all = pow(6, n);
        vector<double> res;
        for (int i = n; i < dp.size(); i++)
        {
            if (dp[i] == 0)
                continue;
            double p = dp[i] * 1.0 / all;
            res.push_back(p);
        }
        //sort(res.begin(), res.end());
        return res;
    }
};