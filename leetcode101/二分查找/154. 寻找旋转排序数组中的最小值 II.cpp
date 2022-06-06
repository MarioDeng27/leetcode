class Solution
{
public:
    int findMin(vector<int> nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[(mid - 1 + n) % n] > nums[mid])
            {
                return nums[mid];
            }
            if (nums[mid] > nums[(mid + 1) % n])
            {
                return nums[(mid + 1) % n];
            }
            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
            }
            if ((nums[l] >= nums[mid] && nums[mid] <= nums[r]) || (nums[l] < nums[r]))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return nums[mid];
    }
};