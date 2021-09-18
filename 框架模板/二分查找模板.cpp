/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-13 20:14:29
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-13 20:14:29
 */
//二分查找模板

//普通二分查找，只要找到target就返回索引
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
        }
        return -1;
    }
};

//找到target，并且如果有多个target，返回最左边target的索引，通过这种方法稍加修改可以找到比target小的元素中较大的元素的索引
//可以通过此方法找到刚好大于等于target的值的索引
int left_bound(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] == target)
        {
            right = mid - 1;
        }
    }
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

//找到target，并且如果有多个target，返回最右边target的索引，通过这种方法可以找到比target大的元素中较小的元素的索引
//通过此方法可以找到刚好小于或者等于target的值的索引
int right_bound(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] == target)
        {
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}