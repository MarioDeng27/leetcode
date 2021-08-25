/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-24 22:59:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-24 22:59:23
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i++)
        {
            int maxlen = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    maxlen = max(maxlen, dp[j]);
                }
            }
            dp[i] += maxlen;
            res = max(res, dp[i]);
        }
        return res;
    }
};