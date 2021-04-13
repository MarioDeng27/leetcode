/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-04-11 17:06:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-11 17:06:24
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>>
            dp(n, vector<bool>(n, false));
        int len = INT_MIN;
        string res;
        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i + l - 1 > n - 1)
                    break;
                int j = i + l - 1;
                if (l == 1)
                    dp[i][j] = true;
                else if (l == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if (dp[i][j] && l > len)
                {
                    len = l;
                    res = s.substr(i, l);
                }
            }
        }
        return res;
    }
};