/*
 * @Description: https://leetcode-cn.com/problems/majority-element/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-09 22:27:01
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-09 22:39:31
 */
//投票算法
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 0;
        for (auto n : nums)
        {
            if (candidate == n)
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count < 0)
            {
                candidate = n;
                count = 1;
            }
        }
        return candidate;
    }
};
//分而治之
/*
    假设有一个数组nums,它的多数元素是a,则将它一分为二,那么必定有一部分的多数元素也为a,另一半不一定,可以用反证法证明.反过来,如果一个nums被分为两部分
    分别可以得两部分的多数元素为a和b那么,nums的众数必定在a和b中的一个,具体哪一个,还得判断a的个数是否大于两部分总数的一半,如果大于,则为a,反之.

    我们一步步将nums分割成只有一个元素的时候,也就是它的左边界等于右边界,那么其多数元素就是自身nums[low]

    然后慢慢的将两个数合起来,从刚刚分析的方法中判断出多数元素

    然后就是慢慢拼起来,只要注意,一个数组的多数元素,必定是两部分中各自多数元素的其中一个.


*/
class Solution
{
public:
    int count_num(vector<int> &nums, int low, int high, int target)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (nums[i] == target)
                count++;
        }
        return count;
    }

    int getmajority(vector<int> &nums, int low, int high)
    {
        if (low == high)
            return nums[low];
        int mid = low + (high - low) / 2;
        int left_major = getmajority(nums, low, mid);
        int right_major = getmajority(nums, mid + 1, high);
        if (count_num(nums, low, high, left_major) > (high - low + 1) / 2)
            return left_major;
        if (count_num(nums, low, high, right_major) > (high - low + 1) / 2)
            return right_major;
        return -1;
    }
    int majorityElement(vector<int> &nums)
    {
        return getmajority(nums, 0, nums.size() - 1);
    }
};