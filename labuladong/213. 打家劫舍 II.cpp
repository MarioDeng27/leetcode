/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 10:05:11
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 10:38:44
 */

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int dp_i2 = 0;
        int dp_i1 = 0;
        int dp_i = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            //int done = dp[i + 2] + nums[i];
            int done = dp_i2 + nums[i];
            //int notdone = dp[i + 1];
            int notdone = dp_i1;
            dp_i = max(done, notdone);
            dp_i2 = dp_i1;
            dp_i1 = dp_i;
        }

        int nostart = dp_i;

        dp_i2 = 0;
        dp_i1 = 0;
        dp_i = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            //int done = dp[i + 2] + nums[i];
            int done = dp_i2 + nums[i];
            //int notdone = dp[i + 1];
            int notdone = dp_i1;
            dp_i = max(done, notdone);
            dp_i2 = dp_i1;
            dp_i1 = dp_i;
        }

        int notend = dp_i;
        return max(nostart, notend);
    }
};

//labuladong解法
public
int rob(int[] nums)
{
    int n = nums.length;
    if (n == 1)
        return nums[0];
    return Math.max(robRange(nums, 0, n - 2),
                    robRange(nums, 1, n - 1));
}

// 仅计算闭区间 [start,end] 的最优结果
int robRange(int[] nums, int start, int end)
{
    int n = nums.length;
    int dp_i_1 = 0, dp_i_2 = 0;
    int dp_i = 0;
    for (int i = end; i >= start; i--)
    {
        dp_i = Math.max(dp_i_1, nums[i] + dp_i_2);
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i;
}
//递归，带备忘录
class Solution
{
public:
    unordered_map<int, int> mem;
    //偷 [start,end) 的房子的最大利润
    int dp(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return 0;
        if (mem.count(start) > 0)
            return mem[start];
        //偷start这一房子
        int done = nums[start] + dp(nums, start + 2, end);
        //不偷start这一房子
        int notdone = dp(nums, start + 1, end);
        int res = max(done, notdone);
        mem[start] = res;
        return res;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        //偷不包含第一个房子，从第二个房子开始到最后一个房子的结果
        int nostart = dp(nums, 1, nums.size());
        mem.clear();
        //偷不包含最后一个房子，从第一个房子开始，到倒数第二个房子的结果
        int noend = dp(nums, 0, nums.size() - 1);
        return max(nostart, noend);
    }
};