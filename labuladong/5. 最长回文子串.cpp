/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-02 17:33:50
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 17:47:58
 */
//dp方法
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;
        int maxLen = 1;
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == (j - i - 1))
                {
                    dp[i][j] = j - i + 1;
                    if (dp[i][j] > maxLen)
                    {
                        l = i;
                        r = j;
                        maxLen = j - i + 1;
                    }
                }
                else
                {
                    dp[i][j] = max(max(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]);
                }
            }
        }
        return s.substr(l, maxLen);
    }
};
//中心扩展方法
class Solution
{
public:
    string expand(string s, int l, int r)
    {
        string res = "";
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        l++;
        r--;
        if (l <= r)
        {
            res = s.substr(l, r - l + 1);
        }
        return res;
    }
    string longestPalindrome(string s)
    {
        int l = 0;
        int r = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            string str1 = expand(s, i, i);
            string str2 = expand(s, i, i + 1);
            if (str1.size() > res.size())
                res = str1;
            if (str2.size() > res.size())
                res = str2;
        }
        return res;
    }
};