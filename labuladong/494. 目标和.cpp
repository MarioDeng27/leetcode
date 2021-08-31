/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-31 21:41:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-31 22:40:17
 */
//不带备忘录的回溯实现
class Solution
{
public:
    int ret = 0;
    void backtrack(vector<int> &nums, int i, int rest)
    {
        if (i == nums.size())
        {
            if (rest == 0)
                ret++;
            return;
        }
        backtrack(nums, i + 1, rest - nums[i]);
        backtrack(nums, i + 1, rest + nums[i]);
        /*
        或者
        "选择符号为+号"
        rest -= nums[i]
        backtrack(nums, i + 1, rest);
        rest += nums[i]

        "选择符号为-号"
        rest += nums[i]
        backtrack(nums, i + 1, rest);
        rest -= nums[i]
        */
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        backtrack(nums, 0, target);
        return ret;
    }
};

//带mem的递归实现，有点像回溯，有选择有回退
class Solution
{
public:
    unordered_map<string, int> mem;
    //状态变量是i和rest
    //backtrack计算的是[i,n-1]数字中和以及初始值为rest这种情况下，能够将rest减到 0 的情况的种数
    int backtrack(vector<int> &nums, int i, int rest)
    {
        if (i == nums.size())
        {
            if (rest == 0)
                return 1;
            return 0;
        }
        string key = to_string(i) + "," + to_string(rest);
        if (mem.count(key))
            return mem[key];
        //做选择
        int a = backtrack(nums, i + 1, rest - nums[i]);
        //恢复选择前的状态，重新选择
        int b = backtrack(nums, i + 1, rest + nums[i]);
        mem[key] = a + b;
        return a + b;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return backtrack(nums, 0, target);
    }
};

//动态规划
class Solution
{
public:
    /* 
    dp思路推导：将nums种的数组分为两堆，一堆A是表示它们所选用的符号是 “+”，另一堆B表示它们所选用的符号是“-”，所以
    sum(A) - sum(B) = target -> sum(A) = target + sum(B)
    sum(A) + sum(A) = target + sum(B) + sum(A)
    sum(A) = (target + sum(nums))/2 = s
    就变成了，nums种是否存在一些数字的和为 s, 是一个子集背包问题
    */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if ((total + target) % 2 == 1 || (total + target) < 0)
            return 0;
        int s = (total + target) / 2;
        int n = nums.size();
        // dp[i][sum] 从1开始到第i个，i也在可选范围内，能够凑出和为sum 的可能数
        // dp[0][sum] = 0
        // dp[i][0] = 1
        int dp[n + 1][s + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][s];
    }
};