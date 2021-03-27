/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-27 14:08:04
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-27 14:08:07
 */
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<pair<int, int>> vec;
        int index = 0;
        for (auto num : nums)
            vec.push_back({num, index++});
        sort(vec.begin(), vec.end(), [&](pair<int, int> &p1, pair<int, int> &p2) { return p1.first > p2.first; });
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = vec[i].second;
            int num = vec[i].first;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (index < vec[j].second && num != vec[j].first)
                    res++;
            }
        }
        return res;
    }
};

/*
通过归并算法来解决，
比如[2,4,6] [3,7,9]
当左边的数组遍历到的数字比右边遍历到的数字更小，则记录右边到头部的距离d，表示右边有d个比左边遍历到的数字小的个数
注意判断条件要用<= 防止出现重复的个数

*/

class Solution
{
public:
    int res = 0;
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int i = left;
        int j = mid + 1;
        vector<int> tmp(right - left + 1);
        int index = 0;
        while (i <= mid && j <= right)
        {
            //tmp[index++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
            if (nums[i] <= nums[j])
                res += (j - mid - 1);
            tmp[index++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid)
        {
            res += (j - mid - 1);
            tmp[index++] = nums[i++];
        }
        while (j <= right)
            tmp[index++] = nums[j++];
        for (int i = 0; i < tmp.size(); i++)
        {
            nums[i + left] = tmp[i];
        }
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    int reversePairs(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
};