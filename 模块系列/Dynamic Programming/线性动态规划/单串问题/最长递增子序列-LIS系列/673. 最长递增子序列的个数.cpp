/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-12 14:36:07
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-12 14:40:54
 */
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        //数组里放pair类型，dp[i]表示以i结尾并包含第i个元素的结果是第一个关键词代表长度，第二个关键词代表该长度对应有的个数，当然长度可能会相同
        //第二个int就是记录最长的长度有的个数
        vector<pair<int, int>> dp(nums.size(), {1, 1});
        for (int i = 1; i < nums.size(); i++)
        {
            int maxLen = 0;
            int res = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (maxLen < dp[j].first)
                    {
                        maxLen = dp[j].first;
                        //当前长度已更新，长度初始化为对应长度已有的个数
                        res = dp[j].second;
                    }

                    else if (maxLen == dp[j].first)
                    {
                        //当前j状态长度与maxLen相等，加上对应的个数。
                        res += dp[j].second;
                    }
                }
            }
            dp[i] = {maxLen + 1, res};
        }
        //通过对dp进行排序找到以第一个int为关键词从大到小排序，本来找到最长的就行了，现在要返回最长长度的个数，所以得把最大长度有的个数全都加起来
        sort(dp.begin(), dp.end(), [](pair<int, int> p1, pair<int, int> p2) { return p1.first > p2.first; });
        int res = dp[0].second;
        for (int i = 0; i < dp.size() - 1; i++)
        {
            if (dp[i].first > dp[i + 1].first)
                break;
            else
                res += dp[i + 1].second;
        }
        return res;
    }
};