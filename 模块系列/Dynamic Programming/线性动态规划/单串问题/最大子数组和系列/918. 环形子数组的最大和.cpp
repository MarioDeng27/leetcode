/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-12 21:22:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-12 21:26:22
 */
//通过使用两次Kadane
/*
    最终结果，只有两种情况
    1. 最大max在原数组中
    2. 最大max在环形数组中，即包含了num[0]和num[size()-1]，那么我们只要找到在(0,size()-1)不含这两端的连续最小和子序列，然后让总sum-subSum就能得到这种情况的最大max
*/
class Solution
{
public:
    int maxSubSumCore(vector<int> nums)
    {
        int subSum = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            subSum = max(nums[i], subSum + nums[i]);
            res = max(res, subSum);
        }
        return res;
    }
    int minSubSumCore(vector<int> nums)
    {
        int subSum = 0;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            subSum = min(nums[i], subSum + nums[i]);
            res = min(res, subSum);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int> &A)
    {
        if (A.size() == 1)
            return A[0];
        int res1 = maxSubSumCore(A);
        int minSubSum = minSubSumCore(vector<int>(A.begin() + 1, A.end() - 1));
        int totalSum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            totalSum += A[i];
        }
        int res2 = totalSum - minSubSum;
        return max(res1, res2);
    }
};
