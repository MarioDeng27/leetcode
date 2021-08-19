/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-19 21:17:59
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-19 21:17:59
 */
class Solution
{
public:
    vector<vector<int>> twoSumTarget(vector<int> &nums, int target)
    {
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

    vector<vector<int>> threeSumTarget(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto tuples = twoSumTarget(nums, target - num);
            for (auto tuple : tuples)
            {
                tuple.push_back(num);
                res.push_back(tuple);
            }
            while (i < n - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};