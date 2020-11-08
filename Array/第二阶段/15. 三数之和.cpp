/*
    排序 + 双指针
    本题的难点在于如何去除重复解。

    算法流程：
    特判，对于数组长度 n，如果数组为 null 或者数组长度小于 3，返回 [][。
    对数组进行排序。
    遍历排序后数组：
    若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
    对于重复元素：跳过，避免出现重复解
    令左指针 L=i+1，右指针 R=n-1，当 L<R时，执行循环：
    当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
    若和大于 0，说明 nums[R]nums[R] 太大，R 左移
    若和小于 0，说明 nums[L]nums[L] 太小，L 右移
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int L = i + 1;
            int R = n - 1;
            while (L < R)
            {
                if (nums[i] + nums[L] + nums[R] > 0)
                    R--;
                else if (nums[i] + nums[L] + nums[R] < 0)
                    L++;
                else //()==0
                {
                    res.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                        L++;
                    while (L < R && nums[R] == nums[R - 1])
                        R--;
                    L++;
                    R--;
                }
            }
        }
        return res;
    }
};