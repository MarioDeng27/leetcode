/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 17:24:10
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 18:35:45
 */
//dp的长度如果是size+1，那dp[i]表示，房子的编号是从1开始的，小偷走到第i间房子可以偷盗的最大金额，dp[0]表示小偷还没走到第一个房子，dp[1]表示小偷刚走到第一个房子
//dp的长度如果设成size，那dp[i]表示，房子的编号从0开始，小偷走到第i间房子可以偷盗的最大金额，dp[0]表示，小偷走到首个房子，dp[1]表示，已经走到第二个房子了，如果只剩两个，那么肯定偷编号为0和1房子间金额较多的那个。
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return dp[nums.size()];
    }
};