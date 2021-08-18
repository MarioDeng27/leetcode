/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 18:36:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 18:36:15
 */
class Solution
{
public:
    int helper(vector<int> nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return dp[nums.size()];
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int noEnd = helper(vector<int>(nums.begin(), nums.end() - 1));
        int noStart = helper(vector<int>(nums.begin() + 1, nums.end()));
        return max(noEnd, noStart);
    }
};