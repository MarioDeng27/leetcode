/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-12 21:30:00
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-12 21:30:21
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int subSum = 0;
        int res = INT_MIN;
        for (const auto num : nums)
        {
            subSum = max(num, num + subSum);
            res = max(res, subSum);
        }
        return res;
    }
};