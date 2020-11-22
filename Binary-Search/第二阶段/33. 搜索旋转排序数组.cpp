/*
    1. 通过low 和 high，计算出mid，如果nums[mid] == target则返回mid
    2. 以mid为分割点，判断[low, mid]和[mid+1,high]哪个是有序数组，通过 数组的边界点来判断，如果右边界的值大于或等于左边界的值则就是有序数组
        进入有序数组后，判断target是否在这个有序数组中，判断条件为 数组左右两边界的值一小一大：
        2.1如果在[low, mid]有序的话，target是否在有序数组中就判断nums[low]<=target<nums[mid],因为考虑到mid-1会小于0所以不采用nums[low]<=target<=nums[mid-1]
                 如果在的话，high = mid -1
                 如果不在的话，就在另一个数组中，low = mid+1
        2.2如果在[mid+1,high]有序的话，target是否在有序数组中就判断nums[mid]<target<=nums[high],因为考虑到mid+1会大于n-1所以不采用nums[mid+1]<=target<=nums[high]
                如果在的话，low = mid + 1
                如果不在的话，就在另一个数组中，high = mid -1
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && nums[mid] > target)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] < target && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};