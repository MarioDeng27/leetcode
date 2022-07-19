/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-19 12:29:54
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-19 12:32:55
 */
/*
dp[i][j]表示以[i,j]作为正方形右下角的坐标所能得到的最大正方形的边长，它的值一定是dp[i-1][j],dp[i][j-1],dp[i-1][j-1]中的最小值+1，反过来说，如果正方形边长是k，则这个点的上边和左边的邻居点所能组成的最大正方形的边长就是k-1，当然是充要条件
 */
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        if (!m || !n)
            return 0;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};