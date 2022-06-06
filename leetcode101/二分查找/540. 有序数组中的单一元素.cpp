class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0;
        int r = n - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            {
                return nums[mid];
            }
            else if (nums[mid - 1] == nums[mid] && (r - mid) % 2 == 1 || nums[mid + 1] == nums[mid] && (r - mid - 1) % 2 == 1)
            {
                if (nums[mid - 1] == nums[mid])
                    l = mid + 1;
                else
                    l = mid + 2;
            }
            else
            {
                if (nums[mid - 1] == nums[mid])
                    r = mid - 2;
                else
                    r = mid - 1;
            }
        }
        return nums[l];
    }
};

//---------------
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[(mid - 1 + n) % n] != nums[mid] && nums[(mid + 1) % n] != nums[mid])
            {
                return nums[mid];
            }
            else if (nums[(mid - 1 + n) % n] == nums[mid] && (r - mid) % 2 == 1 || nums[(mid + 1) % n] == nums[mid] && (r - mid - 1) % 2 == 1)
            {
                if (nums[(mid - 1 + n) % n] == nums[mid])
                    l = mid + 1;
                else
                    l = mid + 2;
            }
            else
            {
                if (nums[(mid - 1 + n) % n] == nums[mid])
                    r = mid - 2;
                else
                    r = mid - 1;
            }
        }
        return nums[mid];
    }
};