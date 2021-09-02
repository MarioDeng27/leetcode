/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-02 17:59:12
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 17:59:12
 */
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        //表示[i,j]组成的字符串中最长的回文子序列的长度为dp[i][j]
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(max(dp[i + 1][j - 1], dp[i + 1][j]), dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};