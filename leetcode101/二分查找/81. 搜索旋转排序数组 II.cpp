/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-05 20:25:52
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 20:29:09
 */
//注意nums[l] == nums[mid] 且 nums[r] == nums[mid]这种特殊情况，这种情况下，无法确定不符合的区间，只能逐个确认，相当于On，真坑
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid] && nums[r] == nums[mid])
            {
                l++;
                r--;
            }
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] < target && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};