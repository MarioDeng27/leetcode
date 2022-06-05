class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int l = 0;
        int r = n - 1;
        int mid = 0;
        vector<int> res = {-1, -1};
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (r >= 0 && nums[r] == target)
            res[1] = r;
        else
            return res;
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (l < n && nums[l] == target)
            res[0] = l;
        return res;
    }
};