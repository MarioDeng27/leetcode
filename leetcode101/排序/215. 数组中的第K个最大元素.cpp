class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
        int i = 0;
        while (i < k)
        {
            int val = pq.top();
            pq.pop();
            i++;
        }
        return pq.top();
    }
};

//利用快排的思想，将快速选择的数字的左边都大于该数，确定这个数字坐标时和K作比较，如果符合就是它，如果不符合缩小范围
class Solution
{
public:
    int partition(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return -1;
        int first = l, last = r, key = nums[first];
        while (first < last)
        {
            while (first < last && nums[last] <= key)
                last--;
            nums[first] = nums[last];
            while (first < last && nums[first] >= key)
                first++;
            nums[last] = nums[first];
        }
        nums[first] = key;
        return first;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int p = partition(nums, l, r);
            if (p + 1 == k)
                return nums[p];
            if (p + 1 < k)
            {
                l = p + 1;
            }
            else
            {
                r = p - 1;
            }
        }
        return nums[l];
    }
};