/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Binary-Search\第二阶段\875. 爱吃香蕉的珂珂.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-25 17:03:18
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-11-25 17:04:12
 */
/*
    max-min 最大值最小化问题。求在最小满足条件的情况下的最大值的简化版
    参考410这题这题就很简单了，注意left和right 的边界值，left的初始边界值为1

*/

class Solution
{
public:
    bool check(vector<int> &piles, int H, int x)
    {
        int cnt = 0;
        for (auto p : piles)
        {
            if (p % x != 0)
                cnt += p / x + 1;
            else
                cnt += p / x;
        }

        return cnt <= H;
    }

    /**
     * @brief: 
     * @param[in]:H：警卫离开时间，piles每堆香蕉的数量 
     * @param[out]: 最小的吃香蕉速度
     * @return {*}
     * @note: 
     */
    int minEatingSpeed(vector<int> &piles, int H)
    {
        if (piles.size() == 1)
        {
            if (piles[0] <= H)
            {
                return 1;
            }
            else
            {
                if (piles[0] % H != 0)
                    return piles[0] / H + 1;
                else
                    return piles[0] / H;
            }
        }
        int left = 1, right = 0;
        for (auto p : piles)
        {
            right = max(right, p);
        }
        int mid;
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (check(piles, H, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};