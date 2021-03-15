/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 20:29:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 20:29:30
 */
class Solution
{
public:
    int helper(vector<int> nums)
    {
        int n = nums.size();
        int choose = (n + 1) / 3;
        //目的就是在n个数字中，选出choose个，相当于（3N个数字中选出N个），让编号从1开始dp[6][2]相当于，前6个里选出2个块的和最大。dp[0][]表示从前面包括0个选出j个，肯定为0。dp[1]表示从i个里面选出j个
        vector<vector<int>> dp(n + 1, vector<int>(choose + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= choose; j++)
            {
                //前面表示选择了当前这个饼，也就是nums[i-1]，那么就要相当于从前i-2 选出 j-1的最优结果，i<2的话，相当于，从i = 1，也就是只能取第i个也就是nums[i-1]作为结果。后面一种情况相当于不选当前块，要从前面i-1个饼里选出j个组成最大的和。
                dp[i][j] = max((i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + nums[i - 1], dp[i - 1][j]);
            }
        }
        //返回从n块里，去choose 的最优解，限制条件还有不相邻
        return dp[n][choose];
    }
    int maxSizeSlices(vector<int> &slices)
    {
        if (slices.size() == 0)
            return 0;
        if (slices.size() == 1)
            return slices[0];
        int noEnd = helper(vector<int>(slices.begin(), slices.end() - 1));
        int noStart = helper(vector<int>(slices.begin() + 1, slices.end()));
        return max(noEnd, noStart);
    }
};