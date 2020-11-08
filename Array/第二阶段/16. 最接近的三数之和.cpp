/*
    自己的想法
    排序+双指针

    算法流程：
    特判，对于数组长度 n，如果数组为 null 或者数组长度小于 3，返回 []。
    对数组进行排序。
    遍历排序后数组：
    定义了变量d表示遍历到目前最接近的和res 与 target的距离，遍历维护了这两个值

    若 d=0，则表示数组中存在与target相等的和，直接返回当前维护的res就是target。
    对于最左边的元素，若重复元素：跳过，避免出现重复解

    对于中间元素，令左指针 L=i+1，右指针 R=n-1，当 L<R时，执行循环：
    当 nums[i]+nums[L]+nums[R]==target，表示找到最佳的答案，即res=target
    若和大于 0，说明 nums[R]太大，首先去除最右边元素的重复元素， 一直到 相邻元素不重复为止之前R--，最后R左移一步
    若和小于 0，说明 nums[L]太小，同理上一种情况。
*/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int d = INT_MAX;
        int n = nums.size();
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (d == 0)
                break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int L = i + 1;
            int R = n - 1;
            while (L < R)
            {
                int sum = (nums[i] + nums[L] + nums[R]);
                if (target == sum)
                {
                    res = target;
                    d = 0;
                    break;
                }
                else if (target < sum)
                {

                    while (L < R && nums[R] == nums[R - 1])
                        R--;
                    R--;
                }
                else
                {
                    while (L < R && nums[L] == nums[L + 1])
                        L++;
                    L++;
                }
                if (abs(target - sum) < d)
                {
                    res = sum;
                    d = abs(target - sum);
                }
            }
        }
        return res;
    }
};