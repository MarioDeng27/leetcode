/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 19:40:00
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-01 19:40:20
 */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[left])
            {
                if (nums[left] <= target && nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < nums[right])
            {
                if (nums[mid] < target && nums[right] >= target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};