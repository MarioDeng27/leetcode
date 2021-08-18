/*
    具体解决办法还是分有序还是无序数组去分析，参考第33题目，只是判断有序还是无序的方法有了不一样的情况
    判断条件：判断[[low,mid]是否有序就一定要判断出是否  nums[low] < nums[mid]
    那么当出现 nums[low] == nums[mid] 这个就很难判断出是否有序，10111 和 11101 这样的很难判断前面有序还是后面有序，因为nums[mid] == nums[low] == nums[high]
    好的办法就是判处nums[low]这个重复的干扰项，就是 low++之后continue，相当于从[low+1,high]这个区间范围去判断是否存在target，因为一开始已经判断了，nums[mid]肯定不等于target所以nums[low]一定不等于target
*/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return false;
        if (n == 1)
            return nums[0] == target ? true : false;
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid])
            {
                low++;
                continue;
            }

            if (nums[low] < nums[mid])
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
        return false;
    }
};