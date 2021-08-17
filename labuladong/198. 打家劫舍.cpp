/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-17 19:58:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-17 21:53:57
 */

//不带备忘录的递归实现（自顶向下）
class Solution
{
public:
    //dp的作用是，从start开始偷走最大的钱
    int dp(vector<int> &nums, int start)
    {
        if (start >= nums.size())
            return 0;
        int done = nums[start] + dp(nums, start + 2);
        int notdone = dp(nums, start + 1);
        return max(done, notdone);
    }
    int rob(vector<int> &nums)
    {
        return dp(nums, 0);
    }
};

//带备忘录的递归实现（自顶向下）
class Solution
{
public:
    unordered_map<int, int> mem;
    //dp的作用是，从start开始偷走最大的钱
    int dp(vector<int> &nums, int start)
    {
        if (start >= nums.size())
            return 0;
        if (mem.count(start) > 0)
            return mem[start];
        int done = nums[start] + dp(nums, start + 2);
        int notdone = dp(nums, start + 1);
        int res = max(done, notdone);
        mem[start] = res;
        return res;
    }
    int rob(vector<int> &nums)
    {
        return dp(nums, 0);
    }
};

//dp, 空间O(N)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int done = dp[i + 2] + nums[i];
            int notdone = dp[i + 1];
            dp[i] = max(done, notdone);
        }

        return dp[0];
    }
};
//dp, 空间O(1)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 0;
        int dp_i2 = 0;
        int dp_i1 = 0;
        int dp_i = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            //int done = dp[i + 2] + nums[i];
            int done = dp_i2 + nums[i];
            //int notdone = dp[i + 1];
            int notdone = dp_i1;
            dp_i = max(done, notdone);
            dp_i2 = dp_i1;
            dp_i1 = dp_i;
        }
        return dp_i;
    }
};