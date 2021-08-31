/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-31 22:40:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-31 22:40:14
 */
//动态规划解决
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ret = nums[0];
        int n = nums.size();
        int dp[n];
        memset(dp, INT_MIN, sizeof(dp));
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(dp[i], ret);
        }
        return ret;
    }
};

//空间优化
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ret = nums[0];
        int n = nums.size();
        int dp = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            ret = max(dp, ret);
        }
        return ret;
    }
};