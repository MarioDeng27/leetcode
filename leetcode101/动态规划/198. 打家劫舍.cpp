class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = (i >= 2 ? max(dp[i - 1][1], dp[i - 2][1]) : dp[i - 1][1]);
            dp[i][1] = (i >= 2 ? max(dp[i - 1][0], dp[i - 2][1]) : dp[i - 1][0]) + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};