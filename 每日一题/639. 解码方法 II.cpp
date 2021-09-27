/*
 * @Author: your name
 * @Date: 2021-09-27 16:59:41
 * @LastEditTime: 2021-09-27 17:52:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \test-asusf:\cpp\leetcode\每日一题\639. 解码方法 II.cpp
 */
/*
 * @Author: your name
 * @Date: 2021-09-27 16:59:41
 * @LastEditTime: 2021-09-27 16:59:42
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \test-asusf:\cpp\leetcode\每日一题\639. 解码方法 II.cpp
 */
//dp带备忘录，但是过了90%，最后会超时

class Solution
{
public:
    const long N = 1000000007;
    vector<int> mem;
    long dp(string s, int i)
    {
        if (i > s.size())
            return 0;
        if (i == s.size())
            return 1;

        if (mem[i] != -1)
            return mem[i];

        if (s[i] == '0')
            return 0;

        if (s[i] != '*')
        {
            long a = dp(s, i + 1);
            if (i + 1 <= s.size() - 1 && s[i + 1] != '*')
            {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num <= 26)
                {
                    a += dp(s, i + 2);
                }
            }
            else if (i + 1 <= s.size() - 1 && s[i + 1] == '*')
            {
                if (s[i] == '1')
                    a = a + 9 * dp(s, i + 2);
                if (s[i] == '2')
                    a = a + 6 * dp(s, i + 2);
            }
            mem[i] = a % N;
            return a % N;
        }
        else
        {
            long a = 9 * dp(s, i + 1);
            if (i + 1 <= s.size() - 1 && s[i + 1] != '*')
            {
                int num = s[i + 1] - '0';
                if (num >= 0 && num <= 6)
                    a = a + 2 * dp(s, i + 2);
                else
                    a = a + dp(s, i + 2);
            }
            else if (i + 1 <= s.size() - 1 && s[i + 1] == '*')
            {
                a = a + 15 * dp(s, i + 2);
            }
            mem[i] = a % N;
            return a % N;
        }
    }

    int numDecodings(string s)
    {
        mem.resize(s.size(), -1);
        return dp(s, 0) % N;
    }
};
//dp完成，无压缩
class Solution
{
public:
    const long N = 1000000007;
    int numDecodings(string s)
    {
        int n = s.size();
        long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                if (s[i] == '*')
                    dp[i] = 9;
                else if (s[i] == '0')
                    dp[i] = 0;
                else
                    dp[i] = 1;
                continue;
            }
            long a = 0;
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }

            if (s[i] == '*')
            {
                a = 9 * dp[i + 1];
                if (s[i + 1] == '*')
                {
                    a += (15 * dp[i + 2]);
                }
                else if (s[i + 1] != '*')
                {
                    int num = s[i + 1] - '0';
                    if (num >= 0 && num <= 6)
                        a = a + 2 * dp[i + 2];
                    else
                        a = a + dp[i + 2];
                }
            }

            else
            {
                a = dp[i + 1];
                if (i + 1 <= s.size() - 1 && s[i + 1] != '*')
                {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num <= 26)
                    {
                        a += dp[i + 2];
                    }
                }
                else if (i + 1 <= s.size() - 1 && s[i + 1] == '*')
                {
                    if (s[i] == '1')
                        a = a + 9 * dp[i + 2];
                    if (s[i] == '2')
                        a = a + 6 * dp[i + 2];
                }
            }
            dp[i] = a % N;
        }
        return dp[0];
    }
};
//dp完成，有压缩
class Solution
{
public:
    const long N = 1000000007;
    int numDecodings(string s)
    {
        int n = s.size();
        long pre = 1;
        long cur;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                if (s[i] == '*')
                    cur = 9;
                else if (s[i] == '0')
                    cur = 0;
                else
                    cur = 1;
                continue;
            }

            if (s[i] == '0')
            {
                pre = cur;
                cur = 0;
                continue;
            }

            long a = 0;
            if (s[i] == '*')
            {
                a = 9 * cur;
                if (s[i + 1] == '*')
                {
                    a += (15 * pre);
                }
                else if (s[i + 1] != '*')
                {
                    int num = s[i + 1] - '0';
                    if (num >= 0 && num <= 6)
                        a = a + 2 * pre;
                    else
                        a = a + pre;
                }
            }

            else
            {
                a = cur;
                if (i + 1 <= s.size() - 1 && s[i + 1] != '*')
                {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num <= 26)
                    {
                        a += pre;
                    }
                }
                else if (i + 1 <= s.size() - 1 && s[i + 1] == '*')
                {
                    if (s[i] == '1')
                        a = a + 9 * pre;
                    if (s[i] == '2')
                        a = a + 6 * pre;
                }
            }
            pre = cur;
            cur = a % N;
        }
        return cur;
    }
};