/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 20:56:41
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 20:57:02
 */
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && (nums[left] & 1) == 1)
                left++;
            while (left < right && (nums[right] & 1) == 0)
                right--;
            if (left < right)
            {
                int t = nums[left];
                nums[left] = nums[right];
                nums[right] = t;
            }
        }
        return nums;
    }
};