/*
    动态规划：
    步骤：先尝试用递归方式写出暴力算法，这样的话核心的转移方程会有体现，接下去就尝试将每一种状态的值记录再DP table里，当作备忘录
    str1="abcde"，str2 = "ace"
    1. DP table定义
    dp[i][j]的含义：str1中从字符串的第1个字符开始到第i个字符形成的子串和str2中从字符串的第一个字符开始到第j个字符形成的字串的最长公共子序列（lcs）
    比如dp[1][1],表示 [1,1]和[1,1]即，a和a 的lcs 就是1
    dp[2][3],表示ab和ace的lcs是1

    2. 状态转移方程
    其实就是在确定选择条件，这里我们选择当前str1[i] 和 str2[j]两字符是否相等作为选择条件，然后进行分支判断
    假设我们已经知道 dp[i-1][j-1]和dp[i-1][j]和dp[i][j-1]三个dp值，那么当我们来到他们的后一个状态的时候，可以利用前一阶段的状态值来判断
    先写选择条件：如果str1[i] = str2[j] = c那么该字符c变量c必定会存在lcs中。那么其dp[i][j] 也就是dp[i-1][j-1]+1的值，即前一个状态值加1
    如果不相等，则目前dp的最大值就是dp[i][j]的值，那么最大值如何判断呢，也就是从dp[i-1][j-1]和dp[i-1][j]和dp[i][j-1]的三个dp值中选出最大值，然而
    dp[i-1][j-1]必定不大于dp[i-1][j]和dp[i][j-1]，所以只要判断dp[i-1][j]和dp[i][j-1]中的较大值作为当前dp值就行。

    其实最终的选择可以归纳为，str1[i]和str[2]是否在lcs中，如果相等，那么肯定都存在于lcs，如果不相等，那么他们两个中至少有一个字符是不存在于lcs中的
    dp[i-1][j]就可以表示str1[i]字符必定不在lcs中
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};