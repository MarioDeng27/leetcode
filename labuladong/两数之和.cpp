/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-19 21:12:22
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-19 21:12:22
 */
class Solution
{
public:
    vector<vector<int>> twoSumTarget(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        vector<vector<int>> res;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            int left = nums[low];
            int right = nums[high];
            if (sum < target)
            {
                //去除nums从low位置开始与left一样的值
                while (low < high && nums[low] == left)
                    low++;
            }
            else if (sum > target)
            {
                //去除nums从high位置开始与right一样的值
                while (low < high && nums[high] == right)
                    high--;
            }
            else if (sum == target)
            {
                res.push_back({left, right});
                while (low < high && nums[low] == left)
                    low++;
                while (low < high && nums[high] == right)
                    high--;
            }
        }
        return res;
    }
};