/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-25 23:45:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-25 23:45:30
 */
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        int n = nums.size();
        //dp[i][w] = true i的编号从1开始，表示前i个且包含第i个数字可以凑出和为w
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};