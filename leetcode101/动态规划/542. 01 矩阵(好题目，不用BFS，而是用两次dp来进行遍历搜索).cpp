/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-18 11:37:54
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-18 12:48:42
 */
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = m ? mat[0].size() : 0;
        if (!m && !n)
            return {};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                if (i == 0)
                {
                    dp[i][j] = j > 0 ? dp[i][j - 1] + 1 : (m + n);
                }
                else
                {
                    dp[i][j] = j > 0 ? min(dp[i - 1][j], dp[i][j - 1]) + 1 : dp[i - 1][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    continue;
                if (i == m - 1)
                {
                    int t = j < n - 1 ? dp[i][j + 1] + 1 : (m + n);
                    dp[i][j] = min(dp[i][j], t);
                }
                else
                {
                    int t = j < n - 1 ? min(dp[i][j + 1], dp[i + 1][j]) + 1 : dp[i + 1][j] + 1;
                    dp[i][j] = min(dp[i][j], t);
                }
            }
        }
        return dp;
    }
};
//更加自如
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = m ? mat[0].size() : 0;
        if (!m && !n)
            return {};
        vector<vector<int>> dp(m, vector<int>(n, m + n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (i > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j > 0)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (i < m - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    if (j < n - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }
        return dp;
    }
};
