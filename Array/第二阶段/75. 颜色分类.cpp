/*
    单指针实现

*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for (int i = ptr; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    }
};
/*
    双指针实现

*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int ptr0 = 0;
        int ptr1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[i], nums[ptr1]);
                ptr1++;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[ptr0]);
                if (ptr0 < ptr1)
                {
                    swap(nums[i], nums[ptr1]);
                }
                ptr0++;
                ptr1++;
            }
        }
    }
};
/*
    计数排序实现
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> m;
        for (auto num : nums)
        {
            ++m[num];
        }
        nums.clear();
        for (auto it : m)
        {
            for (int i = 0; i < it.second; i++)
            {
                nums.push_back(it.first);
            }
        }
    }
};
/*
    快速排序实现

*/
class Solution
{
public:
    int findindex(vector<int> &nums, int l, int r)
    {
        int pivot = nums[l];
        while (l < r) //知道l==r跳出循环
        {
            while (l < r && nums[r] >= pivot)
                r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int m = findindex(nums, l, r);
        quicksort(nums, l, m - 1);
        quicksort(nums, m + 1, r);
    }

    void sortColors(vector<int> &nums)
    {
        quicksort(nums, 0, nums.size() - 1);
    }
};