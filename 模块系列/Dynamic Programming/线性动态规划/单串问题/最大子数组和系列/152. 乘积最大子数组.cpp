/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-12 21:53:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-12 21:55:03
 */
// maxVal = 在等号左边的是表示当前元素包含在内的连续子数组的乘积最大值，它等于{num,num*maxVal,num*minVal}中的最大值，因为num的大小有正有负
//同理minVal = 在等号左边表示乘积最小值，可能后面的数字就是负数呢，那就发了。然后每次计算min和max只与前面一个状态的值有关，所以用递推方式更好，省空间
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int minVal = 1;
        int maxVal = 1;
        int res = nums[0];
        for (const auto num : nums)
        {
            int currMax = maxVal, currMin = minVal;
            maxVal = max(num, max(currMin * num, currMax * num));
            minVal = min(num, min(currMin * num, currMax * num));
            res = max(maxVal, res);
        }
        return res;
    }
};