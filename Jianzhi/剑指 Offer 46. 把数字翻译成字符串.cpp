/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-04-13 20:52:39
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-13 21:12:48
 */
//https : //leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/submissions/
class Solution
{
public:
    int translateNum(int num)
    {
        string str;
        str = to_string(num);
        vector<int> dp(str.size(), 1);
        int prev = INT_MAX;
        for (int i = 1; i < str.size(); i++)
        {
            string t = str.substr(i - 1, 2);
            int tmp;
            if (t[0] != '0')
                tmp = (t[0] - '0') * 10 + (t[1] - '0');
            else
                tmp = 30;
            if (tmp <= 25)
            {
                if (i >= 2 && i < 3)
                    dp[i] = dp[i - 2] * 2 + (prev <= 25 ? 1 : 0);
                else if (i >= 3)
                {
                    dp[i] = dp[i - 2] * 2 + dp[i - 3] * (prev <= 25 ? 1 : 0);
                }
                else
                    dp[i] = 2;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
            prev = tmp;
        }
        return dp[str.size() - 1];
    }
};
//把数字分为两种情况
class Solution
{
public:
    int translateNum(int num)
    {
        string str;
        str = to_string(num);
        vector<int> dp(str.size(), 1);
        for (int i = 1; i < str.size(); i++)
        {
            string t = str.substr(i - 1, 2);
            int tmp;
            tmp = (t[0] - '0') * 10 + (t[1] - '0');
            if (tmp >= 10 && tmp <= 25)
            {
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp[str.size() - 1];
    }
};