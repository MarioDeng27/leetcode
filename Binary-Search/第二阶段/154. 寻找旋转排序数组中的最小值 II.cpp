/*
	153的变型:
    注意:出现相同大小的元素记得缩小范围.这一招得掌握
	只要出现nums[left] < nums[right] 或者 mid + 1 < n && nums[mid] > nums[mid + 1] 或者 mid > 0 && nums[mid - 1] > nums[mid]
	都能找到最小值
	上述条件不满足的情况下而如果一旦出现nums[left] == nums[mid]的情况说明,则left自加1,表示缩小搜查范围
	然后再去判断 最小值可能出现在mid左侧还是右侧,经过上述判断mid是不可能作为最小值了
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int left = 0, right = n - 1, mid;

        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                return nums[left];
            }
            mid = left + ((right - left) >> 1);
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (mid > 0 && nums[mid - 1] > nums[mid])
                return nums[mid];

            if (nums[left] == nums[mid])
            {
                left++;
                continue;
            }
            if (nums[left] < nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[right];
    }
};