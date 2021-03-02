/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 16:29:08
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 16:54:14
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int res = nums[0];
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};

class Solution
{
public:
    struct Range
    {
        int lSum = 0;
        int rSum = 0;
        int iSum = 0;
        int mSum = 0;
    };

    Range combine(Range lRange, Range rRange)
    {
        int lSum = max(lRange.lSum, lRange.iSum + rRange.lSum);
        int rSum = max(rRange.rSum, rRange.iSum + lRange.rSum);
        int iSum = lRange.iSum + rRange.iSum;
        int mSum = max(max(lRange.mSum, rRange.mSum), lRange.rSum + rRange.lSum);
        return {lSum, rSum, iSum, mSum};
    }
    Range getRange(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return {nums[l], nums[l], nums[l], nums[l]};
        int m = (l + r) / 2;
        Range lRange = getRange(nums, l, m);
        Range rRange = getRange(nums, m + 1, r);
        return combine(lRange, rRange);
    }
    int maxSubArray(vector<int> &nums)
    {
        return getRange(nums, 0, nums.size() - 1).mSum;
    }
};